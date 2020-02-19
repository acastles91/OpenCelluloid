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

    uint8_t code;

    if (device.available()){

    incomingRequest = true;

    std::size_t sz = device.readByte(code);

    switch  (code){

    case 'a':
                notificationString = "Serial Task, case auto reset \n"
                                     "a = Auto Reset \n"
                                     "b = Start Moving Forward \n"
                                     "c = Start Moving Backward \n"
                                     "d = Stop \n"
                                     "e = One Frame \n"
                                     "f = Hundred Frames \n"
                                     "g = Loading \n"
                                     "h = Test \n"
                                     "i = Test digital \n"
                                     "j = Test analog \n"
                                     "k = Encoder Test \n"
                                     "l = Calibrate Shutter \n"
                                     "m = Calibrate Sensor \n"
                                     "n = Read Sensor \n"
                                     "o = Print Values \n"
                                     "q = Direction Toggle \n"
                                     "r = Turn on interrupt \n"
                                     "s = Turn off interrupt \n"
                                     "t = Toggle Capture \n"
                                     "u = Homing \n"
                                     "v = Test button \n"
                                     "x = Test LED \n"
                                     "z = Start stop toggle \n";

                break;
    case 'b':
        notificationString = "Start moving forward";
        break;

    case 'c':
        notificationString = "Start moving backward";
        break;

    case 'd':
        notificationString = "Stopping";
        break;

    case 'e':
        notificationString = "One frame";
        break;

    case 'f':
        notificationString = "Hundred Frames";
        break;

    case 'g':
        notificationString = "Loading";
        break;

    case 'h':
        notificationString = "Test";
        break;

    case 'i':
        notificationString = "Test digital";
        break;

    case 'j':
        notificationString = "Test analog";
        break;

    case 'k':
        notificationString = "Encoder test";
        break;

    case 'l':
        notificationString = "Calibrate shutter";
        break;

    case 'm':
        notificationString = "Calibrate sensor";
        break;

    case 'n':
        notificationString = "Read sensor";
        break;

    case 'o':
        notificationString = "Print values";
        break;

    case 'p':
        notificationString = "Test acceleration";
        break;

    case 'q':
        notificationString = "Direction Toggle";
        break;

    case 'r':
        notificationString = "Turn on interrupt";
        break;

    case 's':
        notificationString = "Turn off interrupt";
        break;

    case 't':
        notificationString = "Toggle Capture";
        break;

    case 'u':
        notificationString = "Homing";
        break;

    case 'x':
        notificationString = "LEDS test";
        break;

    case 'z':
        notificationString = "Start Moving Toggle";
        break;

    case '0':
        //notificationString = "Frame";
        notificationString = "0";
        captureFrame();
        break;
        }
    }
    else {
        incomingRequest = false;
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


