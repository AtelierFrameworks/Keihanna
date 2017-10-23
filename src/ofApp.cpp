#include "ofApp.h"
#include "ofxSPK.h"
#include "Player.hpp"

ofxSPK::System sys;
ofxSPK::Group group;

ofImage sprite;

ofxSPK::Modifier rot;

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

}

//--------------------------------------------------------------
void ofApp::update(){

	//bLeft=0@¶Œü‚«@bLeft=1@‰EŒü‚«
	bLeft=atelier.update();

	if (color_data == 1) {
		for (int i = 0; i < 10; i++) {
			magic[i].update(i);
		}
	}

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
