#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    kami.load("1.jpg");
    back.load("BackGround.jpg");
    mySound.loadSound("o.mp3");
    ofBackground(0, 0, 0);
    mouse = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(mouse==true){
        kami.draw(50, 0);
        mySound.play();
        //p=2;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
    mouse=true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse=false;

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
