#include "PmergeMe.hpp"

int compteur = 0;

void PmergeMe::oddChecker()
{
    if (_vec.size() % 2)
    {
        _odd = _vec.back();
        _vec.pop_back();
    }
}

void PmergeMe::convert_vec(char **input)
{
    for (int i = 0; input[i]; i++)
        _vec.push_back(std::strtol(input[i], NULL, 10));
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {
        int c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

void PmergeMe::jacobsthal2(int size)
{
	int j = 0;
	for (int i = 3; j < size; i++)
	{
		j = jacobsthal(i);
		_jacobsthal.push_back(j);
	}
}

void PmergeMe::mergeInsertSort(std::vector<int>& mainChain)
{
	if (mainChain.size() <= 1) return ;
	int odd = 0;
	if (mainChain.size() % 2) {
		odd = mainChain.back();
		mainChain.pop_back();
	}
	std::vector< std::pair<int, int> > pairs;
	for (int i = 0; i < static_cast<int>(mainChain.size()); i += 2)
	{
		pairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
		if (pairs.back().first < pairs.back().second) 
			std::swap(pairs.back().first, pairs.back().second);
	}
	std::vector<int> tmp;
	for (int i = 0; i < static_cast<int>(pairs.size()); i++)
		tmp.push_back(pairs[i].first);
	mergeInsertSort(tmp);
	// std::vector<int> pending;
	// for (int i = 0; i < static_cast<int>(mainChain.size()); i++)
	// {
	// 	for (int j = 0; j < static_cast<int>(pairs.size()); j++)
	// 	{
	// 		if (mainChain[i] == pairs[j].first)
	// 		{
	// 			pending.push_back(pairs[j].second);
	// 			pairs[j].first = -1;
	// 		}
	// 	}
	// }
	// mainChain.insert(mainChain.begin(), pending[0]);
	// jacobsthal2(mainChain.back());
	compteur++;
	std::cout << compteur << " : ";
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
