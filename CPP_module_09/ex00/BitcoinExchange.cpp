#include "BitcoinExchange.hpp"

BitCoinExchange::BitCoinExchange()
{

}

BitCoinExchange::BitCoinExchange(const BitCoinExchange& other)
{
    _data = other._data;
}

BitCoinExchange& BitCoinExchange::operator=(const BitCoinExchange& other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

bool isLeapYear(long year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool    lineParser(const std::string& line)
{
    if (line.size() < 13 || !isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) || line[4] != '-' ||
        !isdigit(line[5]) || !isdigit(line[6]) || line[7] != '-' || !isdigit(line[8]) || !isdigit(line[9]) ||
        line[10] != ' ' || line[11] != '|' || line[12] != ' ' || (!isdigit(line[13]) && line[13] != '-'))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    char *end = NULL;
    double val = std::strtod(line.c_str() + 13, &end);
    if (*end != '\0')
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (val < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    std::string yearStr = line.substr(0, 4);
    std::string monthStr = line.substr(5, 2);
    std::string dayStr = line.substr(8, 2);
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long year = std::strtol(yearStr.c_str(), &end, 10);
    if (*end != '\0') 
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    long month = std::strtol(monthStr.c_str(), &end, 10);
    if (*end != '\0') 
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    long day = std::strtol(dayStr.c_str(), &end, 10);
    if (*end != '\0') 
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (year < 2008 || month < 1 || month > 12 || day < 1) 
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (month == 2 && isLeapYear(year))
        daysInMonth[2] = 29;
    if (day > daysInMonth[month]) 
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    return 1;
}

bool BitCoinExchange::output(const std::string& fileName)
{
    std::ifstream inFile(fileName.c_str());

    if (!inFile.is_open())
    {
        std::cerr << "Error file opening1\n";
        return false;
    }
    std::string line;
    std::getline(inFile, line);
    while (getline(inFile, line))
    {
        if (!lineParser(line)) continue;

        std::stringstream ss(line);
        std::string tmp;
        std::string tmp1;
        double val;
        
        std::getline(ss, tmp, ' ');
        std::getline(ss, tmp1);
        val = strtod(tmp1.c_str() + 2, NULL);
        
        std::map<std::string, double>::const_iterator it = _data.upper_bound(tmp);
        if (it != _data.begin())
            it--;
        std::cout << tmp << " => " << val << " = " << val * it->second << std::endl;
    }
    return true;
}

bool BitCoinExchange::data_copy(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error file oppening\n";
        return false;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string tmp1;
        std::string tmp2;
        double val;

        std::getline(ss, tmp1, ',');
        std::getline(ss, tmp2);
        val = std::strtod(tmp2.c_str(), NULL);
        _data[tmp1] = val;
    }
    file.close();
    return true;
}
