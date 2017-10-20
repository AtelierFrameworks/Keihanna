#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Sound.h"
#include "MagicBase.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage back;
		Player atelier;
		Sound sound;
		MagicBase magic[10];

		int color_data=1, hall_data=0;
		bool hall_sensor;
		
};
