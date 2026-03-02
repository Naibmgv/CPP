#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public :
        Zombie(void);
        ~Zombie();
        void announce( void );
        void setname (std::string name);

    private :
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif