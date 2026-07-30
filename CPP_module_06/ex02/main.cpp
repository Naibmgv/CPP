#include "Base.hpp"

Base* generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
    {
        std::cout << "Instance A créée." << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Instance B créée." << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Instance C créée." << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "Type A identifie(pointer)" << std::endl;
    }
        
    else if (dynamic_cast<B*>(p))
    {
         std::cout << "Type B identifie(pointer)" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Type C identifie(pointer)" << std::endl;
    } 
    else 
    {
        std::cout << "Type inconnu" << std::endl;
    }
}

void identify(Base& ref)
{
    try 
    {
        A& a = dynamic_cast<A&>(ref);
        (void)a;
        std::cout << "Type A identified(reference)" << std::endl;
    } 
    catch (const std::exception& e) {}
    try
    {
        B& b = dynamic_cast<B&>(ref);
        (void)b;

        std::cout << "Type B identified(reference)" << std::endl;
    }
    catch (const std::exception& e) {}
    try
    {
        C& c = dynamic_cast<C&>(ref);
        (void)c;

        std::cout << "Type C identified(reference)" << std::endl;
    }
   catch (const std::exception& e) {}
}

int main()
{
    std::srand(std::time(NULL));

    std::cout << "=== TEST 1 : Génération aléatoire et Identification ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Essai " << i + 1 << " ---" << std::endl;
        
        Base* ptr = generate();
        
        identify(ptr);   
        identify(*ptr); 

        delete ptr;     
    }

    std::cout << "\n=== TEST 2 : Test avec un pointeur NULL ou invalide ===" << std::endl;
    Base* nullPtr = NULL;
    identify(nullPtr); 

    return 0;
}