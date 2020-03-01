#include "ofApp.h"

void ofApp::setupGui(){


//    //Logo & Background
//    //--------------------------------------------------------------

    ofSetFrameRate(120);
    ofBackground(235, 235, 235);
    margin = 50;
    projectorNotificationString = "Starting";
    captureNotificationsString = "Hey";
    emptyString = "";
    directionBool = true;
    mode = true;

//    //ofxGuiExtended
//    //--------------------------------------------------------------


//    //Project panel
//    //--------------------------------------------------------------

    projectPanel = gui2.addPanel();
    projectPanel->setShowHeader(false);
    projectPanel->setBackgroundColor(ofColor::darkGray);
    projectPanel->setPosition(margin, margin);

    projectGroup = projectPanel->addGroup(projectParameters);
    projectGroup->setShowHeader(0);
    projectGroup->setConfig(ofJson({{"type", "fullsize"}, {"direction", "vertical"}}));

    containerLeft = projectGroup->addContainer();
    containerLeft->setBackgroundColor(ofColor::blue);
    containerLeft->setWidth(50.0f);
    containerLeft->setPosition(0,0);

    destination = containerLeft->add<ofxGuiButton>("Film destination", ofJson({{"type", "fullsize"}, {"text-align", "center"}}));

    destination->addListener(this, &ofApp::changeDestination);
    path3.set("Directory", emptyString);

    homingStatus.set("Homing not executed");
    projectGroup->add(path3);
    projectGroup->add<ofxGuiTextField>(textfieldVal.set("Project Name", "Enter project name"));

    projectGroup->add(homingStatus);

//    //speed Control Panel
//    //--------------------------------------------------------------

//    speedControlPanel = gui2.addPanel();
//    speedControlPanel->setShowHeader(false);
//    speedControlPanel->setBackgroundColor(ofColor::darkGray);


//    speedControlGroup = speedControlPanel->addGroup(speedControlParameters);
//    speedControlGroup->setShowHeader(0);
//    speedControlGroup->setConfig(ofJson({{"type", "fullsize"}, {"direction", "vertical"}}));

//    speedControlContainer = speedControlGroup->addContainer();
//    speedControlContainer->setBackgroundColor(ofColor::lightGray);

    //speedControlPanel = gui2.addPanel();
    //speedControlPanel->setShowHeader(false);
    //speedControlPanel->setBackgroundColor(ofColor::darkGray);


    speedControlGroup = projectPanel->addGroup(speedControlParameters);
    speedControlGroup->setShowHeader(0);
    speedControlGroup->setConfig(ofJson({{"type", "fullsize"}, {"direction", "vertical"}}));

    speedControlContainer = speedControlGroup->addContainer();
    speedControlContainer->setBackgroundColor(ofColor::lightGray);
    //speedControlContainer->add(speedProjector.set("Speed", 1, 1, 4), ofJson({{"precision", 1}}));
    //speedControlContainer->add<ofxGuiButton>("Change Speed", ofJson({{"type", "fullsize"}, {"text-align", "center"}}));


    //speedControlContainer->add(speed2.set("Speed 2", 0.5, 0.1, 1), ofJson({{"precision", 1}}));


//    //markers group
//    //--------------------------------------------------------------

//    markersGroup = speedControlPanel->addGroup();
    markersGroup = projectPanel->addGroup();
    markersSubContainer = markersGroup->addContainer();
    markersSubContainer->add(drawMarkersParameter, ofJson({{"type", "fullsize"}, {"text-align", "center"}}));
    //markersSubContainer->setWidth(containerLeft->getWidth());
    //markersContainer = markersGroup->addContainer();
    drawMarkersParameter.set("Draw Markers", false);
    markersBool = false;
    //markersContainer->setWidth(markers);
    drawMarkersParameter.addListener(this, &ofApp::markersCall);
    markersParameters.add(parameter4k.set("4K", false));
    markersParameters.add(parameter2k.set("2K", false));
    markersParameters.add(parameter1080p.set("1080p", false));
    markersParameters.add(parameter720p.set("720p", false));
    markersParameters.add(parameterCenter.set("Center", false));
    markersSubGroup = markersGroup->addGroup(markersParameters);
    //markersSubGroup->setWidth(speedControlGroup->getWidth());
    //markersSubGroup->setWidth(markersGroup->getWidth());
    markersSubGroup->setBackgroundColor(ofColor::lightGray);
    markersSubGroup->setShowHeader(0);
    markersSubGroup->setShowName(1);
    markersSubGroup->setConfig(ofJson({{"type", "fullsize"}, {"direction", "horizontal"}}));
    markersSubGroup->setExclusiveToggles(0);
    markersGroup->setShowHeader(0);
    //markersGroup->setWidth(speedControlGroup->getWidth());

//Notifications
//--------------------------------------------------------------


//    notificationsGroup = speedControlPanel->addGroup("Notifications");
    notificationsGroup = projectPanel->addGroup("Notifications");
    //notificationsGroup->isChild(projectPanel);
    notificationsGroup->setShowHeader(0);
    projectorNotificationsContainer = notificationsGroup->addContainer();
    projectorNotificationsContainer->add(projectorNotificationString);
    captureNotificationsContainer = notificationsGroup->addContainer();
    captureNotificationsContainer->add(captureNotificationsString);
//    //Stabilization paneln
//    //--------------------------------------------------------------

    //    stabPanel = gui2.addPanel();
    //    stabPanel->setShowHeader(false);
    //    stabPanel->setBackgroundColor(ofColor::darkGray);
    //    stabPanel->setPosition(projectPanel->getX(), speedControlPanel->getHeight() + 50);


    //    stabGroup = stabPanel->addGroup(stabParameters);
    //    stabGroup->setShowHeader(0);
    //    stabGroup->setConfig(ofJson({{"type", "fullsize"}, {"direction", "vertical"}}));

    //    stabContainer = stabGroup->addContainer();
    //    stabContainer->setBackgroundColor(ofColor::lightGray);
    //    stabContainer->add(stabMin.set("Min", 30.0, 0.0, 300.0), ofJson({{"precision", 1}}));
    //    stabContainer->add(stabMax.set("Max", 300.0, 0.0, 600.0), ofJson({{"precision", 1}}));
    //    stabContainer->add(stabThreshold.set("Threshold", 100.0, 0.0, 200.0), ofJson({{"precision", 1}}));
    //    stabContainer->add(stabHole.set("Hole", false));

    //Size and layout
    //--------------------------------------------------------------


    projectPanel->setWidth(markersGroup->getWidth());
    projectPanel->setHeight(ofGetHeight() - 2 * margin);
    projectGroup->setWidth(projectPanel->getWidth());
    notificationsGroup->setWidth(projectGroup->getWidth());
    markersGroup->setWidth(projectGroup->getWidth());
    speedControlGroup->setWidth(projectGroup->getWidth());
    //speedControlPanel->setPosition(projectGroup->getX() + margin, projectGroup->getHeight() + margin + 50);
    //speedControlPanel->setWidth(projectPanel->getWidth());
    notificationsGroup->setHeight(projectPanel->getHeight() - notificationsGroup->getY());


//    //Speed selector
//    //--------------------------------------------------------------

    speedParameters.add(speedParameter1.set("Mode 1", mode));
    speedParameters.add(speedParameter2.set("Mode 2", !mode));

    speedPanel = gui2.addPanel();
    speedPanel->setShowHeader(false);
    speedPanel->setBackgroundColor(ofColor::darkGray);
    speedGroup = speedPanel ->addGroup(speedParameters);


    speedGroup->setShowHeader(0);
    speedGroup->setExclusiveToggles(true);
    speedGroup->setConfig(ofJson({{"type", "radio"}, {"direction", "horizontal"}}));

    speedGroup->getActiveToggleIndex().addListener(this, &ofApp::setMode);
    speedGroup->setActiveToggle(0);
//    //Projector control
//    //--------------------------------------------------------------

    controlPanel = gui2.addPanel();
    controlPanel->setShowHeader(false);
    controlPanel->setBackgroundColor(ofColor::darkGray);
    controlGroup = controlPanel->addGroup(controlParameters);
    controlGroup->setShowHeader(0);
    controlGroup->setConfig(ofJson({{"direction", "horizontal"}}));

    startStopP = controlGroup->addPanel();
    startStopP->setBackgroundColor(ofColor::lightGray);
    startStopP->setShowHeader(false);
    startStopP->setWidth(80.0f);
    startStopParameter.set("Start", false);
    startStopP->add(startStopParameter, ofJson({{"type", "fullsize"}, {"text-align", "center"}}));
    startStopP->setPosition(projectPanel->getX(), projectPanel->getHeight() + 100);
    startStopParameter.addListener(this, &ofApp::startStop);

    directionP = controlGroup->addPanel();
    directionP->setBackgroundColor(ofColor::lightGray);
    directionP->setShowHeader(false);
    directionP->setWidth(80.0f);
    directionParameter.set("Forward", true);
    directionP->add(directionParameter, ofJson({{"type", "fullsize"}, {"text-align", "center"}}));
    directionP->setPosition(startStopP->getX() + startStopP->getWidth(), startStopP->getY());
    directionParameter.addListener(this, &ofApp::directionSwitch);

    homingP = controlGroup->addPanel();
    homingP->setBackgroundColor(ofColor::lightGray);
    homingP->setShowHeader(false);
    homingP->setWidth(80.0f);
    homingParameter.set("Homing", true);
    homingP->add(homingParameter, ofJson({{"type", "fullsize"}, {"text-align", "center"}}));
    homingP->setPosition(directionP->getX() + directionP->getWidth(), directionP->getY());
    homingParameter.addListener(this, &ofApp::homingToggle);


    captureP = controlGroup->addPanel();
    captureP->setBackgroundColor(ofColor::orange);
    captureP->setShowHeader(false);
    captureP->setWidth(80.0f);
    captureParameter.set("Capture", false);
    captureP->add(captureParameter, ofJson({{"type", "fullsize"}, {"text-align", "center"}}));
    captureP->setPosition(homingP->getX() + homingP->getWidth(), homingP->getY());
    captureParameter.addListener(this, &ofApp::capture);

    changeSpeedP = controlGroup->addPanel();
    changeSpeedP->setBackgroundColor(ofColor::lightGray);
    changeSpeedP->setShowHeader(false);
    changeSpeedP->setWidth(80.0f);
    changeSpeedParameter.set("Change Speed", true);
    changeSpeedP->add(changeSpeedParameter, ofJson({{"type", "fullsize"}, {"text-align", "center"}}));
    changeSpeedP->setPosition(captureP->getX() + captureP->getWidth(), captureP->getY());
    changeSpeedParameter.addListener(this, &ofApp::setSpeed);


    changeSpeedSliderP = controlGroup->addPanel();
    changeSpeedSliderP->setBackgroundColor(ofColor::lightGray);
    changeSpeedSliderP->setShowHeader(false);
    changeSpeedSliderP->setWidth(160.0f);
    changeSpeedSliderP->add(speed1.set("Speed", 4, 1, 4), ofJson({{"precision", 1}}));
    changeSpeedP->setPosition(changeSpeedP->getX() + changeSpeedP->getWidth(), changeSpeedP->getY());




//    //Size and layout
//    //--------------------------------------------------------------

//    controlPanel->setPosition(ofGetWidth()/2 - controlPanel->getWidth() / 2, ofGetHeight() - 200);
//    speedPanel->setPosition(ofGetWidth()/2 - speedPanel->getWidth() / 2, controlPanel->getY() - 50);


    //camX = ofGetWidth() - 1280 - projectPanel->getX();
    camX = projectPanel->getX() + projectPanel->getWidth() + margin;
    camY = projectPanel->getY();

//    controlPanel->setPosition( camX + cam.getWidth() / 2 - (controlPanel->getWidth() / 2) + (1280 / 2), ofGetHeight() - 200);
//    speedPanel->setPosition( camX + cam.getWidth() / 2 - (speedPanel->getWidth() / 2) + (1280 / 2), controlPanel->getY() - 50);

    controlPanel->setPosition(camX + (camWidth /2) - controlPanel->getWidth() / 2, ofGetHeight() - 200);
    speedPanel->setPosition( camX + (camWidth / 2) - (speedPanel->getWidth() / 2), controlPanel->getY() - 50);



}

