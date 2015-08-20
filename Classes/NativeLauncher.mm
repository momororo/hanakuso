//
//  NativeLauncher.cpp
//  hanakuso
//
//  Created by 新井脩司 on 2015/08/19.
//
//
#include "NativeLauncher.h"
//#include <Twitter/Twitter.h>
#include <Social/Social.h>


/*
//レビューに誘導
void NativeLauncher::openReview(){
    
    //IDを入れてね
    NSURL *reivewURL = [NSURL URLWithString:[NSString stringWithFormat:@"https://itunes.apple.com/jp/app/reindoroppu-luochiru-nawo/id%d?mt=8&ign-mpt=uo%%3D4",957700310]];
    [[UIApplication sharedApplication] openURL:reivewURL];
    
}

//Game Center
void NativeLauncher::loginGameCenter()
{
    [GameCenter loginGameCenter];
}
// Leaderboard表示
void NativeLauncher::openRanking()
{
    [GameCenter openRanking];
}
// ハイスコアを送信
void NativeLauncher::postHighScore(std::string key,int score)
{
    [GameCenter postHighScore:[[[NSString alloc] initWithCString:key.c_str() encoding:NSUTF8StringEncoding] autorelease] score:score];
}
*/


//twitter
void NativeLauncher::openTweetDialog(const char *$tweet,const char *filePath){
    NSString* tweet = [NSString stringWithUTF8String:$tweet];
    NSString* screenshot = [NSString stringWithUTF8String:filePath];
        
    if([SLComposeViewController isAvailableForServiceType:SLServiceTypeTwitter]){
        UIViewController *myViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
        SLComposeViewController *composeCtl = [[SLComposeViewController alloc]init];
        [composeCtl setInitialText: tweet];
        UIImage *image = [UIImage imageWithContentsOfFile:screenshot];
        [composeCtl addImage:image];
        
        composeCtl.completionHandler = ^(SLComposeViewControllerResult res){
            [myViewController dismissViewControllerAnimated:YES completion: nil];
            //ログで確認用。あとで削除
            if (res == SLComposeViewControllerResultDone) {
                NSLog(@"ツイート成功！");
            }
        };
        [myViewController presentViewController: composeCtl animated:YES completion: nil];
    }else{
        tweet = [NSString stringWithFormat: @"%@%@",@"http://twitter.com/intent/tweet?text=",tweet];
        tweet = [tweet stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        [[UIApplication sharedApplication]openURL:[NSURL URLWithString:tweet]];
    }
    tweet = nil;
}

/*
//appbankSSP
void NativeLauncher::setAppbankSSP(){
    
    [AppbankSSP setAppbankSSP];
    
}

void NativeLauncher::startInterstitial(){
    [AppbankSSP startInterstitial];
}

void NativeLauncher::stopInterstitial(){
    [AppbankSSP stopInterstitial];
}

void NativeLauncher::showInterstitial(){
    [AppbankSSP showInterstitial];
}

void NativeLauncher::loadInterstitial(){
    [AppbankSSP loadInterstitial];
}
*/
