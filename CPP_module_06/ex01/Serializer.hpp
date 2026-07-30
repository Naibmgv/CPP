#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string str;
    int i;
};

class Serializer
{
    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private :
        Serializer() {}
        Serializer(const Serializer& src) {(void)src;}
        Serializer& operator=(const Serializer& rhs) {
        (void)rhs;
        return *this;
    }
    ~Serializer() {}
};

#endif