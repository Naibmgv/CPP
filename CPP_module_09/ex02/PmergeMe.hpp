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
#include <utility>
#include <algorithm>

class PmergeMe
{
    private :
        int _odd;
		std::vector<int> _jacobsthal;
	public :
        PmergeMe(char **input) {
			convert_vec(input);
		}
        PmergeMe(const PmergeMe& other) : _vec(other._vec) {}
        PmergeMe& operator=(const PmergeMe& other){
            if (this != &other) {
                _vec = other._vec;
                _odd = other._odd;
            }
            return *this;
        }
        ~PmergeMe() {}

        std::vector<int> _vec;
        void convert_vec(char **input);
        void mergeInsertSort(std::vector<int>& mainChain);
        void oddChecker();
		int jacobsthal(int n);
		void jacobsthal2(int size);
};


#endif