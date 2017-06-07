#ifndef LayoutHelper_h
#define LayoutHelper_h


#include "cocos2d.h"


class LayoutHelper
{
public:
    static void initialize();
    static float getVisibleWidth();
    static float getVisibleHeight();
    static cocos2d::Vec2 getVisibleOrigin();
    static cocos2d::Vec2 computePosition(float widthPercent, float heightPercent,
            bool adjustOrigin = false);
    static float computeScale(cocos2d::Node* node, float maxWidthPercent, float maxHeightPercent);

private:
    static cocos2d::Vec2 _originVisible;
    static cocos2d::Size _sizeVisible;
    
    LayoutHelper();
};


#endif /* LayoutHelper_h */
