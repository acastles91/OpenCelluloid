#include "ofApp.h"

void ofApp::setupCamera(){

    ofSetLogLevel(OF_LOG_VERBOSE);
    cam.setup(bmdMode4K2160p30);
    ofClear(255,255,255, 0);
    camWidth = ofGetWidth() / 1.33;
    camHeight = ofGetHeight() / 1.33;

}


bool ofApp::setupRecorder(){


    path = path3.toString();
    projectName = textfieldVal.toString();
    if(emptyString.compare(path) == 0){
        captureNotificationsString = "Capture directory not set";
    }else{
//        cam.recorder.setPrefix(ofToDataPath(path + "/" + projectName + "-")); // this directory must already exist
        cam.recorder.setPrefix(path + "/" + projectName + "-"); // this directory must already exist
        cam.recorder.setFormat("tiff"); // png is really slow but high res, bmp is fast but big, jpg is just right
        cam.recorder.setNumberWidth(5);
    }
    captureNotificationsString = "Recorder setup";
    recorderOk = true;
    return true;

}


void ofApp::captureFrame(){
        if (recorderOk){
            cam.recorder.addFrame(cam.getColorPixels());
            framesArrived +=1;
            ofLog() << "Frame captured";
//            buff.begin();
//            frameTexture = cam.getColorTexture();
//            buff.end();
        }
    }

