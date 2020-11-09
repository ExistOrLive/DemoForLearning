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
        Test2 *test = [Test2 new];
        test.a = @"hahah";
        test.b = 12;
        
        Test1 *ts = test;
        ts.a = @"dadas";
        ts.b = 133;
        
        NSLog(@"%@",test);
    }
    return 0;
}
