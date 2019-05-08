//
//  ZMPropertyTest.h
//  PropertyTestDemo
//
//  Created by 朱猛 on 2019/5/7.
//  Copyright © 2019年 朱猛. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMPropertyTestItem: NSObject <NSCopying>

@end

@interface ZMPropertyTest : NSObject

@property(nonatomic,strong) ZMPropertyTestItem * value1;

@property(nonatomic,weak) ZMPropertyTestItem * value2;     //MRC 环境不支持weak

@property(nonatomic,unsafe_unretained) ZMPropertyTestItem * value3;

@property(nonatomic,copy) ZMPropertyTestItem * value4;

@property(atomic,copy) ZMPropertyTestItem * value5;    // MRC 不支持aotmic


@end
