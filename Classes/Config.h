//
//  Config.h
//  hanakuso
//
//  Created by yasutomo on 2015/08/19.
//
//

#ifndef hanakuso_Config_h
#define hanakuso_Config_h

//******************ゲーム状態管理*****************

enum class  STATUSFLAG {
    
    //画面遷移後
    PREPARATION,
    //スタート前準備
    PRESTART,
    //スタート
    START,
    //プレイ厨
    PLAY,
    //ポーズ
    PAUSE,
    //ゴール(backGroundが最終地点に到達)
    GOAL,
    //終了
    GOODEND,
    BADEND,
    
    
};



//フラグ
//static gameStatus STATUSFLAG;

//******************ゲーム状態管理終*****************

enum class TAPPOINT {
    NONE,
    RIGHT,
    LEFT
};


//******************タップ状態管理*****************


class Config {

public:
    
    //staticにしたとしても別途cppに記述しないとリンクエラー。。。。
    static STATUSFLAG statusFlag;
    static TAPPOINT tapPoint;


#endif/* defined(__hanakuso__config__) */


};