void ofApp::drawMarkers(bool &){

        if(parameter4k){
            //ofEnableAlphaBlending();
            ofSetColor(ofColor::red);
            ofNoFill();
            ofSetLineWidth(2);
            //ofPushMatrix();
            //ofTranslate(camX + ((cam.getWidth() / 3) / 2), camY + ((cam.getHeight() / 3) / 2));
//            ofDrawRectangle(-((cam.getWidth() / 3) / (3840.0f / 2048.0f) / 2), -((cam.getHeight() / 3) / (3840.0f / 2048.0f)) / 2, (cam.getWidth() / 3) / (3840.0f / 2048.0f), (cam.getHeight() / 3) / (3840.0f / 2048.0f));


            ofDrawRectangle(camX, camY, cam.getWidth() / 3, cam.getHeight() / 3);

            ofDrawBitmapString(ofToString(cam.getWidth()) + " x " + ofToString(cam.getHeight()),camX + (cam.getWidth() / 3) - 90, camY + (cam.getHeight() / 3) + 12);
            ofSetColor(ofColor::white);
            //ofPopMatrix();

        }

        if (parameter2k){

            //ofEnableAlphaBlending();
            ofSetColor(ofColor::green);
            ofNoFill();
            ofSetLineWidth(2);
            ofPushMatrix();
            ofTranslate(camX + ((cam.getWidth() / 3) / 2), camY + ((cam.getHeight() / 3) / 2));
            ofDrawRectangle(-((cam.getWidth() / 3) / (3840.0f / 2048.0f) / 2), -((cam.getHeight() / 3) / (3840.0f / 2048.0f)) / 2, (cam.getWidth() / 3) / (3840.0f / 2048.0f), (cam.getHeight() / 3) / (3840.0f / 2048.0f));
            ofDrawBitmapString(ofToString(cam.getWidth() / (3840.0f / 2048.0f)) + " x " + ofToString(cam.getHeight() / (3840.0f / 2048.0f)),((cam.getWidth() / 3) / (3840.0f / 2048.0f) / 2) - 90 , ((cam.getHeight() / 3) / (3840.0f / 2048.0f)) / 2 + 12);
            ofSetColor(ofColor::white);
            ofPopMatrix();
        }

        if (parameter1080p){

            //ofEnableAlphaBlending();
            ofSetColor(ofColor::yellow);
            ofNoFill();
            ofSetLineWidth(2);
            ofPushMatrix();
            ofTranslate(camX + ((cam.getWidth() / 3) / 2), camY + ((cam.getHeight() / 3) / 2));
            ofDrawRectangle(-((cam.getWidth() / 3) / (3840.0f / 1920.0f) / 2), -((cam.getHeight() / 3) / (3840.0f / 1920.0f)) / 2, (cam.getWidth() / 3) / (3840.0f / 1920.0f), (cam.getHeight() / 3) / (3840.0f / 1920.0f));
            ofDrawBitmapString(ofToString(cam.getWidth() / (3840.0f / 1920.0f)) + " x " + ofToString(cam.getHeight() / (3840.0f / 1920.0f)),((cam.getWidth() / 3) / (3840.0f / 1920.0f) / 2) - 90 , ((cam.getHeight() / 3) / (3840.0f / 1920.0f)) / 2 + 12);
            ofSetColor(ofColor::white);
            ofPopMatrix();
        }

        if (parameter720p){

            ofSetColor(ofColor::purple);
            ofNoFill();
            ofSetLineWidth(2);
            ofPushMatrix();
            ofTranslate(camX + ((cam.getWidth() / 3) / 2), camY + ((cam.getHeight() / 3) / 2));
            ofDrawRectangle(-((cam.getWidth() / 3) / (3840.0f / 1280.0f) / 2), -((cam.getHeight() / 3) / (3840.0f / 1280.0f)) / 2, (cam.getWidth() / 3) / (3840.0f / 1280.0f), (cam.getHeight() / 3) / (3840.0f / 1280.0f));
            ofDrawBitmapString(ofToString(cam.getWidth() / (3840.0f / 1280.0f)) + " x " + ofToString(cam.getHeight() / (3840.0f / 1280.0f)),((cam.getWidth() / 3) / (3840.0f / 1280.0f) / 2) - 90 , ((cam.getHeight() / 3) / (3840.0f / 1280.0f)) / 2 + 12);
            ofSetColor(ofColor::white);
            ofPopMatrix();


        }

        if (parameterCenter){

            ofSetColor(ofColor::blue);
            ofNoFill();
            ofSetLineWidth(2);
            ofPushMatrix();
            ofTranslate(camX + ((cam.getWidth() / 3) / 2), camY + ((cam.getHeight() / 3) / 2));
            ofDrawLine(-(cam.getWidth() / 3) / 2, 0, (cam.getWidth() / 3 / 2), 0);
            ofDrawLine(0, -(cam.getHeight() / 3) / 2, 0, (cam.getHeight() / 3) / 2);
            ofSetColor(ofColor::white);
            ofPopMatrix();
        }
 }

