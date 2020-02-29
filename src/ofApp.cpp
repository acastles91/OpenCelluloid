#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    recording = false;

    setupGui();
    setupCamera();
    setupSerial();
    setSpeed(mode);
}

//--------------------------------------------------------------
void ofApp::update(){

    cam.update();


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




}

//--------------------------------------------------------------
void ofApp::draw(){

//    if (!recording){
        cam.drawColor(camX, camY, cam.getWidth() / 3, cam.getHeight() / 3);
//    }
//    if (recording){
//        if(serial.readByte() == 0){
//        cam.drawColor(camX, camY, cam.getWidth() / 3, cam.getHeight() / 3);
//        }
//    }

        if (markersBool){
                drawMarkers(markersBool);
            }



}
//--------------------------------------------------------------

void ofApp::keyPressed(int key){


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
