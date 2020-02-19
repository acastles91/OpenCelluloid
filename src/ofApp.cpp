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
    cam.update();
    if (markersBool){
            drawMarkers();
        }
    updateSerial();

   //
    if (recording){
        if (serial.readByte() == 0){
            captureFrame();
        }

    }

}

//--------------------------------------------------------------
void ofApp::draw(){
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