//--------------------------------------------------------------
void ofApp::changeDestination(){

    ofFileDialogResult result = ofSystemLoadDialog("project folder", true);
    if(result.bSuccess) {
       path3 = result.getPath();


    cout << path3 << endl;
    }
}
//--------------------------------------------------------------
void ofApp::markersCall(bool &){

    markersBool = !markersBool;

}
//--------------------------------------------------------------
void ofApp::startStop(bool &)
{
    startStopBool = !startStopBool;
    std::string code{};

    homingStatus.set("Homing not executed");
    if (!startStopBool){
        startStopParameter.setName("Start");
    }else{
        startStopParameter.setName("Stop");
    }

    if (!incomingRequest){
        code = 'z';
        ofx::IO::ByteBuffer codeBuffer(code);
        //

        //device.writeBytes(codeBuffer);
        device.writeBytes(codeBuffer);
        codeBuffer.empty();
    }

}

//--------------------------------------------------------------

void ofApp::directionSwitch(bool &)
{
    directionBool = !directionBool;
    std::string code{};

    if (!directionBool){
        directionParameter.setName("Backward");
    }else{
        directionParameter.setName("Forward");
    }

    if (!incomingRequest){
    code = 'q';
    ofx::IO::ByteBuffer codeBuffer(code);

    device.writeBytes(codeBuffer);
    codeBuffer.empty();
    }

}

