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

        std::map<std::string, float> data;

    public :

        BitCoinExchange(const std::string& data_filename);
        BitCoinExchange(const BitCoinExchange& other);
        BitCoinExchange& operator=(const BitCoinExchange& other);
        ~BitCoinExchange();

        int copy_data(const std::string& filename);

};

#endif