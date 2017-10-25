#pragma once
#include "ofMain.h"
#include<stdio.h>

class Player {
public:
	enum CDirection { RIGHT, LEFT };
	void init(string filename);
	Player(); //�R���X�g���N�^
	int update(); //update���ŌĂԊ֐�
	void draw(); //draw���ŌĂԊ֐�
	void move(CDirection dir); //�����������̊֐�
    ofImage img; //�A�g���[�̉摜
    ofMesh mesh; //�摜��ό`���邽�߂̃��b�V��
	static int imgW, imgH; //�摜�̃T�C�Y
	float t; //�ό`�̂��߂̕ϐ�

	float x, y;
	bool bLeft;

	int spot[2] = { 0 ,0 };
};

