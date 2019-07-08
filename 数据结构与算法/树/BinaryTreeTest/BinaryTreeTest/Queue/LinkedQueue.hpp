//
//  LinkedQueue.hpp
//  QueueTest
//
//  Created by 朱猛 on 2019/7/4.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef LinkedQueue_hpp
#define LinkedQueue_hpp

#include <stdio.h>
#include "AbstractQueueHeader.h"

namespace zm{
    
    template <typename T>
    class LinkedQueueNode
    {
    public:
        T value;
        LinkedQueueNode * next;
    };
    
    template <typename T>
    class LinkedQueue: AbstractQueue<T>
    {
        private :
        
        LinkedQueueNode<T> * front;                  // 队头指针
        LinkedQueueNode<T> * rear;                   // 队尾下标
        int size;                                    // 队列长度

        
    public:
        
        LinkedQueue():AbstractQueue<T>()
        {
            this->front = new LinkedQueueNode<T>;     // 定义头节点
            if(this->front == NULL)
            {
                throw __cpp_exceptions;
            }
            this->front->next = NULL;
            this->rear = this->front;
            this->size = 0;
        }
        
        ~ LinkedQueue()
        {
            LinkedQueueNode<T> * tmpNode = this->front;
            while(tmpNode)
            {
                LinkedQueueNode<T> * deleteNode = tmpNode;
                tmpNode = tmpNode->next;
                delete deleteNode;
            }
            this->front = NULL;
            this->rear = NULL;
            this->size = 0;
        }
        
        void clearQueue()
        {
            LinkedQueueNode<T> * tmpNode = this->front->next;
            this->front->next = NULL;
            while(tmpNode)
            {
                LinkedQueueNode<T> * deleteNode = tmpNode;
                tmpNode = tmpNode->next;
                delete deleteNode;
            }
            this->rear = this->front;
            this->size = 0;
        }
        
        bool isQueueEmpty()
        {
            return this->size == 0;
        }
        
        int queueLength()
        {
            return this->size;
        }
        
        
        bool getHead(T& elem)
        {
            if(this->size == 0 && this->front == this->rear)
            {
                return  false;
            }
            
            elem = this->front->next->value;
            
            return true;
        }
        
        bool enQueue(T elem)
        {
            LinkedQueueNode<T> * newNode = new LinkedQueueNode<T>;
            newNode->value = elem;
            newNode->next = NULL;
            
            this->rear->next = newNode;
            this->rear = newNode;
            this->size ++;
            
            return true;
        }
        
        bool deQueue(T& elem)
        {
            if(this->size == 0 && this->front == this->rear)
            {
                return false;
            }
            
            LinkedQueueNode<T> * deleteNode = this->front->next;
            
            elem = deleteNode->value;
            this->front->next = deleteNode->next;
            if(this->rear == deleteNode)
            {
                this->rear = this->front;
            }
            this->size --;
            
            delete deleteNode;
            deleteNode = NULL;
            
            return true;
        }
    };
}

#endif /* LinkedQueue_hpp */
