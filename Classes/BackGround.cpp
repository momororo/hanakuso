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

Node* BackGround::getBackGround(){
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
    
    //ステージによって呼ぶ処理を変えること
    makeStage1();
    
    
    
}

void BackGround::makeStage1(){
   
        backGround = CSLoader::getInstance()->createNode("StageTest.csb");
    
        //アンカーポイントを真下
        backGround ->setAnchorPoint(Vec2(0.5f, 1.0f));
        
        backGround ->setPosition(selfFrame.width/2,selfFrame.height);
    
        log("init時のyポジは%f",backGround->getPositionY());
    
        log("縦は%f、横は%f",backGround->getContentSize().height,backGround->getContentSize().width);
    
}

void BackGround::update(){

    
    
//スタート前に視点を奥から手前へバン
    if (Config::statusFlag == STATUSFLAG::PRESTART) {

        //バン速度
        int speed = 50;
     
        log("yポジは%f",backGround->getPositionY());
        
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