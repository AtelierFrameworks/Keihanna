#pragma once
#include "FireMagic.h"
#include "WindMagic.h"
#include "IceMagic.h"
class MagicBase
{
public:
	void setup(int _tone);
	void update(int _tone);
	void draw(int _tone);

	FireMagic fire;
	WindMagic wind;
	IceMagic ice;

	int judge=0;
};

