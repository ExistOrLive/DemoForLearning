//
//  main.m
//  OCTest
//
//  Created by 朱猛 on 2020/10/30.
//

#import <Foundation/Foundation.h>
#import "Test1.h"


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int a = 1;
        void(^function)(void);
        
        function = ^{
            ++a;
            NSLog(@"%d\n",a);
        };
        
        
        function();
        function();
        
    }
    return 0;
}
