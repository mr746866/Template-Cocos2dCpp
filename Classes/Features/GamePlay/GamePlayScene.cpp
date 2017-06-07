#include "GamePlayScene.h"

#include "../Home/HomeScene.h"
#include "../../Helpers/Utility.h"
#include "../../Helpers/LayoutHelper.h"
#include "../../Helpers/AudioHelper.h"
#include "../../Helpers/CppBridge.h"


using namespace cocos2d;


#pragma mark - GamePlayScene

#pragma mark

GamePlayScene* GamePlayScene::create()
{
    GamePlayScene* instance = new GamePlayScene();
    
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

GamePlayScene::~GamePlayScene()
{
}

bool GamePlayScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    
    _score = 0;
    
    LayoutHelper::initialize();
    
    setupBackgrounds();
    setupLabels();
    setupControls();
    setupDecorations();
    setupListeners();
    
    return true;
}

void GamePlayScene::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();
}

#pragma mark

void GamePlayScene::setupBackgrounds()
{
    LayerColor* layerColorBackground = LayerColor::create(Color4B(167, 44, 44, 255),
            LayoutHelper::getVisibleWidth(), LayoutHelper::getVisibleHeight());
    layerColorBackground->setPosition(LayoutHelper::computePosition(0, 0, true));
    addChild(layerColorBackground, - 4);
}

void GamePlayScene::setupLabels()
{
    char textScore[3];
    sprintf(textScore, "%d", _score);
    _labelScore = Label::createWithTTF(textScore, "fonts/silkscreen.ttf", 120);
    _labelScore->setPosition(LayoutHelper::computePosition(0.5, 0.5, true));
    addChild(_labelScore, 4);
}

void GamePlayScene::setupControls()
{
}

void GamePlayScene::setupDecorations()
{
    _spriteInstruction = Sprite::create("images/instruction_play.png");
    _spriteInstruction->setScale(LayoutHelper::computeScale(_spriteInstruction, 0.4, 0.18));
    _spriteInstruction->setPosition(LayoutHelper::computePosition(0.5, 0.25, true));
    addChild(_spriteInstruction, 3);
}

void GamePlayScene::setupListeners()
{
    EventListenerTouchOneByOne* listenerTouch = EventListenerTouchOneByOne::create();
    listenerTouch->setSwallowTouches(true);
    listenerTouch->onTouchBegan = [=](Touch* touch, Event* event) -> bool
        {
            _score++;
            
            char textScore[3];
            sprintf(textScore, "%d", _score);
            _labelScore->setString(textScore);
            
            if (_spriteInstruction)
            {
                _spriteInstruction->removeFromParentAndCleanup(true);
                _spriteInstruction = nullptr;
            }
            
            if (_score >= 10)
            {
                Director::getInstance()->replaceScene(
                        TransitionCrossFade::create(0.3, HomeScene::create()));
            }
            
            return true;
        };
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerTouch, this);
}
