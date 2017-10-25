#pragma once
#include "ofMain.h"
#include<stdio.h>

class Player {
public:
	enum CDirection { RIGHT, LEFT };
	void init(string filename);
	Player(); //コンストラクタ
	int update(); //update内で呼ぶ関数
	void draw(); //draw内で呼ぶ関数
	void move(CDirection dir); //動かす方向の関数
    ofImage img; //アトリーの画像
    ofMesh mesh; //画像を変形するためのメッシュ
	static int imgW, imgH; //画像のサイズ
	float t; //変形のための変数

	float x, y;
	bool bLeft;

	int spot[2] = { 0 ,0 };
};

