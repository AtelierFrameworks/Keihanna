//
//  Player.cpp
//  mario
//
//  Created by USER1 on 2017/09/28.
//
//

#include "Player.hpp"
ofImage Player::img;
ofMesh Player::mesh;
int Player::imgW;
int Player::imgH;

void Player::init(string filename){
    img.load(filename);
    imgW = img.getWidth();
    imgH = img.getHeight();
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(int y=0; y<imgH; y++){
        mesh.addVertex(ofPoint(0,y));
        mesh.addVertex(ofPoint(imgW,y));
        
        mesh.addTexCoord(ofPoint(0,y));
        mesh.addTexCoord(ofPoint(imgW,y));
    }
}

Player::Player(){
    x=40;
    y=ofGetHeight()-368;
    t = -1;
    bLeft = true;
}

void Player::update(){
    if(bLeft){
        t += 0.1; //左向きならtを増やす
        x-=4;
        
    }
    else{
        t -= 0.1; //右向きならtを減らす
        x+=4;
        
    }
    //ofLogNotice() << "x: " << x;
    // tは-1〜2の間
    if(t>2) t = 2;
    else if(t<-1) t = -1;
    
    if(bLeft&&x<0){
        move(RIGHT);
    }else if(!bLeft && x > ofGetWidth())
    {
        move(LEFT);
    }
}

void Player::draw(){
    
    for (int y=0; y<imgH; ++y) {
        //頂点の移動先を計算
        int convert_x = (int)(sin(PI/2*MAX(-1,MIN(1,t-(float)y/imgH)))*(-imgW/2)+imgW/2); //画像の左側の点
        int convert_x2 = (int)(sin(PI/2*MAX(-1,MIN(1,t-(float)y/imgH)))*imgW/2+imgW/2); //画像の右側の点
        
        //メッシュの頂点を移動
        mesh.setVertex(2*y, ofPoint(convert_x,y)); //左側の点
        mesh.setVertex(2*y+1, ofPoint(convert_x2,y)); //右側の点
    }
    
    ofPushMatrix();
//    ofTranslate(x-imgW/2,y-imgH/2);
    ofTranslate(x-imgW/2,ofGetHeight() - 368);
    img.bind();
    mesh.draw();
    img.unbind();
    ofPopMatrix();
}

void Player::move(CDirection dir){
    //    img.mirror(false, true);
    if(dir == LEFT) bLeft = true;
    else if(dir == RIGHT) bLeft = false;
}
