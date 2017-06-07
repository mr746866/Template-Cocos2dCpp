#ifndef GamePlayScene_h
#define GamePlayScene_h


#include "cocos2d.h"


class GamePlayScene : public cocos2d::Scene
{
public:
    static GamePlayScene* create();

    virtual ~GamePlayScene();
    virtual bool init();
    virtual void onEnterTransitionDidFinish();
    
private:
    int _score;
    
    cocos2d::Label* _labelScore;
    cocos2d::Sprite* _spriteInstruction;
    
    void setupBackgrounds();
    void setupLabels();
    void setupControls();
    void setupDecorations();
    void setupListeners();    
};


#endif /* GamePlayScene_h */
