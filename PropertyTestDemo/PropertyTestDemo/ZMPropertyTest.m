//
//  ZMPropertyTest.m
//  PropertyTestDemo
//
//  Created by 朱猛 on 2019/5/7.
//  Copyright © 2019年 朱猛. All rights reserved.
//

#import "ZMPropertyTest.h"


@implementation ZMPropertyTestItem

- (id)copyWithZone:(nullable NSZone *)zone
{
    ZMPropertyTestItem * item = [[ZMPropertyTestItem allocWithZone:zone] init];
    
    return item;
}

@end


@interface ZMPropertyTest()
{
    ZMPropertyTestItem * _value5;
    
    __weak ZMPropertyTestItem * _value6;
    
    __unsafe_unretained ZMPropertyTestItem * _value7;
    
}

@end
@implementation ZMPropertyTest

/**
 *
 * MRC
 **/

///**
// *
// * strong 先保留新值，再释放旧值
// **/
//- (void) setValue1:(NSString *)value1
//{
//    [value1 retain];
//    [_value1 release];
//    _value1 = value1;
//}
//
//
//- (void) setValue3:(NSString *)value3
//{
//    _value3 = value3;
//}
//
///**
// *
// * copy 先释放旧值，在拷贝新值
// **/
//- (void) setValue4:(NSString *)value4
//{
//    [_value4 release];
//    _value4 = [value4 copy];
//}


/**
 *
 * MRC 不支持aotmic
 **/


/**
 *
 * ARC 去除手动计数代码
 **/

@synthesize value5 = _value5;
@synthesize value2 = _value6;

/**
 *
 * strong 先保留新值，再释放旧值
 **/
- (void) setValue1:(ZMPropertyTestItem *)value1
{
    _value1 = value1;
}

- (void) setValue2:(ZMPropertyTestItem *)value2
{
    _value6 = value2;
}

- (void) setValue3:(ZMPropertyTestItem *)value3
{
    _value3 = value3;
}

/**
 *
 * copy 先释放旧值，在拷贝新值
 **/
- (void) setValue4:(ZMPropertyTestItem *)value4
{
    _value4 = [value4 copy];
}


- (void) setValue5:(ZMPropertyTestItem *)value5
{
    @synchronized(@"value5")
    {
        _value5 = [value5 copy];
    }
}

- (ZMPropertyTestItem *) value5
{
    @synchronized(@"value5")
    {
        return _value5;
    }
}






@end
