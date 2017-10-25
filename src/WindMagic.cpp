#include "WindMagic.h"
#include "ofxSPK.h"
#include "stdio.h"

ofxSPK::System sys_wind;
ofxSPK::Group group_wind;

ofImage sprite_wind;

ofxSPK::Modifier rot_wind;

//--------------------------------------------------------------
void WindMagic::setup() {
	// setup pointsprite texture
	// NOTES: the texture size must be Power of Two,
	// and turn off arb texture option while loading
	
	ofDisableArbTex();
	sprite_wind.load("wind1.png");
	ofEnableArbTex();

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	sys_wind.setup();

	group_wind.setup(sys_wind);
	group_wind.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
		ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

	group_wind.setLifeTime(0.5, 5);//—±q‚ª”­¶‚µ‚Ä‚¢‚éŠÔ‚Ì”ÍˆÍ(Å¬ŠÔ,Å‘åŠÔ)
	group_wind.setFriction(0.1);


	group_wind.setGravity(ofVec3f(0, -50, 0));
	group_wind.setMass(0.1, 0.1);

	
	group_wind.setSize(0, ofxSPK::RangeF(30, 50));//—±q‚ÌÅ‘å‚Ì‘å‚«‚³
	
	particle = 1000;
	count = 0;

}

//--------------------------------------------------------------
int WindMagic::update() {
	group_wind.reserve(particle);//—±q‚Ì”­¶‚·‚é—Ê
	rot_wind.setup(SPK::Vortex::create(SPK::Vector3D(ofGetMouseX() , ofGetHeight() / 2),
		SPK::Vector3D(0, 1, 0),
		200,
		10), group_wind);
	group_wind.emitRandom(10, ofVec3f(ofGetMouseX()+ofGetWidth()/10, ofGetHeight() / 4 * 3));
	group_wind.emitRandom(10, ofVec3f(ofGetMouseX()-ofGetWidth()/10, ofGetHeight() / 4 * 3));

	sys_wind.update();

	if (count < 180) {
		count++;

	}
	else if (count == 180) {
		particle -= 10;
		if (particle == 0) {
			count = 181;
			return 1;
		}
	}
	return 0;
}

//--------------------------------------------------------------
void WindMagic::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	// sys.debugDraw();

	// bind texture, enable point sprite while drawing particles
	sprite_wind.bind();
	ofEnablePointSprites();
	sys_wind.draw();
	ofDisablePointSprites();
	sprite_wind.unbind();
}



