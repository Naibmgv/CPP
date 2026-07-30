#include "iter.hpp"

template <typename T>
void printsmth(const T& smth)
{
    std::cout << smth << std::endl;
}

template <typename T>
void incrementsmth(T& smth)
{
    smth++;
}

int main(void)
{
    std::cout << "--- Test Entiers ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original : ";
    ::iter(intArray, intLen, printsmth<int>);
    std::cout << std::endl;

    // On modifie les éléments via iter
    ::iter(intArray, intLen, incrementsmth<int>);

    std::cout << "Apres incrementation : ";
    ::iter(intArray, intLen, printsmth<int>);
    std::cout << std::endl << std::endl;


    // ---- Test 2 : Tableau de chaînes (non-const) ----
    std::cout << "--- Test Strings ---" << std::endl;
    std::string strArray[] = {"un", "deux", "trois"};
    std::size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original : ";
    ::iter(strArray, strLen, printsmth<std::string>);
    std::cout << std::endl << std::endl;


    // ---- Test 3 : Tableau d'entiers CONSTANTS ----
    std::cout << "--- Test Const Entiers ---" << std::endl;
    const int constIntArray[] = {10, 20, 30};
    std::size_t constIntLen = sizeof(constIntArray) / sizeof(constIntArray[0]);

    // On ne peut qu'afficher (printsmth prend une const ref, donc ça passe !)
    std::cout << "Const Array : ";
    ::iter(constIntArray, constIntLen, printsmth<int>);
    std::cout << std::endl;

    // La ligne suivante ne compilerait pas (et c'est normal/attendu) :
    // ::iter(constIntArray, constIntLen, incrementsmth<int>);

    return 0;
}