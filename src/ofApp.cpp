#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//ofSetFullscreen(true);
	for (int i = 0; i < 10; i++) {
		magic[i].setup(i);
	}
	for (int i = 0; i < 4; i++) {
        char costume[20];
		sprintf(costume, "atelier%d.png", i);
		atelier[i].init(costume);
	}
    for(int j=0;j<10;j++){
        animals[j].setup(j);
    }
   
	/*
	atelier.init("atelier.png");
	piano.init("piano.png");
	xylophone.init("xylophone.png");
	guitar.init("guitar.png");
	*/
	back.load("background.png");
	sound.setInstrument();

    mArduino.setup();
    ofAddListener(mArduino.mSendEvent, this, &ofApp::receiveData);
    setupThunder();
}

void ofApp::setupThunder(){
    kami.load("3.jpg");
    ThunderSound.load("o.mp3");
    ThunderSound.setVolume(0.1f);
    mouse = false;
}

//--------------------------------------------------------------
void ofApp::update(){

	//bLeft=0@¶Œü‚«@bLeft=1@‰EŒü‚«
	//bLeft=atelier.update();
	/*piano.update();
	xylophone.update();
	guitar.update();
	*/
	
	for (int i = 0; i < 4; i++) {
		atelier[i].update();
	}

    

    for (int i = 0; i < 10; i++) {
        animals[i].update();
    }
	
	for (int i = 0; i < 10; i++) {
		magic[i].update(i);
	}
	
	mArduino.update();


}

//--------------------------------------------------------------
void ofApp::draw(){

    if(mouse==true){
        kami.draw(50, 0);
        ThunderSound.play();
        //p=2;
    }
    

	ofSetColor(255, 255, 255, 255);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	back.draw(0, 0, ofGetWidth(), ofGetHeight());
	
    if(color_data==3){
        for(int i=0;i<10;i++){
            animals[i].draw();
        }
    }
    
	if (color_data == 4) {
		for (int i = 0; i < 10; i++) {
			magic[i].draw(i);
		}
	}
    

	ofSetColor(255,255,255,alpha);
	
	switch (color_data) {
	case 0:
		atelier[0].draw();
		break;
	case 1:
		atelier[1].draw();
		break;
	case 2:
		atelier[2].draw();
		break;
	default:
		atelier[3].draw();
		break;
	}
    
//    for(int i = 0; i<4;i++){
//        atelier[i].draw();
//    }
//    atelier[1].draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'q') {
		color_data = 0;
		
	}
	else if (key == 'w') {
		color_data = 1;
	}
	else if (key == 'e') {
		color_data = 2;
	}
	else if (key == 'r') {
		color_data = 3;
	}
	else if (key == 't') {
		color_data = 4;
	}


	if (color_data == 4) {
		if (key == 'a') {
			hall_data = 0;
			magic[0].setup(0);
		}
		else if(key=='s'){
			hall_data = 1;
			magic[1].setup(1);
		}
		else if (key == 'd') {
			hall_data = 2;
			magic[2].setup(2);
		}
		else if (key == 'f') {
			hall_data = 3;
			magic[3].setup(3);
		}
		else if (key == 'g') {
			hall_data = 4;
			magic[4].setup(4);
		}
		else if (key == 'z') {
			hall_data = 5;
			magic[5].setup(5);
		}
		else if (key == 'x') {
			hall_data = 6;
			magic[6].setup(6);
		}
		else if (key == 'c') {
			hall_data = 7;
			magic[7].setup(7);
		}
		else if (key == 'v') {
			hall_data = 8;
			magic[8].setup(8);
		}
		else if (key == 'b') {
			hall_data = 9;
			magic[9].setup(9);
		}
	}
	else if (color_data == 3) {
		if (key == 'a') {
			hall_data = 0;
            animals[0].setup(0);
		}
		else if (key == 's') {
			hall_data = 1;
            animals[1].setup(1);
		}
		else if (key == 'd') {
			hall_data = 2;
            animals[2].setup(2);
		}
		else if (key == 'f') {
			hall_data = 3;
            animals[3].setup(3);
		}
        else if (key == 'g') {
            hall_data = 4;
            animals[4].setup(4);
        }
        else if (key == 'z') {
            hall_data = 5;
            animals[5].setup(5);
        }
        else if (key == 'x') {
            hall_data = 6;
            animals[6].setup(6);
        }
        else if (key == 'c') {
            hall_data = 7;
            animals[7].setup(7);
        }
        else if (key == 'v') {
            hall_data = 8;
            animals[8].setup(8);
        }
        else if (key == 'b') {
            hall_data = 9;
            animals[9].setup(9);
        }
        
	}
	
		if (key == 'a') {
			hall_data = 0;
			
		}
		else if (key == 's') {
			hall_data = 1;
			
		}
		else if (key == 'd') {
			hall_data = 2;
			
		}
		else if (key == 'f') {
			hall_data = 3;
		}
		else if (key == 'g') {
			hall_data = 4;
		}
		else if (key == 'z') {
			hall_data = 5;
		}
		else if (key == 'x') {
			hall_data = 6;
		}
		else if (key == 'c') {
			hall_data = 7;
		}
		else if (key == 'v') {
			hall_data = 8;
		}
		else if (key == 'b') {
			hall_data = 9;
		}
		sound.manage(color_data, hall_data);
	


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



