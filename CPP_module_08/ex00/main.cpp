#include "easyfind.hpp"

int main() {
    // ---- Test 1: Avec un std::vector ----
    std::cout << "--- Test avec std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Trouve ! Valeur : " << *it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // ---- Test 2: Cas d'erreur (élément absent) ----
    try {
        std::cout << "Recherche de 99 (absent) : " << std::endl;
        easyfind(vec, 99);
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception attrapee : " << e.what() << std::endl;
    }

    // ---- Test 3: Avec un std::list ----
    std::cout << "\n--- Test avec std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = easyfind(lst, 2);
        std::cout << "Trouve dans la liste ! Valeur : " << *it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}