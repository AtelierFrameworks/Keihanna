#include "MagicBase.h"
#include "ofMain.h"


void MagicBase::setup(int _tone){
	switch (_tone) {
	case 0:
		//FireMagic *fire;
		//fire = new FireMagic;
		fire.setup();
		break;
	case 1:
		wind.setup();
		break;
	case 2:
		ice.setup();
		break;
	}
}

void MagicBase::update(int _tone) {
	switch (_tone) {
	case 0:
		judge=fire.update();
		if (judge == 1) {
			//delete  fire;
		}
		break;
	case 1:
		wind.update();
		break;
	case 2:
		ice.update();
		break;
	}
}

void MagicBase::draw(int _tone) {
	switch (_tone) {
	case 0:
		fire.draw();
		break;
	case 1:
		wind.draw();
		break;
	case 2:
		ice.draw();
		break;
	}
}


