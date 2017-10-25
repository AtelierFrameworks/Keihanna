#pragma once
class IceMagic
{
public:
	void setup();
	int update();
	void draw();

	int count;
	int particle;
	int spot[2];
	int plus;
	int dirx;
};

