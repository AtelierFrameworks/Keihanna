//
//  ArduinoManager.cpp
//  Keihanna
//
//  Created by 池上綾乃 on 2017/10/24.
//
//

#include "ArduinoManager.hpp"

void ArduinoManager::setup(){
    mSerial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = mSerial.getDeviceList();
    mSerial.setup(1,9600);
    mValue.clear();
    mHasData = false;
    mHasColorData = false;
}

void ArduinoManager::update(){
    int nRead = 0;
    char bytesRead[50];
    unsigned char bytesReturned[50];
    
    memset(bytesReturned, 0, 50);
    
    if(mSerial.isInitialized()){
        if(mSerial.available() > 0){
            int available = mSerial.available();
            ofLogNotice() << "available" << mSerial.available();
            while ((nRead = mSerial.readBytes(bytesReturned, 50)) > 0) {
                nBytesRead = nRead;
                ofLogNotice() << "nRead" << nRead;
                
                mBytesReadString = string((char*)bytesReturned);
                ofLogNotice() << "value" <<  bytesReturned;
                separateBytes();
            };
            //            mSerial.flush();
            
        }
    }
    
}

void ArduinoManager::separateBytes(){
    std::vector<string> result = ofSplitString(mBytesReadString, ",");
    
    for (string stringData:result) {
        
        if(stringData=="{"){
            mHasData = true;
            
            mValue.clear();
            
        }else if(stringData == "}" && mHasData){
            judgeData();
            mHasData = false;
        }else if(stringData == "[" ){
            mHasColorData = true;
        }else if(stringData == "]"){
            mHasColorData = false;
        }else{
            if(stringData !="" && mHasData){
                try{
                    ofLogNotice() << "data" << stringData;
                    int data = std::stoi(stringData);
                    if(mHasColorData){
                        data += 100;
                    }
                    mValue.push_back(data);
                }catch(const invalid_argument& e){
                    
                    ofLogNotice() << "error" << stringData;
                    if(stringData == "}0" || stringData == "}1"){
                        judgeData();
                        mValue.clear();
                        std::vector<string> errorData = ofSplitString(stringData, "}");
                        try{
                            mValue.push_back(std::stoi(errorData.at(0)));
                        }catch(const invalid_argument& a){
                            
                        }
                    }
                }
            }
            
        }
    }
}



bool ArduinoManager::getIsSetup(){
    return mSerial.isInitialized();
}

void ArduinoManager:: judgeData(){
    ofLogNotice() << "judge" << mValue.size() ;
    std::vector <CONST::E_SENSOR> isActionSensor;
    for(int data :mValue){
        CONST::E_SENSOR sensor;
        bool isPush = false;
        //color
        if(data >= 100){
            data -= 100;
            isPush = true;
            switch (data) {
                case 1:
                    sensor = CONST::C_RED;
                    break;
                case 2:
                    sensor = CONST::C_GREEN;
                    break;
                case 3:
                    sensor = CONST::C_BLUE;
                    break;
                case 4:
                    sensor = CONST::C_YELLOW;
                    break;
                case 5:
                    sensor = CONST::C_PINK;
                    break;
                default:
                    sensor = CONST::C_NONE;
                    break;
            }
        }else{
            //hall
        int modData = data % 2;
            //反応あるかどうか
            if(modData == 0){
                isPush = true;
                data = data / 2 -1;
                sensor = (CONST::E_SENSOR)data;
            }
        }
        
        if(isPush){
            isActionSensor.push_back(sensor);
        }
    }
    
    ofNotifyEvent(mSendEvent, isActionSensor);
}
