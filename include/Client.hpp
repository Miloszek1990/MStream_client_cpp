#include <string>

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
        void sendData(std::string& msg);
};