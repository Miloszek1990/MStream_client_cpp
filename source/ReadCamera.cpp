#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

#include "../include/ReadCamera.hpp"

ReadCamera::ReadCamera(int imgWgth, int imgHght): 
        imgWgth_(imgWgth),
        imgHght_(imgHght)
{}

ReadCamera::~ReadCamera(){}

void ReadCamera::frameCapture(cv::Mat& frame)
{
    cv::VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        std::cout << "ups..." << std::endl;
    
    cap.set(cv::CAP_PROP_FRAME_WIDTH, imgWgth_);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, imgHght_);

    cap >> frame;
    
    //int imgSize = frame.total() * frame.elemSize();
    //std::cout << frame.total() << "  " << frame.elemSize() << "  " << imgSize << std::endl;
    //std::cout << typeid(frame).name() << std::endl;

    //cv::imwrite("../aaa.png", frame);
    //std::cout << "ok..." << std::endl;
}