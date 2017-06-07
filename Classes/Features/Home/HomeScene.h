#ifndef HomeScene_h
#define HomeScene_h


#include "cocos2d.h"


class HomeScene : public cocos2d::Scene
{
public:
    static HomeScene* create();

    virtual ~HomeScene();
    virtual bool init();
    virtual void onEnterTransitionDidFinish();
    
private:
    cocos2d::MenuItemSprite* _itemSpritePlay;
    
    void setupBackgrounds();
    void setupLabels();
    void setupControls();
    void setupDecorations();
    void setupListeners();
    
    void onClickPlay(cocos2d::Ref* sender);
};


#endif /* HomeScene_h */
