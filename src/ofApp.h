#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Sound.h"
#include "MagicBase.h"
#include "ArduinoManager.h" 


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

		void receiveData(std::vector<CONST::E_SENSOR> & isActionSensor);


		ofImage back;
		Player atelier[4];
		char costume[20];
		/*Player piano;
		Player xylophone;
		Player guitar;*/
		Sound sound;
		MagicBase magic[10];

		int color_data = 0,hall_data=1;
		
		int bLeft=0;

		
		int alpha=255;

		ArduinoManager mArduino;
};
