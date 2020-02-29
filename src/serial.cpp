#include <ofApp.h>


void ofApp::setupSerial(){

    std::vector<ofx::IO::SerialDeviceInfo> devicesInfo = ofx::IO::SerialDeviceUtils::listDevices();

    ofLogNotice("ofApp::setup") << "Connected Devices: ";

    for (std::size_t i = 0; i < devicesInfo.size(); ++i)
    {
        ofLogNotice("ofApp::setup") << "\t" << devicesInfo[i];
    }

    if (!devicesInfo.empty())
    {
        // Connect to the first matching device.
        bool success = device.setup(devicesInfo[0], 115200);

        std::string code{};
        code = 'a';
        ofx::IO::ByteBuffer codeBuffer(code);

        if (success)
        {
            ofLogNotice("ofApp::setup") << "Successfully setup " << devicesInfo[0];

        }
        else
        {
            ofLogNotice("ofApp::setup") << "Unable to setup " << devicesInfo[0];
        }
    }
    else
    {
        ofLogNotice("ofApp::setup") << "No devices connected.";
    }
}

void ofApp::updateSerial(){



    std::size_t sz = device.readByte(serialCode);

    switch  (serialCode){

    case 'a':
//                projectorNotificationString =    "Serial Task, case auto reset \n"
//                                                 "a = Auto Reset \n"
//                                                 "b = Start Moving Forward \n"
//                                                 "c = Start Moving Backward \n"
//                                                 "d = Stop \n"
//                                                 "e = One Frame \n"
//                                                 "f = Hundred Frames \n"
//                                                 "g = Loading \n"
//                                                 "h = Test \n"
//                                                 "i = Test digital \n"
//                                                 "j = Test analog \n"
//                                                 "k = Encoder Test \n"
//                                                 "l = Calibrate Shutter \n"
//                                                 "m = Calibrate Sensor \n"
//                                                 "n = Read Sensor \n"
//                                                 "o = Print Values \n"
//                                                 "q = Direction Toggle \n"
//                                                 "r = Turn on interrupt \n"
//                                                 "s = Turn off interrupt \n"
//                                                 "t = Toggle Capture \n"
//                                                 "u = Homing \n"
//                                                 "v = Test button \n"
//                                                 "x = Test LED \n"
//                                                 "z = Start stop toggle \n";

                break;
    case 'b':
        projectorNotificationString = "Start moving forward";
        break;

    case 'c':
        projectorNotificationString = "Start moving backward";
        break;

    case 'd':
        projectorNotificationString = "Stopping";
        break;

    case 'e':
        projectorNotificationString = "One frame";
        break;

    case 'f':
        projectorNotificationString = "Hundred Frames";
        break;

    case 'g':
        projectorNotificationString = "Toggle Mode";
        //changeMode(true);
        //mode = true;
        ofLog() << "Toggle mode";

        break;

    case 'h':
        projectorNotificationString = "Mode 2";
        modeIndex = 1;
        setMode(modeIndex);
        ofLog() << "Mode 1";
        break;

    case 'i':
        projectorNotificationString = "Mode 1";
        modeIndex = 0;
        setMode(modeIndex);
        ofLog() << "Mode 2";

        break;

    case 'j':
        projectorNotificationString = "Test analog";
        break;

    case 'k':
        projectorNotificationString = "Encoder test";
        break;

    case 'l':
        projectorNotificationString = "Set speed OF";
        break;

    case 'm':
        projectorNotificationString = "Calibrate sensor";
        break;

    case 'n':
        projectorNotificationString = "Read sensor";
        break;

    case 'o':
        projectorNotificationString = "Print values";
        break;

    case 'p':
        projectorNotificationString = "Test acceleration";
        break;

    case 'q':
        projectorNotificationString = "Direction Toggle";
        break;

    case 'r':
        projectorNotificationString = "Turn on interrupt";
        break;

    case 's':
        projectorNotificationString = "Turn off interrupt";
        break;

    case 't':
        projectorNotificationString = "Toggle Capture";
        break;

    case 'u':
        projectorNotificationString = "Homing";
        break;

    case 'x':
        projectorNotificationString = "LEDS test";
        break;

    case 'y':
        projectorNotificationString = "Set speed toggle";

        break;

    case 'z':
        projectorNotificationString = "Start Moving Toggle";
        break;

    case '0':
        captureNotificationsString = "Frames processed:  " + ofToString(framesArrived);
        captureFrame();
        break;

    case '5':
        speed1.set(1);
        break;

    case '6':
        speed1.set(2);
        break;

    case '7':
        speed1.set(3);
        break;

    case '8':
        speed1.set(4);
        break;

    }

}

            // case 'v':
            //     return Request::button


//        // The serial device can throw exeptions.
//        try
//        {
//            // Read all bytes from the device;
//            uint8_t buffer[1024];

//            while (device.available() > 0)
//            {
//                std::size_t sz = device.readBytes(buffer, 1024);

//                for (std::size_t i = 0; i < sz; ++i)
//                {
//                    std::cout << buffer[i];
//                }
//            }

//            // Send some new bytes to the device to have them echo'd back.
//            //std::string text = "Frame Number: " + ofToString(ofGetFrameNum());

//            ofx::IO::ByteBuffer textBuffer(text);

//            device.writeBytes(textBuffer);
//            device.writeByte('\n');
//        }
//        catch (const std::exception& exc)
//        {
//            ofLogError("ofApp::update") << exc.what();
//        }
    //}


