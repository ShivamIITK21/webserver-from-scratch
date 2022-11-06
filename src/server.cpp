#include "serversocket.hpp"
#include "utils.hpp"

int main(){
    ServerSocket sock;
    sock.OpenSocket();
    sock.ConfigureSocket(8000);
    sock.BindtoAddr();
    sock.ListenForConnect(20);
    sockaddr_in cliaddr;
    socklen_t clilen = sizeof(cliaddr);
    while(1){
        // std::cout << html << std::endl;
        int newsockfd = sock.AcceptConnect(&cliaddr, &clilen);
        char buffer[2048];
        sock.ReadFromSocket(newsockfd, buffer, 1024);
        char * req_file = utils::ExtractReq(buffer);
        char * res = utils::GenerateRes(req_file);
        if(res[0] == '\0'){
            char * notfound = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 62\n\n<html>\n<h1>The File you requested does not exist</h1>\n</html>\n";
            sock.SendToSocket(newsockfd, notfound);
            close(newsockfd);
        }
        else{
            // char * ress = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 33\n\n<html>\n<h1>Hi bsdk!</h1>\n</html>\n";
            sock.SendToSocket(newsockfd, res);
            close(newsockfd);
        }
    }
}