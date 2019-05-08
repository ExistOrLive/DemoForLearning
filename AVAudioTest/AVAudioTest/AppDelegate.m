//
//  AppDelegate.m
//  AVAudioTest
//
//  Created by panzhengwei on 2019/5/7.
//  Copyright © 2019年 ZTE. All rights reserved.
//

#import "AppDelegate.h"
#import <AVFoundation/AVFoundation.h>
#import <CoreTelephony/CTCall.h>
#import <CoreTelephony/CTCallCenter.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNotificationArrived:) name:AVAudioSessionInterruptionNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNotificationArrived:) name:AVAudioSessionRouteChangeNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNotificationArrived:) name:AVAudioSessionMediaServicesWereLostNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNotificationArrived:) name:AVAudioSessionMediaServicesWereResetNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onNotificationArrived:) name:AVAudioSessionSilenceSecondaryAudioHintNotification object:nil];
    
    
    CTCallCenter * callCenter = [[CTCallCenter alloc] init];
    callCenter.callEventHandler = ^(CTCall * call) {
        [self dealWithTelephoneCall:call];
    };
    
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


- (void) onNotificationArrived:(NSNotification *) notification
{
    NSLog(@"notification[%@] catagory[%@]",notification.name,[AVAudioSession sharedInstance].category);
    
    if([notification.name isEqualToString:AVAudioSessionInterruptionNotification])
    {
        NSDictionary * dic = notification.userInfo;
        
        if([dic[AVAudioSessionInterruptionTypeKey] integerValue] == AVAudioSessionInterruptionTypeBegan)
        {
           //[self.player pause];
        }
        else if([dic[AVAudioSessionInterruptionTypeKey] integerValue] == AVAudioSessionInterruptionTypeEnded)
        {
//            [[AVAudioSession sharedInstance] setActive:YES error:nil];
//            [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayAndRecord error:nil];
            //[self.player play];
        }
        
        NSLog(@"AVAudioSessionInterruptionNotification: [%@]",dic);
    }
    else if([notification.name isEqualToString:AVAudioSessionRouteChangeNotification])
    {
        
    }
    else if([notification.name isEqualToString:AVAudioSessionSilenceSecondaryAudioHintNotification])
    {
        NSDictionary * dic = notification.userInfo;
        
        NSLog(@"AVAudioSessionSilenceSecondaryAudioHintNotification: [%@]",dic);
    }
    else if([notification.name isEqualToString:AVAudioSessionMediaServicesWereLostNotification])
    {
        
    }
    else if([notification.name isEqualToString:AVAudioSessionMediaServicesWereResetNotification])
    {
        
    }
    
    
}

- (void) dealWithTelephoneCall:(CTCall *)call
{
    NSLog(@"current call status[%@]",call.callState);
    
    if([call.callState isEqualToString:CTCallStateConnected])
    {
        if([self.player isPlaying])
        {
            [self.player stop];
        }
        
        self.player = nil;
    }
}



@end
