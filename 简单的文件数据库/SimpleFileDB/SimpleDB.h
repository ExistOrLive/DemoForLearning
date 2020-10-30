//
//  SimpleDB.hpp
//  SimpleFileDB
//
//  Created by  on 2020/10/29.
//

#ifndef SimpleDB_hpp
#define SimpleDB_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "btree.h"

class Record{

    friend std::ostream &operator<<(std::ostream &os,const Record &record);
    friend std::istream &operator>>(std::istream &is,Record &record);
    
public:
    int64_t columns[100];
    
    Record(){
        memset(this->columns, 0, sizeof(this->columns));
    }
    
    Record(int64_t id):Record(){
        columns[0] = id;
    }
};


class SimpleDB{
private:
    std::string dbDir;
    
    int64_t recordNum;
    std::ofstream os;
    std::ifstream is;
    
    // b树 保存索引
    std::map<int64_t,phmap::btree_multimap<int64_t,int64_t>> indexMaps;
public:
    
    /**
     * 启动DB
     * @param path DB的目录必须存在
     */
    SimpleDB(const std::string& path);
    
    /**
     *  插入记录
     */
    void insert(const Record &record);
    
    /**
     *  查询
     *  @param column 列号
     *  @param value 值
     *  @param maxRecordNum 限制结果条数
     */
    std::vector<Record> search(int64_t column,int64_t value,int64_t maxRecordNum);

    /**
     *  查询
     *  @param column 列号
     *  @param minValue 最小值(包括)
     *  @param maxValue 最大值(包括)
     *  @param maxRecordNum 限制结果条数
     */
    std::vector<Record> search(int64_t column,int64_t minValue,int64_t maxValue,int64_t maxRecordNum);
    
    
    /**
     *  添加索引
     *  @param columnNum 列号
     */
    bool addIndexFor(int64_t columnNum);
    
    void flush();
    
    ~SimpleDB();
};



#endif /* SimpleDB_hpp */
