#pragma once

#ifndef ArduinoManager_h

#define ArduinoManager_h



#include <stdio.h>

#include "ofMain.h"

#include "CONST.h"

#include <vector>

#endif /* ArduinoManager_hpp */

class ArduinoManager {

public:

	void setup();

	void update();

	void draw();

	bool getIsSetup();

	void separateBytes();

	void judgeData();

	ofSerial mSerial;

	int nBytesRead = 0;

	string mBytesReadString;

	std::vector<int> mValue;

	bool mHasData;

	bool mHasColorData;

	ofEvent<std::vector<CONST::E_SENSOR>> mSendEvent;

	ofFile mLogDataFile;

};
