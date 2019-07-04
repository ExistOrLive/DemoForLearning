//
//  main.cpp
//  StackTest
//
//  Created by 朱猛 on 2019/6/27.
//  Copyright © 2019 朱猛. All rights reserved.
//

#include <iostream>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"

void visit(int a)
{
    printf("a=%d\n",a);
}

using zm::ArrayStack;
using zm::LinkedStack;

int main(int argc, const char * argv[]) {
    
    LinkedStack<int> stack;
    
    for(int i = 0 ; i < 333 ; i ++)
    {
        stack.push(i);
//        if(i % 7 == 0)
//        {
//            stack.pop(i);
//        }
        
    }
    
    int length = stack.length();
    for(int i = 0; i < length ; i++)
    {
        int a;
        stack.pop(a);
        
        std::cout<< a << std::endl;
    }
    
}
