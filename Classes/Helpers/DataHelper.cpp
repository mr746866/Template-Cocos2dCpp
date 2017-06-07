#include "DataHelper.h"

#include "cocos2d.h"


using namespace cocos2d;


#pragma mark - DataHelper

#pragma mark

bool DataHelper::isSoundMuted()
{
    return UserDefault::getInstance()->getBoolForKey("SOUND_MUTED", false);
}

void DataHelper::setSoundMuted(bool isMuted)
{
    UserDefault::getInstance()->setBoolForKey("SOUND_MUTED", isMuted);
    UserDefault::getInstance()->flush();
}

int DataHelper::getBestScore()
{
    return UserDefault::getInstance()->getIntegerForKey("BEST_SCORE", 0);
}

void DataHelper::setBestScore(int scoreBest)
{
    UserDefault::getInstance()->setIntegerForKey("BEST_SCORE", scoreBest);
    UserDefault::getInstance()->flush();
}

#pragma mark

DataHelper::DataHelper()
{
}
