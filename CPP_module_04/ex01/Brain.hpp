#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public :
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        void setIdeas(int index, const std::string& new_val);
        std::string getIdeas(int index);
    private :
        std::string ideas[100];
};

#endif