#include "utils.hpp"

char * utils::ExtractReq(char * buffer){
    char c = buffer[5];
    int i = 5;
    int j = 0;
    char req_file[50];
    while(c != ' '){
        req_file[j] = c;
        i += 1;
        c = buffer[i];
        j += 1;
    }
    req_file[j] = '\0';
    std::cout << req_file << std::endl;
    char initial[] = "../../";
    char * final_path = (char *)malloc(sizeof(char)*56);
    strcpy(final_path, initial);
    strcat(final_path, req_file);
    return final_path;
}

char * utils::GenerateRes(char * file){
    char html[2048];
    char * finalRes = (char *)malloc(sizeof(char)*2048);
    // "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: 33\n\n<html>\n<h1>Hi bsdk!</h1>\n</html>\n";
    FILE * fileptr;
    fileptr = fopen(file, "r");
    if(fileptr != NULL){
        int i = 0;
        while(!feof(fileptr)){
            char c = fgetc(fileptr);
            html[i] = c;
            i++;
        }
        html[i-1] = '\0';

        char header[] = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
        int content_len = strlen(html);
        char slen[8];
        sprintf(slen, "%d", content_len);
        int j = strlen(slen);
        slen[j] = '\n';
        slen[j+1] = '\n';
        slen[j+2] = '\0';
        
        strcpy(finalRes, header);
        strcat(finalRes, slen);
        strcat(finalRes, html);

        fclose(fileptr);
        return finalRes;
    }
    finalRes[0] = '\0';
    std::cout << "Requested file doesn't exist" << std::endl;
    return finalRes;
}