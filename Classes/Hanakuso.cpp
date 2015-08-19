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
    
    
    if(Config::statusFlag == STATUSFLAG::START && (hanakuso->isVisible() == false)){
        //鼻くそ可視化
        hanakuso -> setVisible(true);
    }
    
    if(Config::statusFlag == STATUSFLAG::PLAY && Config::tapPoint != TAPPOINT::NONE){
        
        //右へ
        if(Config::tapPoint == TAPPOINT::RIGHT){
            
            hanakuso -> setPosition(Vec2(hanakuso->getPositionX() + 20, hanakuso->getPositionY()));
            
        }
        
        //左へ
        if(Config::tapPoint == TAPPOINT::LEFT){
            
            hanakuso -> setPosition(Vec2(hanakuso->getPositionX() - 20, hanakuso->getPositionY()));
            
        }
        
    }
 
    
}