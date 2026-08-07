#include "BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange(const std::string& data_filename) : data(copy_data(data_filename))
{
    
}

BitCoinExchange::BitCoinExchange(const std::string& )
{
    
}

int BitCoinExchange::copy_data(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return 1;
    
    return 0;
}
