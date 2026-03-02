#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain* brain;
    public :
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();

        virtual void makeSound(void) const;
        std::string getIdeas(int index);
        void    setIdeas(int index, const std::string& idea);
};

#endif