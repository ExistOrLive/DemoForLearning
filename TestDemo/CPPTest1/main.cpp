//
//  main.cpp
//  CPPTest
//
//  Created by 朱猛 on 2020/11/9.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A{
private:
    
public:
    virtual void test1(){
        std::cout << "this is A test1";
    }    
};


class B :  public A{
private:
    
public:
    int result = 11;

    void test1() override final{
        this->A::test1();
        std::cout << "this is B";
    }
};


class C : public B{
private:
    
public:

    void test1(){
        this->A::test1();
        std::cout << "this is B";
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    B b;

    b.test1();

    return 0;
}
