//
//  main.m
//  PropertyTestDemo
//
//  Created by 朱猛 on 2019/5/7.
//  Copyright © 2019年 朱猛. All rights reserved.
//

/**
 *  在MRC环境下展示property的本质，即setter和getter的实现细节
 *
 *
 **/

#import <Foundation/Foundation.h>
#import "ZMPropertyTest.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        ZMPropertyTest * test = [[ZMPropertyTest alloc] init];
        
        @autoreleasepool {
            ZMPropertyTest * test1 = [[ZMPropertyTestItem alloc] init];
            
            //[test setValue1:test1];
            [test setValue2:test1];
            [test setValue3:test1];
            [test setValue4:test1];
            [test setValue5:test1];
        }
 
        
    }
    return 0;
}
