//
//  main.cpp
//  CPPTest
//
//  Created by 朱猛 on 2020/11/9.
//

#include <iostream>

using namespace std;

class A{
private:
    
public:
    virtual void test1(){
        std::cout << "this is A test1";
    }
    
    void test2(){
        std::cout << "this is A test2";
    }
    
    static void test3(){
        std::cout << "this is A test3";
    }
    
    
    
};


class B : private  A{
private:
    
public:
    void test1()  {
        std::cout << "this is B";
    }
    
    void test2()  {
        A::test3();
        std::cout << "this is B";
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    B b;
    
    return 0;
}
