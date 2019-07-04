//
//  main.m
//  BlockTest
//
//  Created by 朱猛 on 2019/6/4.
//  Copyright © 2019年 朱猛. All rights reserved.
//

#import <Foundation/Foundation.h>

//static int d = 11;
//
//int main(int argc, const char * argv[]) {
//
//    NSMutableString * str = [@"dasdas" mutableCopy];
//
//    __block int c = 13;
//
//    int e = 14;
//
//    void(^block_test)(int,int) = ^(int a,int b){
//           NSLog(@"%d,%d,%d,%d,%d,%@",a,b,c,d,e,str);
//        };
//    block_test(1,2);
//    return 0;
//}

int main(int argc, const char * argv[])
{
    @autoreleasepool
    {
        NSLog(@"block1: %@",^{ NSLog(@"dasdas");});
        
        id block2 = ^{ NSLog(@"dasdas");};
        
        NSLog(@"block2: %@",block2);
        
        int b = 0;
        
        NSLog(@"block3: %@",^{ int a = b;});
        
        id block4 = ^{ int a = b;};
        
        NSLog(@"block4: %@",block4);
        
        __weak id block5 = ^{ int a = b;};
        
        NSLog(@"block5: %@",block5);
        
    }
    return 0;
}