void ofApp:: receiveData(std::vector<CONST::E_SENSOR> & isActionSensor){
    ofLogNotice() << "Recieve!" << 0;
    for(CONST::E_SENSOR sensor:isActionSensor){
        ofLogNotice() << "RecieveData" << sensor;
    
    
    switch(sensor){
        case CONST::H1:
            hall_data=0;
            if(color_data==3){
                animals[0].setup(0);
            }
            else if(color_data==4){
                magic[0].setup(0);
            }
            else{
                sound.manage(color_data,hall_data);
            }
            break;
        case CONST::H2:
            hall_data=1;
            if(color_data==3){
                animals[1].setup(1);
            }
            else if(color_data==4){
                magic[1].setup(1);
            }
            else{
                sound.manage(color_data,hall_data);
            }
            break;
        case CONST::H3:
            hall_data=2;
            if(color_data==3){
                animals[2].setup(2);
            }
            else if(color_data==4){
                magic[2].setup(2);
            }
            else{
                sound.manage(color_data,hall_data);
            }
            break;
        case CONST::H4:
            hall_data=3;
            if(color_data==3){
                animals[3].setup(3);
            }
            else if(color_data==4){
                magic[3].setup(3);
            }
            else{
                sound.manage(color_data,hall_data);
            }
            break;
        case CONST::H5:
            hall_data=4;
            if(color_data==3){
                animals[4].setup(4);
            }
            else if(color_data==4){
                magic[4].setup(4);
            }
            else{
                sound.manage(color_data,hall_data);
            }

            break;
        case CONST::H6:
            hall_data=5;
            if(color_data==3){
                animals[5].setup(5);
            }
            else if(color_data==4){
                magic[5].setup(5);
            }
            else{
                sound.manage(color_data,hall_data);
            }

            break;
        case CONST::H7:
            hall_data=6;
            if(color_data==3){
                animals[6].setup(6);
            }
            else if(color_data==4){
                magic[6].setup(6);
            }
            else{
                sound.manage(color_data,hall_data);
            }

            break;
        case CONST::H8:
            hall_data=7;
            if(color_data==3){
                animals[7].setup(7);
            }
            else if(color_data==4){
                magic[7].setup(7);
            }
            else{
                sound.manage(color_data,hall_data);
            }

            break;
        case CONST::H9:
            hall_data=8;
            if(color_data==3){
                animals[8].setup(8);
            }
            else if(color_data==4){
                magic[8].setup(8);
            }
            else{
                sound.manage(color_data,hall_data);
            }

            break;
        case CONST::H10:
            hall_data=9;
            if(color_data==3){
                animals[9].setup(9);
            }
            else if(color_data==4){
                magic[9].setup(9);
            }
            else{
                sound.manage(color_data,hall_data);
            }

            break;
        case CONST::C_RED:
            color_data=0;
            break;
        case CONST:: C_GREEN:
            color_data=2;
            break;
        case CONST :: C_BLUE:
            color_data=3;
            break;
        case CONST:: C_YELLOW:
            color_data=1;
            break;
        case CONST::C_PINK:
            color_data=4
            break;
        case CONST::C_NONE:
            break;
        default: break;
    }
    }
    

}


