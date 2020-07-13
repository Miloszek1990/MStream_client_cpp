#include <string>
#include <typeinfo>

#include <opencv2/opencv.hpp>

class ReadCamera
{	
    private:
        int imgWgth_;
        int imgHght_;

    public:
        ReadCamera(int, int);
        ~ReadCamera();

        void frameCapture(cv::Mat&);

};