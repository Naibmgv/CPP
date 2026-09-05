#include "Span.hpp"

int main()
{
    std::cout << "=== 1. Test classique du sujet ===" << std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span : " << sp.shortestSpan() << " (Attendu: 2)" << std::endl;
        std::cout << "Longest span  : " << sp.longestSpan()  << " (Attendu: 14)" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. Test avec un range de 15 000 elements ===" << std::endl;
    try
    {
        Span bigSpan(15000);
        std::vector<int> v;

        // Remplissage d'un vector temporaire avec des valeurs aléatoires
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (int i = 0; i < 15000; ++i)
        {
            v.push_back(std::rand());
        }

        // Utilisation de ta fonction template avec la plage d'itérateurs
        bigSpan.addNumber(v.begin(), v.end());

        std::cout << "Shortest span : " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span  : " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n=== 3. Test des exceptions (FullSpanException) ===" << std::endl;
    try
    {
        Span tinySpan(2);
        tinySpan.addNumber(42);
        tinySpan.addNumber(84);
        tinySpan.addNumber(100); // Doit throw FullSpanException !
    }
    catch (const Span::FullSpanException& e)
    {
        std::cout << "Succes ! Exception attrapee : " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Autre exception attrapee : " << e.what() << std::endl;
    }

    std::cout << "\n=== 4. Test des exceptions (NoSpanException) ===" << std::endl;
    try
    {
        Span emptySpan(5);
        emptySpan.addNumber(10); // Un seul nombre, impossible de calculer un span !
        std::cout << emptySpan.shortestSpan() << std::endl;
    }
    catch (const Span::NoSpanException& e)
    {
        std::cout << "Succes ! Exception attrapee : " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Autre exception attrapee : " << e.what() << std::endl;
    }

    return 0;
}