#include <iostream>
#include <string>

#include <sys/socket.h>
#include <netdb.h> 
#include <string.h>
#include <unistd.h>

#include "../include/Client.hpp"

Client::Client(std::string serverIP, int port): 
	serverIP_(serverIP), 
	port_(port)
{}

Client::~Client(){}

void error(char *msg) {
    perror(msg);
    exit(0);
}

void Client::printData()
{
    std::cout << serverIP_ << std::endl;
    std::cout << port_ << std::endl;
}

int Client::initializeConnection()
{   
    int sockfd;
    const char *IP = serverIP_.c_str();
    sockaddr_in serv_addr;
    hostent *server;

    std::cout << "Connecting with" << IP << "on port " << port_ << std::endl;
    if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 )
        error( const_cast<char *>( "ERROR opening socket") );

    if ( ( server = gethostbyname( IP ) ) == NULL ) 
        error( const_cast<char *>("ERROR, no such host\n") );
    
    bzero( (char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy( (char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port_);

    if ( connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error( const_cast<char *>( "ERROR connecting") );

    return sockfd;
}

void Client::sendData(std::string& msg)
{   
    int n;
    int sockfd = initializeConnection();
    const char *cmsg = msg.c_str();

    if ( (n = write( sockfd, cmsg, strlen(cmsg) ) ) < 0 )
        perror( const_cast<char *>( "ERROR writing to socket") );

    close( sockfd );
}