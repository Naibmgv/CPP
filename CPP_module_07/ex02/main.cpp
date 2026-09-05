#include "Array.hpp"

int main(void)
{
    // Type simple
    Array<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
 
    Array<int> b(a); // copie
    b[0] = 42;
    std::cout << "a[0] = " << a[0] << " (doit rester 1)" << std::endl;
    std::cout << "b[0] = " << b[0] << " (doit etre 42)" << std::endl;
 
    Array<int> c;
    c = a; // assignation
    c[1] = 99;
    std::cout << "a[1] = " << a[1] << " (doit rester 2)" << std::endl;
    std::cout << "c[1] = " << c[1] << " (doit etre 99)" << std::endl;
 
    // Type complexe
    Array<std::string> s(2);
    s[0] = "salut";
    s[1] = "les gens";
    std::cout << s[0] << " " << s[1] << std::endl;
 
    // Acces hors bornes
    try
    {
        a[100];
    }
    catch (const std::exception& e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }
 
    return 0;
}