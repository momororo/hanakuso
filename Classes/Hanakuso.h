//
//  Hanakuso.h
//  hanakuso
//
//  Created by yasutomo on 2015/08/19.
//
//

#ifndef __hanakuso__Hanakuso__
#define __hanakuso__Hanakuso__

#include "cocos2d.h"


class Hanakuso : public cocos2d::Ref
{
public:
    
    //スプライト型を生成
    static Hanakuso* getInstance();

    //処理を追加すること
    cocos2d::Sprite* getHanakuso();
    
    void update();
    
private:
    
    //シングルトンの場合は変数の宣言が必要
    static Hanakuso* instance;
    
    //newを出来ないようにprivateにコンストラクタを置く
    Hanakuso();
    
    void init();
    
    //必要な変数を追加すること
    cocos2d::Sprite* hanakuso;
};

#endif /* defined(__hanakuso__Hanakuso__) */
