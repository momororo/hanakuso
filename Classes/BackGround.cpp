//
//  BackGround.cpp
//  hanakuso
//
//  Created by yasutomo on 2015/08/19.
//
//

#include "BackGround.h"
#include "Config.h"

//ココスタジオ
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"


#define selfFrame Director::getInstance()->getWinSize()

using namespace cocos2d;


//初期化(シングルトンのみ)
BackGround* BackGround::instance = nullptr;

//空
BackGround::BackGround(){}

Sprite* BackGround::getBackGround(){
    return backGround;
}

BackGround* BackGround::getInstance()
{

    if(instance == nullptr){
    
        instance = new BackGround();
        
        instance -> init();
        
    }
    
    
    return instance;
}

void BackGround::init(){
    
    //大枠の背景
    backGround = Sprite::create();
    //アンカーポイントを真上に
    backGround -> setAnchorPoint(Vec2(0.5f, 1.0f));
    
    //ステージによって呼ぶ処理を変えること
    makeStage1();
    
    
    
}

void BackGround::makeStage1(){
   

    //ステージ長の設定
    int stageLength = 10;
    
    //長さを基準に背景を調整
    backGround -> setTextureRect(Rect(0,0, selfFrame.width, selfFrame.height * stageLength));
    
    backGround ->setPosition(selfFrame.width/2, selfFrame.height);
    
    log("背景のxポジは%f",backGround->getPositionX());
    
    //テスト用に色を変更する
    backGround -> setColor(Color3B::RED);
/*
    //背景画像で埋込
    //テストは適当に埋める
    for(int idx = 0 ; idx < 10 ; idx++){
        
        auto floor = Sprite::create();
        floor -> setTextureRect(Rect(0, 0, selfFrame.width, selfFrame.height));
        switch (random(0, 4)) {
            case 0: floor -> setColor(Color3B::GREEN);break;
            case 1: floor -> setColor(Color3B::YELLOW);break;
            case 2: floor -> setColor(Color3B::MAGENTA);break;
            case 3: floor -> setColor(Color3B::ORANGE);break;
            case 4: floor -> setColor(Color3B::WHITE);break;
            default:                break;
        }
*/
    
        auto floor = CSLoader::getInstance()->createNode("MainScene.csb");
    
/*
        //アンカーポイントを真下に
        floor -> setAnchorPoint(Vec2(0.5f,0.0f));
        //位置の調整
        floor -> setPosition(Vec2(backGround->getPositionX(),backGround->getContentSize().height / 0));
*/
    
        //アンカーポイントを真下に
        floor -> setAnchorPoint(Vec2(0.5f,0.5f));
        //位置の調整
        floor -> setPosition(Vec2(selfFrame.width/2,selfFrame.height/2));

        log("小背景のxポジは%f",floor->getPositionX());
        

        
        backGround->addChild(floor);
        
    //}
    
    
}

void BackGround::update(){

    
    
//スタート前に視点を奥から手前へバン
    if (Config::statusFlag == STATUSFLAG::PRESTART) {

        //バン速度
        int speed = 50;
     
        
        //手前から奥へバン
        if(backGround -> getPositionY() - backGround -> getContentSize().height + speed < 0  )
            backGround -> setPosition(Vec2(backGround->getPositionX(),backGround->getPositionY() + speed));
        else{
            
            
            //最後の調整
            backGround -> setPosition(Vec2(backGround->getPositionX(),backGround->getContentSize().height));
            
            //スタート状態に遷移
            Config::statusFlag = STATUSFLAG::START;

        }
        
        
    }
    
//プレイ中は視点を手前から奥にバン
    if(Config::statusFlag == STATUSFLAG::PLAY){
        
        //バン速度
        int speed = 25;
        
        //手前から奥へバン
        if(backGround -> getPositionY() - selfFrame.height - speed > 0  ){
            backGround -> setPosition(Vec2(backGround->getPositionX(),backGround->getPositionY() - speed));
        }else{
            backGround -> setPosition(Vec2(backGround->getPositionX(),selfFrame.height));
            
            //end状態に遷移
            Config::statusFlag = STATUSFLAG::GOAL;
        }

        
    }
    
}