//
//  LinkedStack.hpp
//  StackTest
//
//  Created by 朱猛 on 2019/7/1.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef LinkedStack_hpp
#define LinkedStack_hpp

#include <stdio.h>
#include "StackHeader.h"

namespace zm {
    
    template <typename T>
    class StackNode
    {
    public:
        T  value;
        StackNode * next;
    };
    
    template <typename T>
    class LinkedStack : AbstractStack<T>
    {
    private:
        StackNode<T> * list;
        int stackSize;
        
    public:
        LinkedStack<T>():AbstractStack<T>()
        {
            StackNode<T> * headNode = new StackNode<T>;
            headNode->next = NULL;
            this->list = headNode;
            this->stackSize = 0;
        }
        
        ~ LinkedStack()
        {
            this->stackSize = 0;
            StackNode<T> * tmpNode = this->list;
            while(tmpNode)
            {
                StackNode<T> * deleteNode = tmpNode;
                tmpNode = tmpNode->next;
                delete deleteNode;
                deleteNode = NULL;
            }
        }
        
        void clearStack()
        {
            
            StackNode<T> * tmpNode = this->list->next;
            while(tmpNode)
            {
                StackNode<T> * deleteNode = tmpNode;
                tmpNode = tmpNode->next;
                delete deleteNode;
                deleteNode = NULL;
            }
            this->list->next = NULL;
            this->stackSize = 0;
        }
        
        //
        virtual bool isEmpty()
        {
            return this->stackSize == 0;
        }
        
        //
        int length()
        {
            return this->stackSize;
        }
        
        virtual bool getTop(T & topElem)
        {
            if(stackSize == 0)
            {
                return false;
            }
            
            topElem = this->list->next->value;
            
            return true;
        }
        
        bool push(T elem)
        {
            StackNode<T> * newNode = new StackNode<T>;
            newNode->value = elem;
            newNode->next = this->list->next;
            this->list->next = newNode;
            this->stackSize ++;
            return true;
        }
        
        bool pop(T & elem)
        {
            if(stackSize == 0)
            {
                return false;
            }
            
            StackNode<T> * node = this->list->next;
            this->list->next = node->next;
            elem = node->value;
            delete node;
            node = NULL;
            this->stackSize --;
            return true;
        }
        
        void stackTraverse(void(*visit)(T elem))
        {
            StackNode<T> * node = this->list->next;
            
            while(node)
            {
                visit(node->value);
                node = node->next;
            }
        }
        
        
    };
}

#endif /* LinkedStack_hpp */
