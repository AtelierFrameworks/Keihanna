#include "MagicBase.h"
#include "ofMain.h"


void MagicBase::setup(int _tone){
	switch (_tone) {
	case 0:
		fire.setup();
		break;
	case 1:
		ball.setup(0);
		break;
	case 2:
		wind.setup();
		break;
	case 3:
		ball.setup(1);
		break;
	case 4:
		ice.setup();
		break;
	case 5:
		ball.setup(2);
		break;
	case 6:
		//kaminari.setup();
		break;
	case 7:
		ball.setup(3);
		break;
	case 8:
		//hibi.setup();
		break;
	case 9:
		ball.setup(4);
		break;
	}
}

void MagicBase::update(int _tone) {
	switch (_tone) {
	case 0:
		fire.update();
		break;
	case 1:
		ball.update();
		break;
	case 2:
		wind.update();
		break;
	case 3:
		ball.update();
		break;
	case 4:
		ice.update();
		break;
	case 5:
		ball.update();
		break;
	case 6:
		//kaminari.update();
		break;
	case 7:
		ball.update();
		break;
	case 8:
		//hibi.update();
		break;
	case 9:
		ball.update();
		break;
	}
}

void MagicBase::draw(int _tone) {
	switch (_tone) {
	case 0:
		fire.draw();
		break;
	case 1:
		ball.draw();
		break;
	case 2:
		wind.draw();
		break;
	case 3:
		ball.draw();
		break;
	case 4:
		ice.draw();
		break;
	case 5:
		ball.draw();
		break;
	case 6:
		//kaminari.draw();
		break;
	case 7:
		ball.draw();
		break;
	case 8:
		//hibi.draw();
		break;
	case 9:
		ball.draw();
		break;
	}
}


