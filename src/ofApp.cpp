#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//ofSetFullscreen(true);
	for (int i = 0; i < 10; i++) {
		magic[i].setup(i);
	}
	atelier.init("atelier.png");
	back.load("background.png");
	sound.setInstrument();

	zou.load("elephant.png");
	tori.load("ugu.png");
    mArduino.setup();
    ofAddListener(mArduino.mSendEvent, this, &ofApp::receiveData);
}

//--------------------------------------------------------------
void ofApp::update(){
	//bLeft=0　左向き　bLeft=1　右向き
	bLeft=atelier.update();

	if (color_data == 1) {
		for (int i = 0; i < 10; i++) {
			magic[i].update(i);
		}
	}
    
    mArduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	back.draw(0, 0, ofGetWidth(), ofGetHeight());
	atelier.draw();
	zou.draw(1200, 470);
	tori.draw(1300, 820);
	if (color_data == 1) {
		for (int i = 0; i < 10; i++) {
			magic[i].draw(i);
		}
	}


	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (color_data == 1) {
		if (key == 'a') {
			hall_data = 0;
			magic[0].setup(0);
		}
		else if(key=='s'){
			hall_data = 1;
			magic[1].setup(1);
		}
		else if (key == 'd') {
			hall_data = 2;
			magic[2].setup(2);
		}
	}

	

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp:: receiveData(std::vector<CONST::E_SENSOR> & isActionSensor){
    ofLogNotice() << "Recieve!" << 0;
    for(CONST::E_SENSOR sensor:isActionSensor){
        ofLogNotice() << "RecieveData" << sensor;
    
    
    switch(sensor){
        case CONST::H1:
            break;
        case CONST::H2:
            break;
        case CONST::H3:
            break;
        case CONST::H4:
            break;
        case CONST::H5:
            break;
        case CONST::H6:
            break;
        case CONST::H7:
            break;
        case CONST::H8:
            break;
        case CONST::H9:
            break;
        case CONST::H10:
            break;
        case CONST::C_RED:
            break;
        case CONST:: C_GREEN:
            break;
        case CONST :: C_BLUE:
            break;
        case CONST:: C_YELLOW:
            break;
        case CONST::C_PINK:
            break;
        case CONST::C_NONE:
            break;
        default: break;
    }
    }
    
}

