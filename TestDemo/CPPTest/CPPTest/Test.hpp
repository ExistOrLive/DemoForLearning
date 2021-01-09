//
//  Test.hpp
//  CPPTest
//
//  Created by 朱猛 on 2020/11/16.
//

#ifndef Test_hpp
#define Test_hpp

#include <iostream>
#include <vector>

using namespace std;

class Test{
public:
    int a;
    vector<int> b;
    virtual void test();
    
    Test():a(11){
        this->test();
    }
};

void Test::test(){
    cout << "Test" << a << " " << b.size();
}


class Test1 : public Test {
public:
    vector<int> c;
    void test() override;
    
    Test1():Test(){
        this->test();
    }
};

void Test1::test(){
    Test::test();
    cout << "Test1" << c.size() << endl;
}


#endif /* Test_hpp */
