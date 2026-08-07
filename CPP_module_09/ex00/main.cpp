#include "BitcoinExchange.hpp"

int main(int ac, char av**)
{
    if (ac != 2)
    {
        std::cerr << "Erreur : fichier invalide ou manquant" << std::endl;
        return 1;
    }
    std::string data_file = argv[1];
    if (data_file != "data.csv")
    {
        std::cerr << "Erreur : fichier invalide ou ouverture impossible" << std::endl;
        return 1;
    }

}
