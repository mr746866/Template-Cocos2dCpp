#ifndef AudioHelper_h
#define AudioHelper_h


class AudioHelper
{
public:
    static void setEffectsVolume(float volume);
    static void setMusicsVolume(float volume);
    static void pauseAll();
    static void resumeAll();
    
    static void playClickEffect();
    static void playBackgroundMusic();
    
private:
    AudioHelper();
};


#endif /* AudioHelper_h */
