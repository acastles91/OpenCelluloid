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
                //Serial.println("Auto reset");
                //notificationString.set('a');
                notificationString = ofToString(code);
//                return Request::auto_reset_request;
//                prevRequestArg = Request::auto_reset_request;
                break;
            case 'b':
                // Serial.println("Start moving forward");
                //notificationString.set('b');
                notificationString = ofToString(code);

//                return Request::start_moving_forward_request;
//                prevRequestArg = Request::start_moving_forward_request;
                break;
            case 'c':
                // Serial.println("Start moving backward");
                //notificationString.set('c');
                notificationString = ofToString(code);

//                return Request::start_moving_backward_request;
//                prevRequestArg = Request::start_moving_backward_request;
                break;
            case 'd':
                // Serial.println("Stopping");
                //notificationString.set('d');
                notificationString = ofToString(code);

//                return Request::stopping_request;
//                prevRequestArg = Request::stopping_request;
                break;
            case 'e':
                //Serial.println("One frame");
                //notificationString.set('e');
                notificationString = ofToString(code);

//                return Request::one_frame_request;
//                prevRequestArg = Request::one_frame_request;
                break;
            case 'f':
                //Serial.println("Hundred Frames");
                //notificationString.set('f');
                notificationString = ofToString(code);

//                return Request::hundred_frames_request;
//                prevRequestArg = Request::hundred_frames_request;
                break;
            case 'g':
                //Serial.println("Loading");
                //notificationString.set('g');
                notificationString = ofToString(code);

//                return Request::loading_request;
//                prevRequestArg = Request::loading_request;
                break;
            case 'h':
                //Serial.println("Test");
                //notificationString.set('h');
                notificationString = ofToString(code);

//                return Request::test_request;
//                prevRequestArg = Request::test_request;
                break;
            case 'i':
                //Serial.println("Test digital");
                //notificationString.set('i');
                notificationString = ofToString(code);

//                return Request::test_digital_request;
//                prevRequestArg = Request::test_digital_request;
                break;
            case 'j':
                //Serial.println("Test analog");
                //notificationString.set('j');
                notificationString = ofToString(code);

//                return Request::test_analog_request;
//                prevRequestArg = Request::test_analog_request;
                break;
            case 'k':
                //Serial.println("Encoder test");
                //notificationString.set('k');
                notificationString = ofToString(code);

//                return Request::encoder_test_request;
//                prevRequestArg = Request::encoder_test_request;
                break;
            case 'l':
                //Serial.println("Calibrate shutter");
                //notificationString.set('l');
                notificationString = ofToString(code);

//                return Request::calibrate_shutter_request;
//                prevRequestArg = Request::calibrate_shutter_request;
                break;
            case 'm':
                //Serial.println("Calibrate sensor");
                //notificationString.set('m');
                notificationString = ofToString(code);

//                return Request::calibrate_sensor_request;
//                prevRequestArg = Request::calibrate_sensor_request;
                break;
            case 'n':
                //Serial.println("Read sensor");
                //notificationString.set('n');
                notificationString = ofToString(code);

//                return Request::read_sensor_request;
//                prevRequestArg = Request::read_sensor_request;
                break;
            case 'o':
                //Serial.println("Print values");
                //notificationString.set('o');
                notificationString = ofToString(code);

//                return Request::print_values_request;
//                prevRequestArg = Request::print_values_request;
                break;
            case 'p':
                //Serial.println("Test acceleration");
                //notificationString.set('p');
                notificationString = ofToString(code);

//                return Request::test_acceleration_request;
//                prevRequestArg = Request::test_acceleration_request;
                break;
            case 'q':
                //Serial.println("Direction Toggle");
                //notificationString.set('q');
                notificationString = ofToString(code);

//                return Request::direction_toggle_request;
//                prevRequestArg = Request::direction_toggle_request;
                break;

            case 'r':
                //Serial.println("Turn on interrupt");
                //notificationString.set('r');
                notificationString = ofToString(code);

//                return Request::turn_on_interrupt_request;
//                prevRequestArg = Request::turn_on_interrupt_request;
                break;

            case 's':
                //Serial.println("Turn off interrupt");
                //notificationString.set('s');
                notificationString = ofToString(code);

//                return Request::turn_off_interrupt_request;
//                prevRequestArg = Request::turn_off_interrupt_request;
                break;

            case 't':
                //Serial.println("Toggle Capture");
                //notificationString.set('t');
                notificationString = ofToString(code);

//                return Request::capture_toggle_request;
//                prevRequestArg = Request::capture_toggle_request;
                break;

            case 'u':
                //notificationString.set('u');
//                return Request::homing_request;
                notificationString = ofToString(code);

//                prevRequestArg = Request::homing_request;
                break;

            case 'x':
                //Serial.println("LEDS test");
                //notificationString.set('x');
                notificationString = ofToString(code);

//                return Request::test_leds_request;
//                prevRequestArg = Request::test_leds_request;
                break;
        }
    }
    else {
        notificationString = ofToString("?");
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


