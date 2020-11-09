//
//  ViewController.m
//  AVDemo
//
//  Created by 朱猛 on 2020/9/29.
//

#import "ViewController.h"
#import "mp3_encoder.hpp"



@interface TapGestureRecognizer : UITapGestureRecognizer

@end

@implementation TapGestureRecognizer

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [super touchesBegan:touches withEvent:event];
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [super touchesEnded:touches withEvent:event];
}

@end


@interface CustomView : UIView

@end

@implementation CustomView

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event{
    return [super hitTest:point withEvent:event];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [super touchesBegan:touches withEvent:event];
}

@end

@interface CustomView2 : UIButton

@end

@implementation CustomView2

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [super touchesBegan:touches withEvent:event];
}

@end


@interface ViewController () <UIGestureRecognizerDelegate>

@property(nonatomic,strong) UIGestureRecognizer *recognizer1;

@property(nonatomic,strong) UIGestureRecognizer *recognizer2;

@property(nonatomic,strong) UIView *view1;

@property(nonatomic,strong) UIView *view2;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view setBackgroundColor:[UIColor redColor]];
    
//    NSMutableString *path = [NSHomeDirectory() stringByAppendingString:@"/Documents/a.pcm"];
//    NSMutableString *path2 = [NSHomeDirectory() stringByAppendingString:@"/Documents/a.mp3"];
//
//    Mp3Encoder encoder;
//
//    encoder.Init(path.UTF8String, path2.UTF8String, 441000, 2, 320000);
//
//    encoder.Encode();
//
    
    UITapGestureRecognizer *tapGestureRecognizer3 = [[TapGestureRecognizer alloc] initWithTarget:self action:@selector(onSingleTap3)];
    [self.view addGestureRecognizer:tapGestureRecognizer3];
    
    

    
    UIView *view1 = [CustomView new];
    [view1 setBackgroundColor:[UIColor greenColor]];
    [view1 setFrame:CGRectMake(100, 100, 100, 100)];
    UITapGestureRecognizer *tapGestureRecognizer = [[TapGestureRecognizer alloc] initWithTarget:self action:@selector(onSingleTap1)];
    tapGestureRecognizer.delegate = self;
    self.recognizer1 = tapGestureRecognizer;
    [view1 addGestureRecognizer:tapGestureRecognizer];
    self.view1 = view1;
    
    [self.view addSubview:view1];
    
    UIButton *view2 = [CustomView2 new];
    [view2 addTarget:self action:@selector(onButtonClicked) forControlEvents:UIControlEventTouchUpInside];
    [view2 setBackgroundColor:[UIColor greenColor]];
    [view2 setFrame:CGRectMake(0, 0, 100, 100)];
  //  UITapGestureRecognizer *tapGestureRecognizer2 = [[TapGestureRecognizer alloc] initWithTarget:self action:@selector(onSingleTap2)];
   // tapGestureRecognizer2.delegate = self;
    //self.recognizer2 = tapGestureRecognizer2;
    //[view2 addGestureRecognizer:tapGestureRecognizer2];
    self.view2 = view2;
    [view1 addSubview:view2];
    
}

- (void) onSingleTap1{
    
}

- (void) onSingleTap2{
    
}

- (void) onSingleTap3{
    
}

- (void) onButtonClicked{
    
}


- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer{
    return TRUE;
}

// called when the recognition of one of gestureRecognizer or otherGestureRecognizer would be blocked by the other
// return YES to allow both to recognize simultaneously. the default implementation returns NO (by default no two gestures can be recognized simultaneously)
//
// note: returning YES is guaranteed to allow simultaneous recognition. returning NO is not guaranteed to prevent simultaneous recognition, as the other gesture's delegate may return YES
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer{
//    return TRUE;
//}
//
//// called once per attempt to recognize, so failure requirements can be determined lazily and may be set up between recognizers across view hierarchies
//// return YES to set up a dynamic failure requirement between gestureRecognizer and otherGestureRecognizer
////
//// note: returning YES is guaranteed to set up the failure requirement. returning NO does not guarantee that there will not be a failure requirement as the other gesture's counterpart delegate or subclass methods may return YES
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldRequireFailureOfGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer API_AVAILABLE(ios(7.0)){
//    return true;
//}
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldBeRequiredToFailByGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer API_AVAILABLE(ios(7.0)){
//    return true;
//}
//
//// called before touchesBegan:withEvent: is called on the gesture recognizer for a new touch. return NO to prevent the gesture recognizer from seeing this touch
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch{
//
//}
//
//// called before pressesBegan:withEvent: is called on the gesture recognizer for a new press. return NO to prevent the gesture recognizer from seeing this press
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceivePress:(UIPress *)press;
//
//// called once before either -gestureRecognizer:shouldReceiveTouch: or -gestureRecognizer:shouldReceivePress:
//// return NO to prevent the gesture recognizer from seeing this event
//- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer shouldReceiveEvent:(UIEvent *)event API_AVAILABLE(ios(13.4), tvos(13.4)) API_UNAVAILABLE(watchos);

@end
