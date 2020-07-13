#include <string>

class ReadCamera
{	
    private:
		std::string serverIP_;
		int port_;

    public:
        ReadCamera(std::string, int);
        ~ReadCamera();
};