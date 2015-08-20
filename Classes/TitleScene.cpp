#include "TitleScene.h"
#include <string.h>
#include "NativeLauncher.h"
//#include "NendModule.h"
//#include "NendInterstitialModule.h"
//#include "AppCCloudPlugin.h"

//画面サイズの取得および設定
#define selfFrame Director::getInstance() -> getWinSize()

USING_NS_CC;
//using namespace CocosDenshion;

//保存先の生成
//UserDefault *userDef = UserDefault::getInstance();

//画面生成
Scene *TitleScene::createScene(){
    
    auto scene = Scene::create();//WithPhysics();   ←物理設定の場合
    auto layer = TitleScene::create();
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
bool TitleScene::init(){
    
    
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
    
    //MARK::ゲームセンターログイン
    //GameCenterBridge::loginGameCenter();
    
    setStartBt();
    setRankingBt();
    setTutorialBt();
    setTwitterBt();


    
    
    
    /**************　タッチイベント設定  ******************/
    
    //シングルタップ用リスナーを用意する
    auto listener = EventListenerTouchOneByOne::create();
    //listener -> setSwallowTouches(_swallowsTouches);
    
    
    //各イベントの割り当て
    listener -> onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan,this);
    listener -> onTouchMoved = CC_CALLBACK_2(TitleScene::onTouchMoved,this);
    listener -> onTouchEnded = CC_CALLBACK_2(TitleScene::onTouchEnded,this);
    
    //イベントディスパッチャようにリスナーを追加する
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    /*************　　タッチイベント設定  終 ****************/
    
    /*************　  衝突イベント設定   ****************/
    /*
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener -> onContactBegin = CC_CALLBACK_1(TitleScene::onContactBegin,this);
    
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(contactListener,this);
    */
    /*************　  衝突イベント設定  終 ****************/
    
    
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

//MARK::AppCCloudの設定と削除
/*
void TitleScene::setAppCCloud(){
    
    appCCloudBt = Sprite::create("other.png");
    appCCloudBt -> setPosition(Vec2((selfFrame.width)-(appCCloudBt->getContentSize().width*2/3),(selfFrame.height)-(appCCloudBt->getContentSize().height*2/3)));
    this -> addChild(appCCloudBt);
    
    appFlag = true;

}

void TitleScene::removeAppCCloud(){
    
    appCCloudBt -> removeFromParent();
    
    appFlag = false;

}
*/


#pragma mark-
#pragma mark touchBegan

bool TitleScene::onTouchBegan(Touch *touch, Event *unused_event){
    
    //タップ開始時の処理
    CCLOG("touchBegan");
    
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);

    
    return true;
    
}

#pragma mark-
#pragma mark touchMoved

void TitleScene::onTouchMoved(Touch *touch, Event *unused_event){
    
    //スワイプ中の処理
    CCLOG("touchMoved");
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
}


#pragma mark-
#pragma mark touchEnded

void TitleScene::onTouchEnded(Touch *touch, Event *unused_event){
    
    //タップ終了時
    CCLOG("touchEnded");
    
    Point touchPoint = Vec2(touch->getLocation().x,touch->getLocation().y);
    
}



/*

#pragma mark-
#pragma mark 衝突判定
bool TitleScene::onContactBegin(cocos2d::PhysicsContact& contact){
    
    
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    
    CCLOG("衝突判定スタート");
    
    return true;

}*/

void TitleScene::setStartBt(){

    //仮スタートラベル
    auto startBt = Label::createWithSystemFont("スタート", "", 15);
    startBt -> setColor(Color3B::BLACK);
    auto startBtTaped = Label::createWithSystemFont("スタート", "", 15);
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

void TitleScene::setRankingBt(){
    
    //仮ランキングラベル
    auto rankingBt = Label::createWithSystemFont("ランキング", "", 15);
    rankingBt -> setColor(Color3B::BLACK);
    auto rankingBtTaped = Label::createWithSystemFont("ランキング", "", 15);
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
    startMenu->setPosition(Vec2(selfFrame.width/3, selfFrame.height/3));
    startMenu->setName("start");
    this->addChild(startMenu);

}

void TitleScene::setTutorialBt(){
    
    //仮チュートリアルラベル
    auto tutorialBt = Label::createWithSystemFont("遊び方", "", 15);
    tutorialBt -> setColor(Color3B::BLACK);
    auto tutorialBtTaped = Label::createWithSystemFont("遊び方", "", 15);
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

//MARK::ツイッターボタン
void TitleScene::setTwitterBt(){
    
    /*
    //ツイッターボタン作成
    auto twitterBt = Sprite::create("twitterBt.png");
    
    auto twitterBtTaped = Sprite::create("twitterBt.png");
    twitterBtTaped -> setOpacity(150);
    */
    
    //仮Twitterボタン
    auto twitterBt = Label::createWithSystemFont("ついったー", "", 15);
    twitterBt -> setColor(Color3B::BLACK);
    auto twitterBtTaped = Label::createWithSystemFont("ついったー", "", 15);
    twitterBtTaped -> setOpacity(150);
    twitterBtTaped -> setColor(Color3B::BLACK);
    
    
    
    //メニューアイテムの作成
    auto pBtnItem = MenuItemSprite::create(twitterBt, twitterBtTaped, [](Ref *ref){
        
        //ボタン効果音
        //SimpleAudioEngine::getInstance()->playEffect("button70.mp3");
        
        /*
        //呟き回数をカウント
        auto userDef = UserDefault::getInstance();
        userDef->setIntegerForKey("twitterCount",(userDef->getIntegerForKey("twitterCount") + 1));
        
        //ポイントの読込
        userDef = UserDefault::getInstance();
        auto totalPoint = userDef -> getIntegerForKey("playPoint");
        */
        
        
        utils::captureScreen([](bool succeed,const std::string &fileName) {
            
            if (succeed) {
                // 撮影完了したのでここで処理
                //言語の取得
                LanguageType lang = Application::getInstance()->getCurrentLanguage();
                
                std::string text;
                
                //日本語の場合は日本語の説明文を、それ以外は英語
                if(lang == LanguageType::JAPANESE){
                    
                    text = StringUtils::format("あははは");
                    //テキスト作成
                    //text = StringUtils::format("現在のポイント：%d点\n【iPhoneアプリ】魔女ムズ\n#魔女ムズ",totalPoint);
                }else{
                    // text = StringUtils::format("TotalPoints：%dpt\n【iPhone apps】Witch's delivery\n#Witch's delivery",totalPoint);
                    text = StringUtils::format("ahahaha");
                }
                
                NativeLauncher::openTweetDialog(text.c_str(), fileName.c_str());

            } else {
                // 撮影失敗
            }
            
        }, "screen_schott.jpg");
        
    });
    
    //メニューの作成
    auto twitterMenu = Menu::create(pBtnItem, NULL);
    
    //Menuを画面中央に配置
    twitterMenu->setPosition(Vec2(selfFrame.width/2, selfFrame.height/3));
    twitterMenu->setName("twitter");
    this->addChild(twitterMenu);
    
}


#pragma mark-
#pragma mark:フレーム管理

void TitleScene::update( float frame )
{
    
}
