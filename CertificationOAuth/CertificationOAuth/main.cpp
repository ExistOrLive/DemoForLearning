//
//  main.cpp
//  CertificationOAuth
//
//  Created by 朱猛 on 2020/11/7.
//

#include <iostream>
#include <string>
#include "OpenXLSX.hpp"
#include "httplib.h"


using namespace std;
using namespace OpenXLSX;

int main(int argc, const char * argv[]) {
   
    cout << "检测程序开始: \n\n";
    
    string sourceFilePath = "/Users/zhumeng/Downloads/淘宝200.xlsx";
    
    XLDocument sourceDoc;
    XLDocument objDoc;
    
    try {
        sourceDoc.open(sourceFilePath);
    } catch (runtime_error error) {
        cout << "源excel 文件不存在" << endl;
        return 0;
    }
        
    auto wks = sourceDoc.workbook().worksheet("Sheet1");
    auto rowCount = wks.rowCount();
    
    cout << "检测数据共有" << rowCount << "条，请等待......\n\n" << endl;
    
    httplib::Client cli("http://zscx.osta.org.cn");
    cli.set_connection_timeout(0,300000);
    
    for (int i = 1 ;  i  <= rowCount ; ++i){
        string cardId = wks.cell(i, 1).value().asString();
        string name = wks.cell(i, 2).value().asString();
        
        cout << cardId;
        cout << "   ";
        cout << name;
        cout << "   ";
        
        httplib::Headers headers = {
            { "Referer","http://zscx.osta.org.cn/"},{"Origin","http://zscx.osta.org.cn"},{"Accept","*/*"}
        };
        
        httplib::Params params = {
            {"tableName","CERT_T"},{"tableName1","000000"},{"CertificateID",""},
            {"CID",cardId},{"Name",name},{"x","137"},{"y","24"},{"province","-1"}
        };
        httplib::Result result = cli.Post("/jiandingApp/command/buzhongxin/ecCertSearchAll",headers,params);
        
        
        if(result) {
            string &body = result.value().body;
            if(body.find(cardId) != string::npos) {
                cout << "有证书" << endl;
            } else if (body.find("对不起，没有查到相关信息") != string::npos) {
                cout << "没有证书" << endl;
            } else {
                cout << "查询失败" << endl;
            }
        } else {
            cout << "查询失败" << endl;
        }
        
        
    }
    
    cout << "\n\n检测数据完毕" << endl;
    

    return 0;
}