//--------------------------------------------------------------

void ofApp::homingToggle(bool &)
{
    homingBool = !homingBool;

    std::string code{};

    if (!incomingRequest){
    code = 'u';
    ofx::IO::ByteBuffer codeBuffer(code);

    device.writeBytes(codeBuffer);
    codeBuffer.empty();
    homingStatus.set("Homing executed");
    }
}

//--------------------------------------------------------------


void ofApp::capture(bool &)
{
    captureBool = !captureBool;

    if (captureBool){
        setupRecorder();
        cam.recorder.startThread();
        ofLog() << "Recorder set up correctly " + path + " " + projectName;
        }
    else if(!captureBool)
        if(cam.recorder.isThreadRunning()){
            //cam.recorder.stopThread();
    }
    recording = !recording;
    if (!incomingRequest){
        std::string code{};
        code = 't';
        ofx::IO::ByteBuffer codeBuffer(code);
        device.writeBytes(codeBuffer);
        codeBuffer.empty();
    }

}

//--------------------------------------------------------------


void ofApp::changeMode(bool &)
{
//    mode = !mode;

//    if (!mode){
//            speedParameter1.set(false);
//        }
//    else{
//            speedParameter1.set(true);
//        }
//    if (!incomingRequest){
//        std::string code{};
//        code = 'g';
//        ofx::IO::ByteBuffer codeBuffer(code);
//        device.writeBytes(codeBuffer);
//        codeBuffer.empty();
//    }

}

