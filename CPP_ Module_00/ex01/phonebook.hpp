#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "contact.hpp"
#include <iomanip>

class Phonebook {

public:

    Phonebook(int i);
    void    search() const;
    int    add();

private:

    Contact _contacts[8];
    int     _index;
    int     _total;
};

#endif