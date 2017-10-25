#pragma once
#include "ofMain.h"
class Animal
{
public:
	void setup(int _tone);
	void update();
	void draw();

	ofImage animal;
	int x , y=ofGetHeight() /10*9;
    int dir;
    int imgH;
};

