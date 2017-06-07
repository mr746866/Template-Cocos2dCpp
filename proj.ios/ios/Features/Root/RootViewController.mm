#import "RootViewController.h"

#import "cocos2d.h"
#import "platform/ios/CCEAGLView-ios.h"


#pragma mark - RootViewController

@implementation RootViewController

#pragma mark

- (void) loadView
{
    CCEAGLView* eaglView = [CCEAGLView viewWithFrame:[UIScreen mainScreen].bounds
            pixelFormat:(__bridge NSString*)cocos2d::GLViewImpl::_pixelFormat
            depthFormat:cocos2d::GLViewImpl::_depthFormat preserveBackbuffer:NO sharegroup:nil
            multiSampling:NO numberOfSamples:0];
    
    [eaglView setMultipleTouchEnabled:NO];
    
    self.view = eaglView;
}

- (void) viewDidLoad
{
    [super viewDidLoad];
}

- (void) didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];

    cocos2d::GLView* glview = cocos2d::Director::getInstance()->getOpenGLView();

    if (glview)
    {
        CCEAGLView *eaglview = (__bridge CCEAGLView*)glview->getEAGLView();

        if (eaglview)
        {
            CGSize size = CGSizeMake([eaglview getWidth], [eaglview getHeight]);
            cocos2d::Application::getInstance()->
                    applicationScreenSizeChanged((int)size.width, (int)size.height);
        }
    }
}

- (BOOL) prefersStatusBarHidden
{
    return YES;
}

@end
