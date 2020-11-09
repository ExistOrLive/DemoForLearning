//
//  AppDelegate.m
//  AVDemo
//
//  Created by 朱猛 on 2020/9/29.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] init];
    [self.window setRootViewController:[ViewController new]];
    
    [self.window makeKeyAndVisible];
    return YES;
}



@end
