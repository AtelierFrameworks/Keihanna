#pragma once
#include "ofMain.h"
class BallMagic
{
public:
	void setup(int _color);
	int update();
	void draw();

	ofVec2f mPosition;
	ofVec2f mVelocity;
	float x;
	float y;
	float vx;
	float vy;
	ofImage sprite;
	int p = 0;
	bool Key;
	bool mouse;
	int spot[2];
	int plus;
	bool bLeft;

	string ballTitle;

};

