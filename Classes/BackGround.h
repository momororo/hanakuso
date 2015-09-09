//
//  BackGround.h
//  hanakuso
//
//  Created by yasutomo on 2015/08/19.
//
//

#ifndef __hanakuso__BackGround__
#define __hanakuso__BackGround__

#include "cocos2d.h"


class BackGround : public cocos2d::Ref
{
public:
    
    //スプライト型を生成
    static BackGround* getInstance();

    //処理を追加すること
    void update();
    
    //getter
    cocos2d::Node* getBackGround();
    
    
private:
    
    
    cocos2d::Node* backGround;
    
    //シングルトンの場合は変数の宣言が必要
    static BackGround* instance;
    
    //newを出来ないようにprivateにコンストラクタを置く
    BackGround();
    
    void init();
    
    //必要な変数を追加すること
    
    //ステージ作成
    void makeStage1();
    
    
};

#endif /* defined(__hanakuso__BackGround__) */
