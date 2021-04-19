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
        NSMutableArray *array = [NSMutableArray new];
        NSArray *array1 = @[@1,@2];
        
        NSLog(@"%@ %@",[array1 class],[array class]);
        NSLog(@"%d",[array isKindOfClass:[NSArray class]]);
        NSLog(@"%d",[array1 isKindOfClass:[NSArray class]]);
    }
    return 0;
}
