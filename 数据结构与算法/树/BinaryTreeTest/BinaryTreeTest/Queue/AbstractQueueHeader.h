//
//  AbstractQueueHeader.h
//  QueueTest
//
//  Created by 朱猛 on 2019/7/4.
//  Copyright © 2019 朱猛. All rights reserved.
//

#ifndef AbstractQueueHeader_h
#define AbstractQueueHeader_h

namespace zm {
    
    template <typename T>
    
    class AbstractQueue
    {
    public:
        
        AbstractQueue()
        {
            //printf("abstractQueue alloc");
        }
        
        ~ AbstractQueue()
        {
           // printf("abstractQueue dealloc");
        }
        
        virtual void clearQueue()     = 0;
        
        virtual bool isQueueEmpty()   = 0;
        
        virtual int queueLength()     = 0;
        
        virtual bool getHead(T&)           = 0;
        
        virtual bool enQueue(T)       = 0;
        
        virtual bool deQueue(T&)           = 0;
    };
}


#endif /* AbstractQueueHeader_h */
