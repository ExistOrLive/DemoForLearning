//
//  main.cpp
//  CPPTest
//
//  Created by 朱猛 on 2020/11/9.
//

#include <iostream>
#include "Test.hpp"

using namespace std;

class SuperClass{
 
public:
    SuperClass(){
        test();
    }
    
    virtual ~SuperClass(){
        test();
    }

    virtual void test(){
        cout << "SuperClass";
    }
};

class SubClass : public SuperClass{
public:
    void test() override{
        SuperClass::test();
        cout << "SubClass";
    }
};


int main(int argc, const char * argv[]) {
    
    SuperClass *a = new SubClass();
    a->test();
    return 0;
}
