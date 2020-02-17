#pragma once

#include "ofMain.h"
#include "ofxGuiExtended.h"
#include "ofxBlackMagic.h"
#include "ofxSimpleSerial.h"

//#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:


        int                 margin;
        ofColor             color;

        ofxGuiPanel          *projectPanel,
                             *panel2,
                             *controlPanel,
                             *speedPanel,
                             *speedControlPanel,
                             //*stabPanel;
                             *startStopP,
                             *directionP,
                             *captureP;

        ofxGuiContainer      *containerLeft,
                             *containerRight,
                             *speedControlContainer,
                             *containerButtons,
                             *markersContainer,
                             *markersSubContainer,
                             *shutter;      //check
                          //   *stabContainer;

         ofxGuiGroup        *controlGroup,
                            *speedGroup,
                            *projectGroup,
                            *speedControlGroup,
                            *markersGroup,
                            *markersSubGroup,
                            *filmToggles;       //check
                    //     *stabGroup;

         ofParameterGroup    controlParameters,
                             speedParameters,
                             projectParameters,
                             speedControlParameters,
                             markersParameters,
                             colorParameters; //check
                        //     stabParameters;

         ofxGui              gui2, gui3;     //check if gui3 is redundant

         ofxGuiButton*       destination,
                             homing,
                             drawMarkersB;  //check drawMarkersB

         ofxGuiToggle           *backwardB,     //check
                                *captureB;//check


         ofParameter<string>    homingStatus,
                                path3,
                                textfieldVal; //check

         ofParameter<bool>       startStopParameter,
                                 directionParameter,
                                 backwardBool2,     //check
                                 startStopToggle,   //check
                                 captureParameter,
                                 speedParameter1,
                                 speedParameter2,
                                 parameter4k,
                                 parameter2k,
                                 parameter1080p,
                                 parameter720p,
                                 parameterCenter,
                                 drawMarkersParameter,
    //    //check all these
    //    //_______________________________________________

                                 color0,
                                 color1,
                                 color2,
                                 color3,
                                 negative2,
                                 stabilizer2,
                                 dustRemoval2,
                                 mFullscreen2,
                                 loadBool2,
                                 captureBool2,
                                 recording2,
                                 forwardBool2,
                                 homingBool;
    //     //_______________________________________________

         ofParameter<float>     speed1,
                                speed2;

         ofParameter<int>       shutterPosition;

         //booleans, check all
         //--------------------------------------------------------------

         bool    negative,
                 dustRemoval,
                 mFullscreen,
                 directionBool,
                 stopBool,
                 startStopBool,
                 loadBool,
                 captureBool,
                 recording,
                 markersBool;

    //     //ofxBlackmagic
    //     //--------------------------------------------------------------

         ofxBlackMagic cam;

         float camX;
         float camY;
         int camWidth;
         int camHeight;

         //ofxSimpleSerial
         //--------------------------------------------------------------

         ofxSimpleSerial serial;
         std::string  message;
         bool    requestRead;
         bool    remember;

    //     //ofxCv
    //     //--------------------------------------------------------------

    //      ofxCv::ContourFinder    stabContour;
    //      ofParameter<bool>       stabHole;
    //      ofParameter<float>      stabMin,
    //                              stabMax,
    //                              stabThreshold;


    //     //Otros objetos, check all
    //     //--------------------------------------------------------------

         ofImage logo;
         ofPixels framePixels;
         ofFbo buff;
         ofTexture frameTexture;

    //     //funciones básicas
    //     //--------------------------------------------------------------



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

    //funciones especiales
    //--------------------------------------------------------------

    //GUI

     void setupGui();
     void changeDestination();
     void markersCall(bool &);
     void startStop(bool &);
     void directionSwitch(bool &);
     void capture(bool &);
     void drawMarkers();



//     void executeHoming();

//     void toggleFullscreen();
//     void refreshWindow();

//     //Projector //check all

//     void projectorForward();
//     void projectorStop();
//     void projectorLoad();

     //Camera

     void setupCamera();
     void setupRecorder();

     void updateCamera();
     void drawCamera();
     void captureFrame();
     void trigFrameCapture();

//     void onNewMessage(std::string &message);


};