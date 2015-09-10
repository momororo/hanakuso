//
//  Hanakuso.cpp
//  hanakuso
//
//  Created by yasutomo on 2015/08/19.
//
//

#include "Hanakuso.h"
#include "Config.h"
#define selfFrame Director::getInstance()->getWinSize()

using namespace cocos2d;


//初期化(シングルトンのみ)
Hanakuso* Hanakuso::instance = nullptr;

//空
Hanakuso::Hanakuso(){}

//getter
Sprite* Hanakuso::getHanakuso(){
    return hanakuso;
}

Hanakuso* Hanakuso::getInstance()
{

    if(instance == nullptr){
    
        instance = new Hanakuso();
        
        instance -> init();
        
    }
    
    
    return instance;
}

void Hanakuso::init(){
    
    //処理を書く
    hanakuso = Sprite::create();
    hanakuso -> setTextureRect(Rect(0, 0, 50, 50));
    hanakuso -> setColor(Color3B::BLACK);
    
    //仮うち
    hanakuso -> setPosition(Vec2(selfFrame.width/2, selfFrame.height/10));
    
    //最初は不可視に
    hanakuso -> setVisible(false);
    
    return;
    
    
}

void Hanakuso::update(){
    
    
    //スタート時で不可視状態の場合は可視化
    if(Config::statusFlag == STATUSFLAG::START && (hanakuso->isVisible() == false)){
        //鼻くそ可視化
        hanakuso -> setVisible(true);
    }
    
    //プレイ中かゴール中　かつ　タップ中
    if((Config::statusFlag == STATUSFLAG::PLAY || Config::statusFlag == STATUSFLAG::GOAL) && Config::tapPoint != TAPPOINT::NONE){
        
        //右へ
        if(Config::tapPoint == TAPPOINT::RIGHT){
            
            hanakuso -> setPosition(Vec2(hanakuso->getPositionX() + 20, hanakuso->getPositionY()));
            
        }
        
        //左へ
        if(Config::tapPoint == TAPPOINT::LEFT){
            
            hanakuso -> setPosition(Vec2(hanakuso->getPositionX() - 20, hanakuso->getPositionY()));
            
        }
        
    }
    
    //ゴール中は前方に移動
    if(Config::statusFlag == STATUSFLAG::GOAL){

            hanakuso -> setPosition(Vec2(hanakuso->getPositionX(), hanakuso->getPositionY() + 25));
        
    }
    
    
    //フィールド外に出た場合はゲームオーバー状態に変化させる
    if(hanakuso->getPositionY() - hanakuso->getContentSize().height/2 > selfFrame.height){
        
        //失敗
        Config::statusFlag = STATUSFLAG::BADEND;
        
    }
    
 
    
}
