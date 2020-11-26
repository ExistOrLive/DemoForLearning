//
//  main.cpp
//  CPPTest
//
//  Created by 朱猛 on 2020/11/9.
//

#include <iostream>
#include "Test.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int a = 1;
    
    auto function = [a]() mutable -> void {
        a++;
        cout << a << endl;
    };
    
    auto func1 = function;
    
    function();
    function();
    func1();
    cout << a << endl;

    return 0;
}
