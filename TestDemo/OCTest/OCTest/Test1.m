//
//  Test1.m
//  OCTest
//
//  Created by 朱猛 on 2020/10/30.
//

#import "Test1.h"

@implementation Test1

- (instancetype) init {
    if(self = [super init]){
        [self test];
    }
    return self;
}

- (void) test{
    NSLog(@"%@",self.a);
}

@end


@implementation Test1(ahah)

- (void) test{
    NSLog(@"Hello World");
}

@end
