#include "IceMagic.h"
#include "ofxSPK.h"

ofxSPK::System sys_ice;
ofxSPK::Group group_ice;

ofImage sprite_ice;

//ofxSPK::Modifier rot;

//--------------------------------------------------------------
void IceMagic::setup() {
	// setup pointsprite texture
	// NOTES: the texture size must be Power of Two,
	// and turn off arb texture option while loading

	ofDisableArbTex();
	sprite_ice.load("ice.png");
	ofEnableArbTex();

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);

	sys_ice.setup();

	group_ice.setup(sys_ice);
	group_ice.setColor(ofxSPK::RangeC(ofColor(255, 255), ofColor(255, 255)),
		ofxSPK::RangeC(ofColor(0, 0), ofColor(255, 0)));

	group_ice.setLifeTime(5, 5);//ó±éqÇ™î≠ê∂ÇµÇƒÇ¢ÇÈéûä‘ÇÃîÕàÕ(ç≈è¨éûä‘,ç≈ëÂéûä‘)
	group_ice.setFriction(0.1);


	
	group_ice.setMass(1, 1);


	group_ice.setSize(0, ofxSPK::RangeF(50, 80));//ó±éqÇÃç≈ëÂÇÃëÂÇ´Ç≥
	
	particle = 1500;
	count = 0;
}

//--------------------------------------------------------------
int IceMagic::update() {
	spot[0] = spot[1];
	spot[1] = ofGetMouseX();
	if (spot[0] < spot[1]) {
		plus = ofGetWidth() / 10;
		dirx = 100;
	}
	else if (spot[0]>spot[1]) {
		plus = -ofGetWidth() / 10;
		dirx = -100;
	}
	group_ice.reserve(particle);//ó±éqÇÃî≠ê∂Ç∑ÇÈó 
	//rot.setup(SPK::Vortex::create(SPK::Vector3D(ofGetWidth() / 2, ofGetHeight() / 2),
	//	SPK::Vector3D(0, 1, 0),200,10), group);
	group_ice.emitRandom(5, ofVec3f(ofGetMouseX()+plus, ofGetHeight()/5*3));
	group_ice.setGravity(ofVec3f(dirx, 0, 0));

	sys_ice.update();

	if (count < 180) {
		count++;

	}
	else if (count == 180) {
		particle -= 15;
		if (particle == 0) {
			count = 181;
			return 1;
		}
	}
	return 0;
}

//--------------------------------------------------------------
void IceMagic::draw() {
	ofEnableBlendMode(OF_BLENDMODE_ADD);

	// sys.debugDraw();

	// bind texture, enable point sprite while drawing particles
	sprite_ice.bind();
	ofEnablePointSprites();
	sys_ice.draw();
	ofDisablePointSprites();
	sprite_ice.unbind();
}





