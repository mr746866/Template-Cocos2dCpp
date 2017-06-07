#ifndef DataHelper_h
#define DataHelper_h


class DataHelper
{
public:
    static bool isSoundMuted();
    static void setSoundMuted(bool isMuted);
    static int getBestScore();
    static void setBestScore(int scoreBest);
    
private:
    DataHelper();
};


#endif /* DataHelper_h */
