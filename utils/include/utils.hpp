#ifndef UTILS_INCLUDED
#define UTILS_INCLUDED
#include<fstream>
#include<iostream>
#include<cstring>

namespace utils{
    char * ExtractReq(char * buffer);
    char * GenerateRes(char * file);
}

#endif