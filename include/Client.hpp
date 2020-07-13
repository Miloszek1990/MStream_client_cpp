#include <string>
#include <opencv2/opencv.hpp>

class Client
{	
    private:
		std::string serverIP_;
		int port_;

        void printError();
        int initializeConnection();

    public:
        Client(std::string, int);
        ~Client();

        void printData();
        void sendData(cv::Mat&, int);
};