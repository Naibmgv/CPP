#include "PmergeMe.hpp"

void PmergeMe::oddChecker()
{
    if (_vec.size() % 2)
    {
        _odd = _vec.back();
        _vec.pop_back();
    }
}

void PmergeMe::convert_vec(const char **input)
{
    for (int i = 0; input[i]; i++)
        _vec.push_back(std::strtol(input[i], NULL, 10));
    oddChecker();
}

void PmergeMe::sort()
{
    std::vector< std::pair<int, int> > pairVec;
    for (int i = 0; i < _vec.size(); i += 2)
        pairVec.push_back(std::make_pair(_vec[i], _vec[i + 1]));
    std::vector<int> tmp;
    
}
