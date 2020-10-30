//
//  main.cpp
//  SimpleFileDB
//
//  Created by  on 2020/10/29.
//

#include <iostream>
#include "SimpleDB.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    SimpleDB db("/Users/zhumeng/Downloads");
    
//    db.addIndexFor(0);
//    db.addIndexFor(1);
//
//    for(int i = 0; i < 1000000; i++){
//        Record record(rand() % 1000000);
//        db.insert(record);
//    }

    vector<Record> result1 = db.search(0, 0, 10);

    vector<Record> result2 = db.search(0, 0, 200000 ,50);

    return 0;
}
