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
# include <utility>
# include <algorithm>
# include <deque>
# include <iomanip>

class PmergeMe
{
	public :
        PmergeMe(char **input) {
			convert(input);
		}
        PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}
        PmergeMe& operator=(const PmergeMe& other){
            if (this != &other) {
				_vec = other._vec;
				_deq = other._deq;
			}
            return *this;
        }
        ~PmergeMe() {}

        std::vector<int> _vec;
		std::deque<int> _deq;

        template <typename Container>
		bool oddChecker(const Container& mainChain)
		{
			return mainChain.size() % 2;
		}

		void convert(char **input);
        void mergeInsertSort(std::vector<int>& mainChain);
		void mergeInsertSort(std::deque<int>& mainChain);
};

#endif