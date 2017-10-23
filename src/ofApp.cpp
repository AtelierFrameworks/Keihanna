#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    hibi1.load("1-1.png");
    hibi2.load("1-2.png");
    hibi3.load("1-3.png");
    hibi4.load("1-4.png");
    
    mySound.loadSound("glass-break2.mp3");
    mySound.setLoop(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(p==1){
        hibi1.draw(0,0);
    }else if(p==2){
        hibi2.draw(0,0);
    }else if(p==3){
        hibi3.draw(0,0);
    }else if(p==4){
        hibi4.draw(0,0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        p=1;
        mySound.play();
    }else if(key == 's'){
        p=2;
        mySound.play();
    }else if(key == 'z'){
        p=3;
        mySound.play();
    }else if(key == 'x'){
        p=4;
        mySound.play();
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
