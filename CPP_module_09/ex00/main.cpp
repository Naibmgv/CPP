#include "BitcoinExchange.hpp"

bool input_Parsing(const std::string& fileName)
{
    std::ifstream is(fileName.c_str());

    if (!is.is_open())
    {
        std::cerr << "cannot open file\n";
        return false;
    }
    std::string line;
    std::getline(is, line);
    if (line != "date | value")
    {
        std::cerr << "Parsing Error(header)\n";
        return false;
    }
    is.close();
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Erreur : fichier invalide ou manquant" << std::endl;
        return 1;
    }
    if (!input_Parsing(av[1]))
        return 1;
    BitCoinExchange test;
    if (!test.data_copy("data.csv") || !test.output(av[1])) 
        return 1;
}
