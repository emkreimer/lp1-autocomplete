#ifndef TERMO_H
#define TERMO_H

#include <string>

class Termo
{
private:
    std::string termo;
    long long peso;

public:
    Termo(std::string t, long long p);
    std::string getTermo() const;
    long long getPeso() const;

    bool operator<(const Termo &other) const;
    bool operator>(const Termo &other) const;
};

#endif