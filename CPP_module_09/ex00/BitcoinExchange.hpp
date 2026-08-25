#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>

class BitCoinExchange
{
    private :

        std::map<std::string, double> _data;

    public :

        BitCoinExchange();
        BitCoinExchange(const BitCoinExchange& other);
        BitCoinExchange& operator=(const BitCoinExchange& other);
        ~BitCoinExchange() {}

        bool data_copy(const std::string& filename);
        bool output(const std::string& fileName);
};

#endif