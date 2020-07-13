#include <iostream>
#include <string>

#include "./include/Client.hpp"
#include "./include/ReadCamera.hpp"

#include <opencv2/opencv.hpp>
//#include <raspicam/raspicam.h>
//#include <raspicam/raspicam_cv.h>

int main(int argc, char *argv[]) {
    
    std::string serverIP = "192.168.0.4";
    int port             = 8000;
    int imgWdth          = 1024;
    int imgHght          = 768;

    ReadCamera camera(imgWdth, imgHght);
    int frameSize = imgWdth * imgHght * 3;
    cv::Mat frame;
    camera.frameCapture(frame);
    frame = frame.reshape(0,1);

    std::string msg = "Ala ma kota.";

    Client client(serverIP, port);
    client.printData();
    client.sendData(frame, frameSize);
    
    std::cout << "fin" << std::endl;
    return 0;
}