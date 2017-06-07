#import "AppController.h"
#import "RootViewController.h"

#import "cocos2d.h"
#import "AppDelegate.h"


#pragma mark - AppController

@interface AppController ()

@property (nonatomic, readonly) RootViewController* viewController;

@end


#pragma mark - AppController

@implementation AppController

static AppDelegate s_sharedApplication;

@synthesize window;

#pragma mark

- (void) dealloc
{
    [window release];
    [_viewController release];
    
    [super dealloc];
}

#pragma mark

- (BOOL) application:(UIApplication*)application
        didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    cocos2d::Application* app = cocos2d::Application::getInstance();
    app->initGLContextAttrs();
    
    cocos2d::GLViewImpl::convertAttrs();

    _viewController = [[RootViewController alloc] init];
    _viewController.edgesForExtendedLayout = UIRectEdgeAll;
    _viewController.extendedLayoutIncludesOpaqueBars = YES;
    
    window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    window.rootViewController = _viewController;
    [window makeKeyAndVisible];

    [[UIApplication sharedApplication] setStatusBarHidden:true];
    
    cocos2d::GLView* glview =
            cocos2d::GLViewImpl::createWithEAGLView((__bridge void*)_viewController.view);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    
    app->run();

    return YES;
}

- (void) applicationWillResignActive:(UIApplication*)application
{
    cocos2d::Director::getInstance()->pause();
}

- (void) applicationDidBecomeActive:(UIApplication*)application
{
    cocos2d::Director::getInstance()->resume();
}

- (void) applicationDidEnterBackground:(UIApplication*)application
{
    cocos2d::Application::getInstance()->applicationDidEnterBackground();
}

- (void) applicationWillEnterForeground:(UIApplication*)application
{
    cocos2d::Application::getInstance()->applicationWillEnterForeground();
}

#pragma mark

- (void) shareApp
{
}

- (void) showInterstitial
{
}

@end
