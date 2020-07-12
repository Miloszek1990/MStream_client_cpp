#include <iostream>
#include <string>
#include "./include/Client.hpp"
//#include <opencv2/opencv.hpp>
//#include <raspicam/raspicam.h>
//#include <raspicam/raspicam_cv.h>

int main(int argc, char *argv[]) {
    
    std::string serverIP = "192.168.0.4";
    int port             = 8000;

    std::string msg = "Ala ma kota.";

    Client client(serverIP, port);
    client.printData();
    client.sendData(msg);
    
    std::cout << "fin" << std::endl;
    return 0;
}