#pragma once
#include "FireMagic.h"
#include "WindMagic.h"
class MagicBase
{
public:
	void setup(int _tone);
	void update(int _tone);
	void draw(int _tone);

	FireMagic fire;
	WindMagic wind;
};

