#include "Animal.h"


void Animal::setup(int _tone) {
	char title[10];
	sprintf(title, "animal%d", _tone);
	animal.load(title);
}

void Animal::update() {
	x = 0;
	y = 0;
}
void Animal::draw() {
	animal.draw(x,y);
}

