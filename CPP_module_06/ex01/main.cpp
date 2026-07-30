#include "Serializer.hpp"

int main() 
{
    Data tmp;
    tmp.str = "Je s'apelle Grout";
    tmp.i = 2026;

    Data* oldptr = &tmp;

    std::cout << "--- AVANT SÉRIALISATION ---" << std::endl;
    std::cout << "Adresse d'origine : " << oldptr << std::endl;
    std::cout << "---------------------------\n" << std::endl;

    uintptr_t raw = Serializer::serialize(oldptr);
    std::cout << "Valeur sérialisée : " << raw << std::endl;
    std::cout << "---------------------------\n" << std::endl;

    Data* newptr = Serializer::deserialize(raw);

    std::cout << "--- APRÈS DÉSERIALISATION ---" << std::endl;
    std::cout << "Adresse obtenue   : " << newptr << std::endl;
    std::cout << "---------------------------\n" << std::endl;

    if (oldptr == newptr) {
        std::cout << "Succès ! Les pointeurs sont identiques." << std::endl;
    } else {
        std::cout << "Échec..." << std::endl;
    }

    return 0;
}
