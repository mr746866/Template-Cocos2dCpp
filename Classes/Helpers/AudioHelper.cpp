#include "AudioHelper.h"

#include "audio/include/SimpleAudioEngine.h"


using namespace std;
using namespace CocosDenshion;


#pragma mark - AudioHelper

#pragma mark

void AudioHelper::setEffectsVolume(float volume)
{
    SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
}

void AudioHelper::setMusicsVolume(float volume)
{
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
}

void AudioHelper::pauseAll()
{
    SimpleAudioEngine::getInstance()->pauseAllEffects();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AudioHelper::resumeAll()
{
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

#pragma mark

void AudioHelper::playClickEffect()
{    
    SimpleAudioEngine::getInstance()->playEffect("audios/click.mp3");
}

void AudioHelper::playBackgroundMusic()
{
    SimpleAudioEngine::getInstance()->playBackgroundMusic("audios/background.mp3", true);
}

#pragma mark

AudioHelper::AudioHelper()
{
}
