//
//  GameScene.h
//  hanakuso
//
//  Created by yasutomo on 2015/08/18.
//
//

#ifndef __hanakuso__GameScene__
#define __hanakuso__GameScene__

#include "cocos2d.h"
#include "BackGround.h"

using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
public:

    
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    void update(float delta);
    
    //イベント処理
    //タップイベントの宣言
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);

    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

};

#endif /* defined(__hanakuso__GameScene__) */
