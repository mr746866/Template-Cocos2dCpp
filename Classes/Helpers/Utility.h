#ifndef Utility_h
#define Utility_h


#include "cocos2d.h"


class Utility
{
public:
    static int getRandomInt(int a, int b);
    static float getRandomFloat(float a, float b);
    static cocos2d::MenuItemSprite* createItemSprite(const std::string& fileName);
    
private:
    Utility();
};


#endif /* Utility_h */
