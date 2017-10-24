#include "BallMagic.h"
#include "ofxSPK.h"
#include "ofMain.h"


ofxSPK::System sys;
ofxSPK::Group group;

ofImage sprite;

//ofxSPK::Modifier rot;

void BallMagic::setup(int _color)
{
	//mouse = false;
	//Key = false;
	ofDisableArbTex();

	sprintf(ballTitle, "ball%d.png", _color);
	sprite.load(ballTitle);
	
	ofEnableArbTex();

	
	ofSetVerticalSync(true);
	sys.setup();

	group.setup(sys);
	group.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
		ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

	group.setLifeTime(0.5);
	group.setFriction(0.1);
	group.setSize(0, ofxSPK::RangeF(30, 250));

	group.setGravity(ofVec3f(0, -5, 0));
	group.setMass(0.1, 1);

	//rot.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth() / 2, ofGetHeight() / 2),
		//SPK::Vector3D(0, 1, 0),200,10), group);

	group.reserve(100);
	vx = 0;
	vy = 0;
	mVelocity = ofVec2f(vx, vy);
	x = ofGetMouseX();
		y = ofGetMouseY();
		mPosition = ofVec2f(x, y);
}


int BallMagic::update()
{
	spot[0] = spot[1];
	spot[1] = ofGetMouseX();
	if (spot[0] < spot[1]) {
		bLeft=true;
	}
	else if (spot[0]>spot[1]) {
		bLeft=false;
	}

	group.emitRandom(1, mPosition);
	sys.update();
	
		

		if (bLeft == false) {
			mVelocity.x -= 1;
			mVelocity.y -= 1;
		}
		else if (bLeft == true) {
			mVelocity.x += 1;
			mVelocity.y -= 1;
		}
	
	if (mPosition.x >= ofGetWidth() || mPosition.y >= ofGetHeight()) {
		mPosition.x = 0;
		mPosition.y = 0;
		mVelocity.x = 0;
		mVelocity.y = 0;
	}


	mPosition += mVelocity;
	return 0;
}

void BallMagic::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(255, 0, 0, 255);

	sys.draw();
	
	sprite.bind();
	ofEnablePointSprites();
	ofDisablePointSprites();
	sprite.unbind();
}
