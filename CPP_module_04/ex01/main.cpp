#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===== BASIC NEW/DELETE (as Animal*) =====\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    delete j;
    delete i;
    
    std::cout << "\n===== DEEP COPY (Dog) =====\n";
    Dog a;
    a.setIdeas(0, "bone");
    Dog b(a);                 // copy constructor
    a.setIdeas(0, "steak");   // change original
    std::cout << "a[0] = " << a.getIdeas(0) << "\n";
    std::cout << "b[0] = " << b.getIdeas(0) << "\n";

    Dog c;
    c = a;                    // operator=
    a.setIdeas(0, "fish");    // change original again
    std::cout << "a[0] = " << a.getIdeas(0) << "\n";
    std::cout << "c[0] = " << c.getIdeas(0) << "\n";

    std::cout << "\n===== DEEP COPY (Cat) =====\n";
    Cat x;
    x.setIdeas(0, "nap");
    Cat y(x);
    x.setIdeas(0, "hunt");
    std::cout << "x[0] = " << x.getIdeas(0) << "\n";
    std::cout << "y[0] = " << y.getIdeas(0) << "\n";

    Cat z;
    z = x;
    x.setIdeas(0, "purr");
    std::cout << "x[0] = " << x.getIdeas(0) << "\n";
    std::cout << "z[0] = " << z.getIdeas(0) << "\n";

    std::cout << "\n===== END =====\n";
    return 0;
}