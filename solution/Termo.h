#ifndef TERMO_H
#define TERMO_H

#include <string>

class Termo
{
public:
    std::string termo;
    long long peso;

    Termo(const std::string &t = "", long long p = 0);
};

#endif