#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//ofSetFullscreen(true);
	for (int i = 0; i < 10; i++) {
		magic[i].setup(i);
	}
	for (int i = 0; i < 3; i++) {
		sprintf(costume, "atelier%d.png", i);
		atelier[i].init(costume);
	}
	/*
	atelier.init("atelier.png");
	piano.init("piano.png");
	xylophone.init("xylophone.png");
	guitar.init("guitar.png");
	*/
	back.load("background.png");
	sound.setInstrument();

    mArduino.setup();
    ofAddListener(mArduino.mSendEvent, this, &ofApp::receiveData);
}

//--------------------------------------------------------------
void ofApp::update(){
	//bLeft=0@¶Œü‚«@bLeft=1@‰EŒü‚«
	//bLeft=atelier.update();
	/*piano.update();
	xylophone.update();
	guitar.update();
	*/
	
	for (int i = 0; i < 4; i++) {
		atelier[i].update();
	}

    


	
	for (int i = 0; i < 10; i++) {
		magic[i].update(i);
	}
	
	mArduino.update();


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255, 255);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	back.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	
	if (color_data == 4) {
		for (int i = 0; i < 10; i++) {
			magic[i].draw(i);
		}
	}

	ofSetColor(255,255,255,alpha);
	
	switch (color_data) {
	case 0:
		atelier[0].draw();
		break;
	case 1:
		atelier[1].draw();
		break;
	case 2:
		atelier[2].draw();
		break;
	default:
		atelier[3].draw();
		break;
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'q') {
		color_data = 0;
		
	}
	else if (key == 'w') {
		color_data = 1;
	}
	else if (key == 'e') {
		color_data = 2;
	}
	else if (key == 'r') {
		color_data = 3;
	}
	else if (key == 't') {
		color_data = 4;
	}


	if (color_data == 4) {
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
		else if (key == 'f') {
			hall_data = 3;
			magic[3].setup(3);
		}
		else if (key == 'g') {
			hall_data = 4;
			magic[4].setup(4);
		}
		else if (key == 'z') {
			hall_data = 5;
			magic[5].setup(5);
		}
		else if (key == 'x') {
			hall_data = 6;
			magic[6].setup(6);
		}
		else if (key == 'c') {
			hall_data = 7;
			magic[7].setup(7);
		}
		else if (key == 'v') {
			hall_data = 8;
			magic[8].setup(8);
		}
		else if (key == 'b') {
			hall_data = 9;
			magic[9].setup(9);
		}
	}
	else if (color_data == 3) {
		if (key == 'a') {
			hall_data = 0;

		}
		else if (key == 's') {
			hall_data = 1;

		}
		else if (key == 'd') {
			hall_data = 2;

		}
		else if (key == 'f') {
			hall_data = 3;

		}
	}
	
		if (key == 'a') {
			hall_data = 0;
			
		}
		else if (key == 's') {
			hall_data = 1;
			
		}
		else if (key == 'd') {
			hall_data = 2;
			
		}
		else if (key == 'f') {
			hall_data = 3;
		}
		else if (key == 'g') {
			hall_data = 4;
		}
		else if (key == 'z') {
			hall_data = 5;
		}
		else if (key == 'x') {
			hall_data = 6;
		}
		else if (key == 'c') {
			hall_data = 7;
		}
		else if (key == 'v') {
			hall_data = 8;
		}
		else if (key == 'b') {
			hall_data = 9;
		}
		sound.manage(color_data, hall_data);
	

	

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

