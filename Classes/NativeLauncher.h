//
//  NativeLauncher.h
//  hanakuso
//
//  Created by 新井脩司 on 2015/08/19.
//
//

#ifndef __hanakuso__NativeLauncher__
#define __hanakuso__NativeLauncher__

#include <stdio.h>

class NativeLauncher{
public:
    //レビュー誘導
    //static void openReview();
    
    //Game Center
    //static void loginGameCenter();
    //static void openRanking();
    //static void postHighScore(std::string key ,int score);
    
    //twitter
    static void openTweetDialog(const char* $tweet,const char *filePath);
    
    //appbank ssp
    //static void setAppbankSSP();
    
    //appbank interstittial
    //static void startInterstitial();
    //static void stopInterstitial();
    //static void showInterstitial();
    //static void loadInterstitial();
    
};

#endif /* defined(__hanakuso__NativeLauncher__) */
