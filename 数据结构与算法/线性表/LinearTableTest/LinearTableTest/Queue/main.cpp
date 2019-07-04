//
//  main.cpp
//  QueueTest
//
//  Created by 朱猛 on 2019/7/4.
//  Copyright © 2019 朱猛. All rights reserved.
//

#include <iostream>
#import "ArrayQueue.hpp"
#import "LinkedQueue.hpp"

using zm::ArrayQueue;
using zm::LinkedQueue;

int main(int argc, const char * argv[]) {
   
    
    LinkedQueue<int> queue;
    
    printf("%d %d \n",queue.isQueueEmpty(),queue.queueLength());
    
    for(int i = 0; i < 100; i++)
    {
        queue.enQueue(i);
    }
    
    printf("%d %d \n",queue.isQueueEmpty(),queue.queueLength());
    
    int a;
    while(queue.deQueue(a))
    {
        printf("a = %d \n",a);
    }
    
    printf("%d %d \n",queue.isQueueEmpty(),queue.queueLength());
    
    return 0;
}
