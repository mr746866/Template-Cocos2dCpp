#include "CppBridge.h"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IosBridge.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif


#pragma mark - CppBridge

#pragma mark

void CppBridge::shareApp()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    IosBridge::shareApp();
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    cocos2d::JniMethodInfo methodInfo;

    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/AndroidBridge", "shareApp", "()V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
    #endif
}

void CppBridge::showInterstitial()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    IosBridge::showInterstitial();
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    cocos2d::JniMethodInfo methodInfo;

    if (cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "org/cocos2dx/cpp/AndroidBridge", "showInterstitial", "()V"))
    {
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
    #endif
}

#pragma mark

CppBridge::CppBridge()
{
}
