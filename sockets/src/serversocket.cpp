#include "serversocket.hpp"

void ServerSocket::OpenSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        std::cout << "Failed to open socket" << std::endl;
        exit(1);
    }
    else{
        std::cout << "Server Socket opened successfully" << std::endl;
    }
}

void ServerSocket::ConfigureSocket(int portno){
    port = portno;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
}

void ServerSocket::BindtoAddr(){
    int n = bind(sockfd, (sockaddr *)&serv_addr, sizeof(sockaddr));
    if(n < 0){
        std::cout << "Bind Failed" << std::endl;
        exit(1);
    }
    else{
        std::cout << "Bind Successful" << std::endl;
    }
}

void ServerSocket::ListenForConnect(int maxQ){
    int n = listen(sockfd, maxQ);
    if(n < 0){
        std::cout << "Failed to Listen" << std::endl;
    }
    else{
        std::cout << "Listening on port " << port << std::endl;
    }
}

int ServerSocket::AcceptConnect(struct sockaddr_in * cliaddrref, socklen_t * clilenref){
    int newsockfd = accept(sockfd, (sockaddr *)cliaddrref, clilenref);
    if(newsockfd < 0){
        std::cout << "Failed to accept" << std::endl;
        exit(1);
    }
    else{
        std::cout << "Accepted Connection" << std::endl;
    }
    return newsockfd;
}

void ServerSocket::ReadFromSocket(int newsockfd, char * buffer, int len){
    bzero(buffer, len);
    int n = read(newsockfd, buffer, len-1);
    if(n < 0){
        std::cout << "Error on Read" << std::endl;
    }
    else{
        std::cout << "Message Recieved From Cliend\n";
        std::cout << buffer << std::endl;
    }
}

void ServerSocket::SendToSocket(int newsockfd, char * buffer){
    send(newsockfd, buffer, strlen(buffer), 0);
}

void ServerSocket::CloseSocket(){
    close(sockfd);
}