//
//  SimpleDB.cpp
//  SimpleFileDB
//
//  Created by  on 2020/10/29.
//

#include "SimpleDB.h"
#include <sys/stat.h>
#include <unistd.h>
#include <exception>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "btree.h"

std::ostream &operator<<(std::ostream &os,const Record &record){
    // 按字节逐个输出到文本
    const char *charArray = reinterpret_cast<const char *>(record.columns);
    for(size_t i = 0; i < sizeof(record.columns); ++i){
        os << charArray[i];
    }
    return os;
}


std::istream &operator>>(std::istream &is,Record &record){
    // 按字节逐个从文本读取
    char *charArray = reinterpret_cast<char *>(record.columns);
    for(size_t i = 0; i < sizeof(record.columns); ++i){
        // 这里不可以使用 >> , 无法读取\t,\n等字符
        is.get(charArray[i]);
    }
    
    return is;
}



SimpleDB::SimpleDB(const std::string &path):dbDir(path){
    // 启动DB
    
    // 1. 检查目录是否存在
    int dirExist = access(path.c_str(), 0);
    if(0 != dirExist){
        // 数据库目录不存在
        throw std::runtime_error("数据库目录不存在");
    }
    
    // 2. 读取数据库文件
    std::string dbPath = path + "/SimpleDB.db";
    struct stat statInfo;
    int fileExist = stat(dbPath.c_str(), &statInfo);
    if(0 != fileExist){
        // 数据库文件不存在
        this->recordNum = 0;
    } else {
        // 一行记录800byte
        this->recordNum = statInfo.st_size / sizeof(Record::columns);
    }
     
    // 创建输入输出流
    this->os.open(dbPath.c_str(),std::ostream::app | std::ostream::binary);
    if(!this->os.is_open()){
        
    }
    this->is.open(dbPath.c_str(),std::istream::binary);
    if(!this->is.is_open()){
        
    }
    
    // 3. 检查读取索引文件
    for(size_t i = 0; i < 100; ++i){
        std::string indexPath = path + "/index_" + std::to_string(i);
        if(0 == access(indexPath.c_str(), 0)){
            std::ifstream indexis(indexPath,std::istream::binary);
            if(indexis.is_open()){
                int64_t tmp[2];
                char *tmpChar = (char *)tmp;
                size_t j = 0;
                while(indexis.get(tmpChar[j])){
                    j++;
                    j %= sizeof(tmp);
                    if(j == 0){
                        this->indexMaps[i].insert(std::make_pair(tmp[0], tmp[1]));
                    }
                }
            }
        }
    }
    
    std::cout << "SimpleDB初始化成功, 当前记录数 [" << this->recordNum << "]" << std::endl;
}


void SimpleDB::insert(const Record &record){
    this->os<<record;
    this->recordNum ++;
    
    // 插入对应记录索引
    for(auto begin = this->indexMaps.begin(); begin != this->indexMaps.end(); ++begin){
        int64_t columnNum = begin->first;
        begin->second.insert(std::make_pair(record.columns[columnNum], this->recordNum));
    }
    
}

std::vector<Record> SimpleDB::search(int64_t column,int64_t value,int64_t maxRecordNum){
   
    time_t startTime;
    time(&startTime);
    
    std::vector<Record> result;
    Record record;
    
    // 1. 如果对应column有索引
    if(this->indexMaps.find(column) != this->indexMaps.end()) {
        // 当前column存在索引
        auto resultRange = this->indexMaps[column].equal_range(value);
        for(auto it = resultRange.first; it != resultRange.second; ++it){
            int64_t recordNum = it->second;
            this->is.clear();
            this->is.seekg(sizeof(Record::columns) * (recordNum - 1), std::ios_base::beg);
            if(this->is>>record){
                result.push_back(record);
                if(result.size() >= maxRecordNum){
                    break;
                }
            }
        }
        
        time_t endTime;
        time(&endTime);
        std::cout << "search " << endTime - startTime <<" s" << std::endl;
        return result;
    }
    
    // 2. 没有索引则顺序查找
    this->is.clear();
    this->is.seekg(0, std::ios_base::beg);
   
    while(this->is>>record){
        if(record.columns[column] == value){
            result.push_back(record);
            if(result.size() >= maxRecordNum){
                break;
            }
        }
    }
    
    time_t endTime;
    time(&endTime);
    std::cout << "search " << endTime - startTime <<" s" << std::endl;
    return result;
}

std::vector<Record> SimpleDB::search(int64_t column,int64_t minValue,int64_t maxValue,int64_t maxRecordNum){
    
    if(minValue > maxValue){
        return std::vector<Record>();
    }
    
    time_t startTime;
    time(&startTime);

    std::vector<Record> result;
    Record record;
    
    // 1. 如果对应column有索引
    if(this->indexMaps.find(column) != this->indexMaps.end()) {
        // 当前column存在索引
        auto startIt = this->indexMaps[column].lower_bound(minValue);
        auto endIt = this->indexMaps[column].lower_bound(maxValue);
        for(auto it = startIt; it != endIt; ++it){
            int64_t recordNum = it->second;
            this->is.clear();
            this->is.seekg(sizeof(Record::columns) * (recordNum - 1), std::ios_base::beg);
            if(this->is>>record){
                result.push_back(record);
                if(result.size() >= maxRecordNum){
                    break;
                }
            }
        }
        time_t endTime;
        time(&endTime);
        std::cout << "search " << endTime - startTime <<" s" << std::endl;
        return result;
    }
    
    // 2. 没有索引则顺序查找
    this->is.clear();
    this->is.seekg(0, std::ios_base::beg);
    while(this->is>>record){
        if(record.columns[column] >= minValue && record.columns[column] <= maxValue){
            result.push_back(record);
            if(result.size() >= maxRecordNum){
                break;
            }
        }
    }
    time_t endTime;
    time(&endTime);
    
    std::cout << "search " << endTime - startTime <<" s" << std::endl;
    
    return result;
}


bool SimpleDB::addIndexFor(int64_t columnNum){
    // 1. 如果已经存在索引直接返回
    auto it = this->indexMaps.find(columnNum);
    if(it != this->indexMaps.end()){
        std::cout << "column " << columnNum << " 的索引已经存在" << std::endl;
        return false;
    }
    
    this->indexMaps[columnNum];
    
    // 2. 遍历数据库，构建索引b树
    this->is.clear();
    this->is.seekg(0, std::ios_base::beg);
    Record record;

    int64_t recordNum = 0;
    while(this->is>>record){
        recordNum ++;
        this->indexMaps[columnNum].insert(std::make_pair(record.columns[columnNum], recordNum));
    }
    
    return true;
}

void SimpleDB::flush(){
    
    this->os.flush();
    
    for(auto begin = this->indexMaps.begin(); begin != this->indexMaps.end(); ++begin){
        int64_t columnNum = begin->first;
        std::string indexPath = this->dbDir + "/index_" + std::to_string(columnNum);
        std::ofstream indexos(indexPath,std::ostream::app);
        if(indexos.is_open()){
            for(auto it = begin->second.begin(); it != begin->second.end(); ++it){
                indexos.write((const char *)&(it->first), 8);
                indexos.write((const char *)&(it->second), 8);
            }
            indexos.flush();
            indexos.close();
        }
    }
}



SimpleDB::~SimpleDB(){
    flush();
}
