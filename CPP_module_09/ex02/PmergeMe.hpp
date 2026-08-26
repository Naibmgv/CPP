#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <climits>
# include <vector>

class PmergeMe
{
    private :
        int _odd;
        std::vector<int> _vec;
    public :
        PmergeMe(const char **input) {}
        PmergeMe(const PmergeMe& other) : _vec(other._vec) {}
        PmergeMe& operator=(const PmergeMe& other){
            if (this != &other) {
                _vec = other._vec;
                _odd = other._odd;
            }
            return *this;
        }
        ~PmergeMe() {}

        void convert_vec(const char **input);
        void sort();
        void oddChecker();

};

#endif