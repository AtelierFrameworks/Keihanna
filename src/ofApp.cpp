#include "ofApp.h"
#include "ofxSPK.h"
#include "Player.hpp"

ofxSPK::System sys;
ofxSPK::Group group;

ofImage sprite;

ofxSPK::Modifier rot;

//--------------------------------------------------------------
void ofApp::setup(){
    mouse = false;
    Key = false;
    AT.init("at.png");
    AT.move(Player::RIGHT);
    ofDisableArbTex();
    sprite.load("image2.png");
    ofEnableArbTex();
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    sys.setup();
    
    group.setup(sys);
    group.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
                   ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));
    
    group.setLifeTime(0.5);
    group.setFriction(0.1);
    group.setSize(0, ofxSPK::RangeF(30, 250));
    
    group.setGravity(ofVec3f(0, -5, 0));
    group.setMass(0.1, 1);
    
    rot.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth() / 2, ofGetHeight() / 2),
                                  SPK::Vector3D(0, 1, 0),
                                  200,
                                  10), group);
    
    group.reserve(10000);
    vx = 0;
    vy = 0;
    mVelocity = ofVec2f(vx, vy);
}

//--------------------------------------------------------------
void ofApp::update(){
    AT.update();
    group.emitRandom(1, mPosition);
    sys.update();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    if (mouse == true) {
        x = ofGetMouseX();
        y = ofGetMouseY();
        mPosition = ofVec2f(x, y);
    
        if (AT.bLeft==true) {
            mVelocity.x -= 1;
            mVelocity.y -= 1;
            
        }
        else if (AT.bLeft==false) {
            mVelocity.x += 1;
            mVelocity.y -= 1;
        }
            }
    if(mPosition.x>=1024|| mPosition.y>= 768 ){
        mPosition.x= 0;
        mPosition.y= 0;
        mVelocity.x = 0;
        mVelocity.y = 0;
    }

    
    mPosition += mVelocity;
}

//--------------------------------------------------------------
void ofApp::draw(){
    AT.draw();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    if(p==1){
    sys.draw();
    }
    sprite.bind();
    ofEnablePointSprites();
    ofDisablePointSprites();
    sprite.unbind();}

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
    p=1;
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
