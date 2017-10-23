#pragma once
#include "ofMain.h"
class Animal
{
public:
	void setup(int _tone);
	void update();
	void draw();

	ofImage animal;
	int x = 0, y = 0;
};

