//
//  StackHeader.h
//  StackTest
//
//  Created by 朱猛 on 2019/6/27.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef StackHeader_h
#define StackHeader_h

namespace zm
{
    template <typename T>
    class AbstractStack
    {
    public:
        
        // 清空stack
        virtual void clearStack() = 0;
        
        // 
        virtual bool isEmpty() = 0;
        
        //
        virtual int length() = 0;
        
        virtual bool getTop(T & topElem) = 0;
        
        virtual bool push(T elem) = 0;
        
        virtual bool pop(T & elem) = 0;
        
        virtual void stackTraverse(void(*visit)(T elem)) = 0;
        
        
    };
}

#endif /* StackHeader_h */
