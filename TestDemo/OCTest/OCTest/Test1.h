//
//  Test1.h
//  OCTest
//
//  Created by 朱猛 on 2020/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Test1 : NSObject

@property(nonatomic, strong) NSString *a;
@property(nonatomic, assign) int b;

- (void) test;

@end

@interface Test2 : Test1

@property(nonatomic, strong) NSString *a;
@property(nonatomic, assign) int b;

@end


NS_ASSUME_NONNULL_END
