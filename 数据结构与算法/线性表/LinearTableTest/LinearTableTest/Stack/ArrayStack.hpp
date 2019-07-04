//
//  ArrayStack.hpp
//  StackTest
//
//  Created by 朱猛 on 2019/6/27.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include <stdio.h>
#include "StackHeader.h"

/**
 *   连续存储的栈
 *   T * list                   指向连续存储空间的首地址
 *   int topIndex               顶部指针
 **/

namespace zm
{
    static const int ArrayStackIncrementNumber = 16;
    
    static const int ArrayStackInitNumber = 16;
    
    template <typename T>
 
    class ArrayStack : AbstractStack<T>
    {
    private:
        T * list;
        
        int topIndex;
        
        int stackSize;
        
        int stackCapacity;
        
        void enlargeStack()
        {
            T * newList = new T[stackCapacity + ArrayStackIncrementNumber];
            
            if(!newList)
            {
                 throw __cpp_exceptions;
            }
            
            for(int i = 0; i < stackSize; i++)
            {
                newList[i] = list[i];
            }
            
            stackCapacity += ArrayStackIncrementNumber;
            delete[] list;
            list = newList;
        }
        
    public:
        
        ArrayStack(): AbstractStack<T>()
        {
            list = new T[ArrayStackInitNumber];
            
            if(!list)
            {
                throw __cpp_exceptions;
            }
            
            topIndex = 0;
            
            stackSize = 0;
            
            stackCapacity = ArrayStackInitNumber;
        }
        
        ~ ArrayStack()
        {
            delete [] list;
            topIndex = 0;
            stackSize = 0;
            stackCapacity = 0;
        }
        
        void clearStack()
        {
            topIndex = 0;
            stackSize = 0;
        }
        
        //
        virtual bool isEmpty()
        {
            return stackSize == 0;
        }
        
        //
        int length()
        {
            return stackSize;
        }
        
        virtual bool getTop(T & topElem)
        {
            if(stackSize == 0)
            {
                return false;
            }
            
            topElem = list[topIndex - 1];
            
            return true;
        }
        
        bool push(T elem)
        {
            if(stackSize >= stackCapacity)
            {
                enlargeStack();
            }
            list[topIndex] = elem;
            topIndex ++;
            stackSize ++;
            
            return true;
        }
        
        bool pop(T & elem)
        {
            if(stackSize == 0)
            {
                return false;
            }
            
            elem = list[-- topIndex];
            stackSize --;
            return true;
        }
        
        void stackTraverse(void(*visit)(T elem))
        {
            for(int i = topIndex - 1; i >= 0 ; i--)
            {
                visit(list[i]);
            }
        }
        
        
        
    };
}



#endif /* ArrayStack_hpp */
