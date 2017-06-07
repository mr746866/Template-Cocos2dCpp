#include "HomeScene.h"

#include "../GamePlay/GamePlayScene.h"
#include "../../Helpers/Utility.h"
#include "../../Helpers/LayoutHelper.h"
#include "../../Helpers/AudioHelper.h"
#include "../../Helpers/CppBridge.h"


using namespace cocos2d;


#pragma mark - HomeScene

#pragma mark

HomeScene* HomeScene::create()
{
    HomeScene* instance = new HomeScene();
    
    if (instance && instance->init())
    {
        instance->autorelease();
    }
    else
    {
        delete instance;
        instance = nullptr;
    }
    
    return instance;
}

#pragma mark

HomeScene::~HomeScene()
{
}

bool HomeScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    LayoutHelper::initialize();

    setupBackgrounds();
    setupLabels();
    setupControls();
    setupDecorations();
    setupListeners();
    
    return true;
}

void HomeScene::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();
    
    _itemSpritePlay->runAction
        (
            Sequence::create
                (
                    DelayTime::create(0.2),
                    EaseSineOut::create(MoveTo::create(0.3, LayoutHelper::computePosition(0.5, 0.5))),
                    NULL
                )
        );
}

#pragma mark

void HomeScene::setupBackgrounds()
{
    LayerColor* layerColorBackground = LayerColor::create(Color4B(167, 44, 44, 255),
            LayoutHelper::getVisibleWidth(), LayoutHelper::getVisibleHeight());
    layerColorBackground->setPosition(LayoutHelper::computePosition(0, 0, true));
    addChild(layerColorBackground, - 4);
}

void HomeScene::setupLabels()
{
}

void HomeScene::setupControls()
{
    Menu* menu = Menu::create();
    menu->setPosition(LayoutHelper::computePosition(0, 0, true));
    addChild(menu, 3);
    
    _itemSpritePlay = Utility::createItemSprite("controls/button_play.png");
    _itemSpritePlay->setCallback(CC_CALLBACK_1(HomeScene::onClickPlay, this));
    _itemSpritePlay->setScale(LayoutHelper::computeScale(_itemSpritePlay, 0.36, 0.12));
    _itemSpritePlay->setPosition(LayoutHelper::computePosition(- 0.18, 0.5));
    menu->addChild(_itemSpritePlay);
}

void HomeScene::setupDecorations()
{
}

void HomeScene::setupListeners()
{
}

#pragma mark

void HomeScene::onClickPlay(Ref* sender)
{
    AudioHelper::playClickEffect();
    
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3, GamePlayScene::create()));
}
