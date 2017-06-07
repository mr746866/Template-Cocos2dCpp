#include "Utility.h"


using namespace std;
using namespace cocos2d;


#pragma mark - Utility

#pragma mark

int Utility::getRandomInt(int a, int b)
{
    if (a > b)
    {
        std::swap(a, b);
    }
    
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<> distribution(a, b);
    
    return distribution(generator);
}

float Utility::getRandomFloat(float a, float b)
{
    if (a > b)
    {
        std::swap(a, b);
    }
    
    random_device device;
    mt19937 generator(device());
    uniform_real_distribution<> distribution(a, b);
    
    return distribution(generator);
}

MenuItemSprite* Utility::createItemSprite(const string& fileName)
{
    Sprite* spriteNormal = Sprite::create(fileName);
    Sprite* spriteSelected = Sprite::create(fileName);
    spriteSelected->setColor(Color3B(200, 200, 200));
    
    return MenuItemSprite::create(spriteNormal, spriteSelected);
}

#pragma mark

Utility::Utility()
{
}
