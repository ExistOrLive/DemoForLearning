//
//  Test.hpp
//  CPPTest
//
//  Created by 朱猛 on 2020/11/16.
//

#ifndef Test_hpp
#define Test_hpp

#include <iostream>

class Test{
public:
    virtual void test(int a = 1, int b = 2);
};

void Test::test(int a, int b){
    std::cout << a << " " << b << std::endl;
}


#endif /* Test_hpp */
