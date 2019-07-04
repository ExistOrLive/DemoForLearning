//
//  BlockTest.m
//  BlockTest
//
//  Created by 朱猛 on 2019/6/4.
//  Copyright © 2019年 朱猛. All rights reserved.
//

#import "BlockTest.h"

@implementation BlockTest

- (void) test
{
    int a = 1;
    
    __block int b = 2;
    
    NSMutableArray *  array = [[NSMutableArray alloc] init];
    
    NSLog(@"&a = %lx &b = %lx self = %lx array = %lx str = %lx",&a,&b,&self,&array,&str);
    
    
    void(^testBlock)() = ^{
        
        NSLog(@"&a = %lx &b = %lx self = %lx array = %lx str = %lx",&a,&b,&self,&array,&str);
        
        str = @"dsadas";
        
        b = 3;
        
    };
    
    testBlock();
    
    NSLog(@"%@",str);
    NSLog(@"%d",b);
    
}

@end