//--------------------------------------------------------------


void ofApp::setMode(int& val){


   std::string code{};

   switch (val){
   case 0:
       speedParameter1.set(true);
       speedParameter2.set(false);
       mode = true;

       //code = 'h';
       break;
    case 1:

       speedParameter1.set(false);
       speedParameter2.set(true);
       mode = false;

       //code = 'i';
       break;
   }

    code = 'o';
    if (!incomingRequest){

    ofx::IO::ByteBuffer codeBuffer(code);
    device.writeBytes(codeBuffer);
    codeBuffer.empty();
    }
};

void ofApp::setSpeed(bool &){

    std::string code{};
    switch (speed1.get()){
    case 1:
        code = '5';
        break;

    case 2:
        code = '6';
        break;

    case 3:
        code = '7';
        break;

    case 4:
        code = '8';
        break;
    }



    if (!incomingRequest){
    ofx::IO::ByteBuffer codeBuffer(code);
    device.writeBytes(codeBuffer);
    codeBuffer.empty();
    ofLog() << "Change speed: " + code;
    ofLog() << code;
    }
}
void ofApp::changeSpeedFunction(bool &)
{

    if (!incomingRequest){
        std::string code{};
        code = 'f';
        ofx::IO::ByteBuffer codeBuffer(code);
        device.writeBytes(codeBuffer);
        codeBuffer.empty();
    }

}

//--------------------------------------------------------------


