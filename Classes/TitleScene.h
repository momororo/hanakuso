#include "cocos2d.h"
//#include "TutorialScene.h"
//#include "GameCenterBridge.h"

class TitleScene : public cocos2d::Layer
{
    
protected:
    
    //1フレームごとに呼ばれる。
    void update(float frame );
    
public:
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
    
    //タップイベントの宣言
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    
    //衝突イベント
    //bool onContactBegin(cocos2d::PhysicsContact& contact);

    //配列を使う場合
    //cocos2d::Vector<cocos2d::Sprite*>dropVector = cocos2d::Vector<cocos2d::Sprite*>();
    
    //AppCCloudの広告用
    //void setAppCCloud();
    //void removeAppCCloud();
    
    void setStartBt();
    void setRankingBt();
    void setTutorialBt();
    void setTwitterBt();
    void setFacebookBt();
};