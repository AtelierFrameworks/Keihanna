#include "Animal.h"


void Animal::setup(int _tone) {
	char title[20];
	sprintf(title, "animal%d.png", _tone/2);
	animal.load(title);
    imgH =animal.getHeight();
    if(_tone<8){
        dir=0;
        x=ofGetWidth();
    }
    else{
        dir=1;
        x=0;
    }
    
}

void Animal::update() {
    if(dir==0){
        x-=1;
    }
    else{
        x+=1;
    }
}
void Animal::draw() {
	animal.draw(x,y-imgH);
}

