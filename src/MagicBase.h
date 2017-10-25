#pragma once
#include "FireMagic.h"
#include "WindMagic.h"
#include "IceMagic.h"
#include "BallMagic.h"
class MagicBase
{
public:
	void setup(int _tone);
	void update(int _tone);
	void draw(int _tone);

	FireMagic fire;
	WindMagic wind;
	IceMagic ice;
	BallMagic ball;

	int judge=0;
};

