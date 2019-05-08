//
//  AppDelegate.h
//  AVAudioTest
//
//  Created by panzhengwei on 2019/5/7.
//  Copyright © 2019年 ZTE. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property(nonatomic,strong) AVAudioPlayer * player;

@end

