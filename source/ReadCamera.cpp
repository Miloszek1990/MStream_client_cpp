#include <iostream>
#include <string>
#include "../include/ReadCamera.hpp"

ReadCamera::ReadCamera(std::string serverIP, int port): 
	serverIP_(serverIP), 
	port_(port)
{}

ReadCamera::~ReadCamera(){}