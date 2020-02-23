#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    recording = false;

    setupGui();
    setupCamera();
    setupSerial();
}

//--------------------------------------------------------------
void ofApp::update(){


    if (device.available()){
//        deviceSz = device.readByte(serialCode);
        incomingRequest = true;
        updateSerial();
    }
    else {
        incomingRequest = false;
    }
    //device.flushOutput();
    //device.flushInput();

    if (markersBool){
            drawMarkers();
        }

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.update();
    if (!recording){
        cam.drawColor(camX, camY, cam.getWidth() / 3, cam.getHeight() / 3);
    }
    if (recording){
        if(serial.readByte() == 0){
        cam.drawColor(camX, camY, cam.getWidth() / 3, cam.getHeight() / 3);
        }
    }
    cam.drawColor(camX, camY, cam.getWidth() / 3, cam.getHeight() / 3);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){ 
        if(key == ' '){
            captureFrame();
        }
        if(key == 'f'){
            ofSetFullscreen(true);
        }

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
