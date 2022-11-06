#ifndef SERVER_INCLUDED
#define SERVER_INCLUDED
#include "headers.hpp"


class ServerSocket{
    public:
        int sockfd;
        struct sockaddr_in serv_addr;
        int port;

        void OpenSocket();
        void ConfigureSocket(int portno);
        void BindtoAddr();
        void ListenForConnect(int maxQ);
        int AcceptConnect(struct sockaddr_in * cliaddr, socklen_t * clilenref);
        void ReadFromSocket(int newsockfd, char * buffer, int len);
        void SendToSocket(int newsockfd, char * buffer);
        void CloseSocket();
};



#endif