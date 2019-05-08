//
//  ViewController.m
//  AVAudioTest
//
//  Created by panzhengwei on 2019/5/7.
//  Copyright © 2019年 ZTE. All rights reserved.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "AppDelegate.h"

@interface ViewController ()

@property(nonatomic,strong) UIButton * playButton;

@property(nonatomic,strong) UIButton * recordButton;



@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.playButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.playButton setFrame:CGRectMake(50, 100, 100, 50)];
    [self.playButton setTitle:@"play" forState:UIControlStateNormal];
    [self.playButton setBackgroundColor:[UIColor blueColor]];
    [self.view addSubview:self.playButton];
    [self.playButton addTarget:self action:@selector(onPlayButtonClicked) forControlEvents:UIControlEventTouchUpInside];
    
    self.recordButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.recordButton setFrame:CGRectMake(50, 200, 100, 50)];
    [self.recordButton setTitle:@"record" forState:UIControlStateNormal];
    [self.recordButton setBackgroundColor:[UIColor blueColor]];
    [self.view addSubview:self.recordButton];
    [self.recordButton addTarget:self action:@selector(onRecordButtonClicked) forControlEvents:UIControlEventTouchUpInside];
    
    
    AVAudioSession * session = [AVAudioSession sharedInstance];

    

    NSLog(@"%@",[session category]);
    
    [session setCategory:AVAudioSessionCategoryPlayAndRecord withOptions:AVAudioSessionCategoryOptionDefaultToSpeaker error:nil];
    BOOL result = [session setActive:YES withOptions:AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation error:nil];

    
      NSLog(@"%@",[session category]);
    
    
}


- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
    
}

- (void) onPlayButtonClicked
{    
    AppDelegate * appDelegate = (AppDelegate *)[UIApplication sharedApplication].delegate;
    AVAudioPlayer * player = appDelegate.player;

    if([player isPlaying])
    {
        [player stop];
    }
    else
    {
        NSString * filePath = [[NSBundle mainBundle] pathForResource:@"ringin" ofType:@"wav"];

        appDelegate.player = [[AVAudioPlayer alloc] initWithContentsOfURL:[NSURL URLWithString:filePath] error:nil];

        [appDelegate.player setNumberOfLoops:100];
        [appDelegate.player play];
    }
    
//    SystemSoundID soundID;
//    NSURL *url = [[NSBundle mainBundle] URLForResource:@"ringin.wav" withExtension:nil];
//    AudioServicesCreateSystemSoundID((__bridge CFURLRef)(url), &soundID);
//
//     AudioServicesPlaySystemSound(soundID);
//    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);

}


- (void) onRecordButtonClicked
{
      AVAudioSession * session = [AVAudioSession sharedInstance];
     [session setActive:NO withOptions:AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation error:nil];
}


@end
