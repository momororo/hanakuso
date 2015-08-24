//
//  GameScene.cpp
//  hanakuso
//
//  Created by yasutomo on 2015/08/18.
//
//

#include "GameScene.h"
#include "Config.h"
#include "Hanakuso.h"
#define selfFrame Director::getInstance()->getWinSize()

using namespace cocos2d;

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    

    //背景
    this -> addChild(BackGround::getInstance() -> getBackGround());
    //鼻くそ
    this -> addChild(Hanakuso::getInstance() -> getHanakuso());
    
    /**************　タッチイベント設定  ******************/
    
    //シングルタップ用リスナーを用意する
    auto listener = EventListenerTouchOneByOne::create();
    //listener -> setSwallowTouches(_swallowsTouches);
    
    
    //各イベントの割り当て
    listener -> onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan,this);
    listener -> onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved,this);
    listener -> onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded,this);
    listener -> onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled,this);
    
    //イベントディスパッチャようにリスナーを追加する
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    /*************　　タッチイベント設定  終 ****************/

    
    
    //ステータス設定
    Config::statusFlag = STATUSFLAG::PREPARATION;
    Config::tapPoint = TAPPOINT::NONE;
    
    scheduleUpdate();
    
    return true;
}




bool GameScene::onTouchBegan(Touch *touch, Event *unused_event){

    
    //ポイントの取得
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
    
    //開始前の開始？処理
    if(Config::statusFlag == STATUSFLAG::PREPARATION){
        
        Config::statusFlag = STATUSFLAG::PRESTART;
        return true;
    
    }
    

    
    //スタート処理
    if(Config::statusFlag == STATUSFLAG::START){
        
        Config::statusFlag = STATUSFLAG::PLAY;
        return true;
    }

    
    
    //鼻くそより右か左か判定
    if(touchPoint.x < Hanakuso::getInstance()->getHanakuso()->getPositionX()){
        Config::tapPoint = TAPPOINT::LEFT;
    }else{
        Config::tapPoint = TAPPOINT::RIGHT;
    }
    
    return true;
 
 
}

void GameScene::onTouchMoved(Touch *touch, Event *unused_event){

    //ポイントの取得
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
    
    //鼻くそより右か左か判定
    if(touchPoint.x < Hanakuso::getInstance()->getHanakuso()->getPositionX()){
        Config::tapPoint = TAPPOINT::LEFT;
    }else{
        Config::tapPoint = TAPPOINT::RIGHT;
    }
        
    
    return;
 
}

void GameScene::onTouchEnded(Touch *touch, Event *unused_event){
    //タップ検知終了
    Config::tapPoint = TAPPOINT::NONE;
    
    return;
}

void GameScene::onTouchCancelled(Touch *touch, Event *unused_event){
    
    
}


void GameScene::update(float delta){
    
    if(Config::statusFlag != STATUSFLAG::PREPARATION){
        
        //各ファイルのupdateを記述
        BackGround::getInstance()->update();
        Hanakuso::getInstance()->update();
        
    }
    
    //ゲームオーバーを検知
    if(Config::statusFlag == STATUSFLAG::FAILURE){
        
        
        Config::statusFlag = STATUSFLAG::PREBADEND;
        
        //ゲームオーバー演出メソッドを呼ぶこと
        
    }
    
  
}