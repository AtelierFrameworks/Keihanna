#include "Player.h"



ofImage Player::img;
ofMesh Player::mesh;
int Player::imgW;
int Player::imgH;

void Player::init(string filename) {
	img.load(filename);
	imgW = img.getWidth();//画像の横幅
	imgH = img.getHeight();//画像の高さ
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	for (int y = 0; y<imgH; ++y) {
		mesh.addVertex(ofPoint(0, y));
		mesh.addVertex(ofPoint(imgW, y));

		mesh.addTexCoord(ofPoint(0, y));
		mesh.addTexCoord(ofPoint(imgW, y));
	}
}

Player::Player() {

	t = -1;
	bLeft = false;
}

int Player::update() {
	x =  ofGetMouseX();
	y =  ofGetMouseY();
	int MAXY = ofGetHeight()/100*68;
	int MinY = ofGetHeight()/100*77;
	if (y < MAXY)y = MAXY;
	else if (y > MinY)y = MinY;


	if (bLeft) {
		t += 0.02; //左向きならtを増やす
	}
	else {
		t -= 0.02; //右向きならtを減らす
	}
	// tは-1〜2の間
	if (t>2) t = 2;
	else if (t<-1) t = -1;

	//アトリーの向きの判別
	spot[0] = spot[1];
	spot[1] = x;
	if (spot[0] < spot[1]) {
		move(RIGHT);
	}
	else if (spot[0]>spot[1]) {
		move(LEFT);
	}

	if (bLeft) {
		return 0;
	}
	else {
		return 1;
	}

}

void Player::draw() {


	for (int y = 0; y<imgH; ++y) {
		//頂点の移動先を計算
		int convert_x = (int)(sin(TWO_PI / 4 * MAX(-1, MIN(1, t - (float)y / imgH)))*(-imgW / 2) + imgW / 2); //画像の左側の点
		int convert_x2 = (int)(sin(TWO_PI / 4 * MAX(-1, MIN(1, t - (float)y / imgH)))*imgW / 2 + imgW / 2); //画像の右側の点


		 //メッシュの頂点を移動
		mesh.setVertex(2 * y, ofPoint(convert_x, y)); //左側の点
		mesh.setVertex(2 * y + 1, ofPoint(convert_x2, y)); //右側の点
	}

	ofPushMatrix();
	ofTranslate(x - imgW / 2,  y - imgH / 2);
	img.bind();
	mesh.draw();
	img.unbind();
	ofPopMatrix();
}

void Player::move(CDirection dir) {
	if (dir == LEFT) bLeft = true;
	else if (dir == RIGHT) bLeft = false;
}

