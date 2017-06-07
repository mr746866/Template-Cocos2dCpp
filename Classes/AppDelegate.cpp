#include "AppDelegate.h"
#include "audio/include/SimpleAudioEngine.h"

#include "Features/Home/HomeScene.h"
#include "Helpers/LayoutHelper.h"
#include "Helpers/AudioHelper.h"


using namespace cocos2d;
using namespace CocosDenshion;


static cocos2d::Size sizeDesignResolution = cocos2d::Size(320, 480);

static int register_all_packages()
{
    return 0;
}


#pragma mark - AppDelegate

#pragma mark

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
    SimpleAudioEngine::end();
}

#pragma mark

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    Director* director = Director::getInstance();
    GLView* glview = director->getOpenGLView();
    
    if (!glview)
    {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) \
            || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Template",
                cocos2d::Rect(0, 0, sizeDesignResolution.width, sizeDesignResolution.height));
        #else
        glview = GLViewImpl::create("Template");
        #endif
    }

    glview->setDesignResolutionSize(sizeDesignResolution.width, sizeDesignResolution.height,
            ResolutionPolicy::NO_BORDER);

    register_all_packages();
    
    preloadImages();
    preloadAudios();

    director->setOpenGLView(glview);
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    director->runWithScene(TransitionCrossFade::create(0.3, HomeScene::create()));
    
    AudioHelper::playBackgroundMusic();

    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseAllEffects();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeAllEffects();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

#pragma mark

void AppDelegate::preloadImages()
{
    Director::getInstance()->getTextureCache()->addImage("controls/button_play.png");

    Director::getInstance()->getTextureCache()->addImage("images/instruction_play.png");
}

void AppDelegate::preloadAudios()
{
    SimpleAudioEngine::getInstance()->preloadEffect("audios/click.mp3");
    
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audios/background.mp3");
}
