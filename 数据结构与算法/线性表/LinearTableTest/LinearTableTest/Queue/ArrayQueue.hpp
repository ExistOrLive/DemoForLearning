//
//  ArrayQueue.hpp
//  QueueTest
//
//  Created by 朱猛 on 2019/7/4.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include <stdio.h>
#include "AbstractQueueHeader.h"

namespace zm {
    
   
    
    static const unsigned int ArrayQueueInitCapacity = 25;
    
     template <typename T>
    class ArrayQueue : AbstractQueue<T>
    {
    private :
        
        T * list;
        int front;                  // 队头下标
        int rear;                   // 队尾下标
        int size;                   // 队列长度
        int capacity;               // 队列容量
        
    public:
        
        ArrayQueue():AbstractQueue<T>()
        {
            this->list = new T[ArrayQueueInitCapacity];
            if(!list)
            {
                throw __cpp_exceptions;
            }
            this->front = 0;
            this->rear = 0;
            this->size = 0;
            this->capacity = ArrayQueueInitCapacity;
        }
        
        ~ ArrayQueue()
        {
            delete[] this->list;
            this->list = NULL;
            this->front = 0;
            this->rear = 0;
            this->size = 0;
            this->capacity = 0;
        }
        
        void clearQueue()
        {
            this->front = 0;
            this->rear = 0;
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
            
            elem = this->list[this->front];
            
            return true;
        }
        
        bool enQueue(T elem)
        {
            if(this->size == this->capacity && this->front == this->rear)
            {
                return false;
            }
            
            this->list[this->rear] = elem;
            this->rear = (this->rear + 1) % this->capacity;
            this->size ++;
            
            return true;
        }
        
        bool deQueue(T& elem)
        {
            if(this->size == 0 && this->front == this->rear)
            {
                return false;
            }
            
            elem = this->list[this->front];
            this->front = (this->front + 1) % this->capacity;
            this->size -- ;
            
            return true;
        }
  
        
        
    };
}

#endif /* ArrayQueue_hpp */
