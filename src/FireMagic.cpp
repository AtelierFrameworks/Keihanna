#include "FireMagic.h"
#include "ofxSPK.h"

ofxSPK::System sys_fire;
ofxSPK::Group group_fire;

ofImage sprite_fire;

ofxSPK::Modifier rot_fire;

//--------------------------------------------------------------
void FireMagic::setup() {
	// setup pointsprite texture
	// NOTES: the texture size must be Power of Two,
	// and turn off arb texture option while loading
	ofDisableArbTex();
	sprite_fire.load("fire1.png");
	ofEnableArbTex();

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	sys_fire.setup();

	group_fire.setup(sys_fire);
	group_fire.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
		ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

	group_fire.setLifeTime(0.5, 15);//粒子が発生している時間の範囲(最小時間,最大時間)
	group_fire.setFriction(0.1);


	group_fire.setGravity(ofVec3f(0, -100, 0));
	group_fire.setMass(0.4, 0.6);

	group_fire.reserve(particle);//粒子の発生する量

	group_fire.setSize(0, ofxSPK::RangeF(50, 60));//粒子の最大の大きさ

	particle = 1000;
	count = 0;
}

//--------------------------------------------------------------
int FireMagic::update() {
	spot[0] = spot[1];
	spot[1] = ofGetMouseX();
	if (spot[0] < spot[1]) {
		plus = ofGetWidth() / 5;
	}
	else if (spot[0] > spot[1]) {
		plus = -ofGetWidth() / 5;
	}



	group_fire.reserve(particle);//粒子の発生する量
	rot_fire.setup(SPK::Vortex::create(SPK::Vector3D(ofGetMouseX() + plus, ofGetHeight() / 2),
		SPK::Vector3D(0, 1, 0),
		200,
		10), group_fire);
	group_fire.emitRandom(10, ofVec3f(100 * sin(15 * ofGetElapsedTimef()) + ofGetMouseX() + plus, ofGetHeight() / 4 * 3));

	sys_fire.update();
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
void FireMagic::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	// sys.debugDraw();

	// bind texture, enable point sprite while drawing particles
	sprite_fire.bind();
	ofEnablePointSprites();
	sys_fire.draw();
	ofDisablePointSprites();
	sprite_fire.unbind();
}

