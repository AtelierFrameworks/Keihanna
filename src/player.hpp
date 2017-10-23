//
//  Player.hpp
//  mario
//
//  Created by USER1 on 2017/09/28.
//
//

#ifndef Player_hpp
#define Player_hpp
#include "ofMain.h"
#include <stdio.h>
class Player{
public:
    enum CDirection{RIGHT, LEFT};
    static void init(string filename);
    Player(); //コンストラクタ
    void update(); //update内で呼ぶ関数
    void draw(); //draw内で呼ぶ関数
    void move(CDirection dir); //動かす方向の関数
    
    static ofImage img; //マリオの画像
    static ofMesh mesh; //画像を変形するためのメッシュ
    static int imgW, imgH; //画像のサイズ
    float t; //変形のための変数
    float x,y;
    bool bLeft;
};

#endif
