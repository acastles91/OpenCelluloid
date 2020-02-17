#include "ofApp.h"

void ofApp::setupCamera(){

    ofSetLogLevel(OF_LOG_VERBOSE);
    cam.setup(bmdMode4K2160p30);
    ofClear(255,255,255, 0);

}


void ofApp::setupRecorder(){

    cam.recorder.setPrefix(ofToDataPath("recording1/frame_")); // this directory must already exist

//    cam.recorder.setPrefix(ofToDataPath(ofToString(path3) + "/" + ofToString(textfieldVal.get())));
    cam.recorder.setFormat("tiff"); // png is really slow but high res, bmp is fast but big, jpg is just right
    cam.recorder.setNumberWidth(5);
    ofLog()<< "HEZ!";

}


void ofApp::captureFrame(){
        if (recording){
        //framePixels.allocate(cam.getWidth(), cam.getHeight(), OF_PIXELS_RGBA);

            cam.recorder.addFrame(cam.getColorPixels());
            ofLog() << "Frame captured";
//            buff.begin();
//            frameTexture = cam.getColorTexture();
//            buff.end();
        }
    }

