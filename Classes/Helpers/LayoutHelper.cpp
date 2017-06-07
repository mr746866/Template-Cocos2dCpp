#include "LayoutHelper.h"


using namespace cocos2d;


#pragma mark - LayoutHelper

Vec2 LayoutHelper::_originVisible = Vec2(0, 0);
Size LayoutHelper::_sizeVisible = Size(0, 0);

#pragma mark

void LayoutHelper::initialize()
{
    _originVisible = Director::getInstance()->getVisibleOrigin();
    _sizeVisible = Director::getInstance()->getVisibleSize();
}

float LayoutHelper::getVisibleWidth()
{
    return _sizeVisible.width;
}

float LayoutHelper::getVisibleHeight()
{
    return _sizeVisible.height;
}

Vec2 LayoutHelper::getVisibleOrigin()
{
    return _originVisible;
}

Vec2 LayoutHelper::computePosition(float widthPercent, float heightPercent, bool adjustOrigin)
{
    Vec2 position = Vec2(_sizeVisible.width * widthPercent, _sizeVisible.height * heightPercent);
    
    if (adjustOrigin)
    {
        position += _originVisible;
    }
    
    return position;
}

float LayoutHelper::computeScale(Node* node, float maxWidthPercent, float maxHeightPercent)
{
    return MIN(_sizeVisible.width / node->getContentSize().width * maxWidthPercent,
            _sizeVisible.height / node->getContentSize().height * maxHeightPercent);
}

#pragma mark

LayoutHelper::LayoutHelper()
{
    _originVisible = Vec2(0, 0);
    _sizeVisible = Size(0, 0);
}
