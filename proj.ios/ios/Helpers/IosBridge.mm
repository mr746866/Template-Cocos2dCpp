#include "IosBridge.h"

#include "AppController.h"


#pragma mark - IosBridge

#pragma mark

void IosBridge::shareApp()
{
    AppController* appController = (AppController*)[UIApplication sharedApplication].delegate;
    [appController shareApp];
}

void IosBridge::showInterstitial()
{
    AppController* appController = (AppController*)[UIApplication sharedApplication].delegate;
    [appController showInterstitial];
}
