#include "GoodEndScene.h"
#include <string.h>

//画面サイズの取得および設定
#define selfFrame Director::getInstance() -> getWinSize()

USING_NS_CC;
//using namespace CocosDenshion;

//保存先の生成
//UserDefault *userDef = UserDefault::getInstance();

//画面生成
Scene *GoodEndScene::createScene(){
    
    auto scene = Scene::create();//WithPhysics();   ←物理設定の場合
    auto layer = GoodEndScene::create();
    layer -> setName("layer");
    scene -> addChild(layer);
    
    
    /* 物理設定
     auto world = scene -> getPhysicsWorld();
     cocos2d::Vect gravity;
     gravity.setPoint(0, -50);
     world -> setGravity(gravity);
     */
    
    //物理体の可視化
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    
    return scene;
    
}

//初期画面作成
bool GoodEndScene::init(){
    
    
    if (!Layer::init()) {
        return false;
    }
    
    //背景色のグラデーション
    auto bgColor = LayerColor::create(Color4B(255,246,213,255));
    this -> addChild(bgColor);
    
    
    /* 効果音の設定
     CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("cursor1.mp3");
     CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("decision7.mp3");
     SimpleAudioEngine::getInstance()->setEffectsVolume(0.6f);
     */
    
    
    /* BGMの設定
     SimpleAudioEngine::getInstance()->playBackgroundMusic("bgmShelling.mp3",true);
     音量
     SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
     */
    
    
    //didsimulate
    this->scheduleUpdate();
    
    
    setNextBt();
    setRetryBt();
    setTopBt();
    
    
    
    
    
    
    /**************　タッチイベント設定  ******************/
    
    //シングルタップ用リスナーを用意する
    auto listener = EventListenerTouchOneByOne::create();
    //listener -> setSwallowTouches(_swallowsTouches);
    
    
    //各イベントの割り当て
    listener -> onTouchBegan = CC_CALLBACK_2(GoodEndScene::onTouchBegan,this);
    listener -> onTouchMoved = CC_CALLBACK_2(GoodEndScene::onTouchMoved,this);
    listener -> onTouchEnded = CC_CALLBACK_2(GoodEndScene::onTouchEnded,this);
    
    //イベントディスパッチャようにリスナーを追加する
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    /*************　　タッチイベント設定  終 ****************/
    
    
    
    //MARK::nendの設定
    //ネンドの呼び出し(ヘッダー)
    /*char apiKey[] = "5aa579f521da85a055c5076641efc68202d5e8e2";
     char spotID[] = "262876";
     NendModule::createNADViewBottom(apiKey, spotID);
     
     //ネンドの呼び出し(飛び出す)
     char interstitialApiKey[] = "6b027f392e0cf11d378908fc4027f1755d6422ad";
     char interstitialSpotID[] = "266067";
     NendInterstitialModule::createNADInterstitial(interstitialApiKey, interstitialSpotID);
     */
    
    
    
    return true;
    
    
}


#pragma mark-
#pragma mark touchBegan

bool GoodEndScene::onTouchBegan(Touch *touch, Event *unused_event){
    
    //タップ開始時の処理
    CCLOG("touchBegan");
    
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
    
    return true;
    
}

#pragma mark-
#pragma mark touchMoved

void GoodEndScene::onTouchMoved(Touch *touch, Event *unused_event){
    
    //スワイプ中の処理
    CCLOG("touchMoved");
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
}


#pragma mark-
#pragma mark touchEnded

void GoodEndScene::onTouchEnded(Touch *touch, Event *unused_event){
    
    //タップ終了時
    CCLOG("touchEnded");
    
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
}



/*
 
 #pragma mark-
 #pragma mark 衝突判定
 bool GoodEndScene::onContactBegin(cocos2d::PhysicsContact& contact){
 
 
 auto nodeA = contact.getShapeA()->getBody()->getNode();
 auto nodeB = contact.getShapeB()->getBody()->getNode();
 
 CCLOG("衝突判定スタート");
 
 return true;
 
 }*/

void GoodEndScene::setNextBt(){
    
    //仮スタートラベル
    auto startBt = Label::createWithSystemFont("次のステージ", "", 15);
    startBt -> setColor(Color3B::BLACK);
    auto startBtTaped = Label::createWithSystemFont("次のステージ", "", 15);
    startBtTaped -> setColor(Color3B::BLACK);
    startBtTaped -> setOpacity(150);
    
    /*
     //スタートボタン作成
     auto startBt = Sprite::create("");
     auto startBtTaped = Sprite::create("");
     startBtTaped -> setOpacity(150);
     */
    
    //メニューアイテムの作成
    auto pBtnItem = MenuItemSprite::create(startBt, startBtTaped, [](Ref *ref){
        
        //ゲームシーンへ画面遷移
        
    });
    
    //メニューの作成　pMenuの中にpBtnItemを入れる
    auto startMenu = Menu::create(pBtnItem, NULL);
    
    //pMenuを画面中央に配置
    startMenu->setPosition(Vec2(selfFrame.width/2, selfFrame.height/2));
    startMenu->setName("start");
    this->addChild(startMenu);
    
}

void GoodEndScene::setRetryBt(){
    
    //仮ランキングラベル
    auto rankingBt = Label::createWithSystemFont("もういちど", "", 15);
    rankingBt -> setColor(Color3B::BLACK);
    auto rankingBtTaped = Label::createWithSystemFont("もういちど", "", 15);
    rankingBtTaped -> setColor(Color3B::BLACK);
    rankingBtTaped -> setOpacity(150);
    
    /*
     //ランキングボタン作成
     auto rankingBt = Sprite::create("");
     auto rankingBtTaped = Sprite::create("");
     rankingBtTaped -> setOpacity(150);
     */
    
    //メニューアイテムの作成
    auto pBtnItem = MenuItemSprite::create(rankingBt, rankingBtTaped, [](Ref *ref){
        
        //ランキングに接続
        
    });
    
    //メニューの作成　pMenuの中にpBtnItemを入れる
    auto startMenu = Menu::create(pBtnItem, NULL);
    
    //pMenuを画面中央に配置
    startMenu->setPosition(Vec2(selfFrame.width/4, selfFrame.height/3));
    startMenu->setName("start");
    this->addChild(startMenu);
    
}

void GoodEndScene::setTopBt(){
    
    //仮チュートリアルラベル
    auto tutorialBt = Label::createWithSystemFont("タイトルへ", "", 15);
    tutorialBt -> setColor(Color3B::BLACK);
    auto tutorialBtTaped = Label::createWithSystemFont("タイトルへ", "", 15);
    tutorialBtTaped -> setColor(Color3B::BLACK);
    tutorialBtTaped -> setOpacity(150);
    
    /*
     //チュートリアルボタン作成
     auto tutorialBt = Sprite::create("");
     auto tutorialBtTaped = Sprite::create("");
     tutorialBtTaped -> setOpacity(150);
     */
    
    //メニューアイテムの作成
    auto pBtnItem = MenuItemSprite::create(tutorialBt, tutorialBtTaped, [](Ref *ref){
        
        //説明画面へ
        
    });
    
    //メニューの作成　pMenuの中にpBtnItemを入れる
    auto startMenu = Menu::create(pBtnItem, NULL);
    
    //pMenuを画面中央に配置
    startMenu->setPosition(Vec2(selfFrame.width*2/3, selfFrame.height*2/3));
    startMenu->setName("start");
    this->addChild(startMenu);
    
}

#pragma mark-
#pragma mark:フレーム管理

void GoodEndScene::update( float frame )
{
    
}
