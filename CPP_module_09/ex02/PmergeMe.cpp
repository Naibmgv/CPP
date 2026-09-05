#include "PmergeMe.hpp"

void PmergeMe::convert(char **input)
{
    for (int i = 0; input[i]; i++){
        _vec.push_back(std::strtol(input[i], NULL, 10));
	}
	for (int i = 0; input[i]; i++) {
        _deq.push_back(std::strtol(input[i], NULL, 10));
	}
}

int jacobsthal2(int n)
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


// ================= vector =================== //


std::vector<int> generate_jacobsthal_vec(int size) 
{
    std::vector<int> tmp;
    if (size < 2) return tmp;

    int i = 3;
    while (true) 
	{
        int j = jacobsthal2(i);
        if (j >= size - 1) 
		{
            tmp.push_back(size - 1);
            break;
        }
        tmp.push_back(j);
        i++;
    }
    return tmp;
}

void PmergeMe::mergeInsertSort(std::vector<int>& mainChain)
{
	if (mainChain.size() <= 1) return ;
	int odd = -1;
	if (oddChecker(mainChain)) {
		odd = mainChain.back();
		mainChain.pop_back();
	}
	std::vector< std::pair<int, int> > pairs;
	for (std::size_t i = 0; i < mainChain.size(); i += 2)
	{
		pairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
		if (pairs.back().first < pairs.back().second) 
			std::swap (pairs.back().first, pairs.back().second);
	}
	std::vector<int> tmp;
	for (std::size_t i = 0; i < pairs.size(); i++)
		tmp.push_back(pairs[i].first);
	mergeInsertSort(tmp);
	std::vector<int> bigGuys(tmp);
	std::vector<int> pend;
	for (std::size_t i = 0; i < tmp.size(); i++)
	{
		for (std::size_t j = 0; j < pairs.size(); j++)
		{
			if (tmp[i] == pairs[j].first)
			{
				pend.push_back(pairs[j].second);
				pairs[j].first = -1;
				break ;
			}
		}
	}
	tmp.insert(tmp.begin(), pend[0]);
	std::vector<int> jacobsthal = generate_jacobsthal_vec(static_cast<int>(pend.size()));
	for (std::size_t i = 0; i < jacobsthal.size(); i++)
	{
		if (i == 0)
		{
			for (std::size_t j = jacobsthal[i]; j > 0; j--)
				tmp.insert(std::lower_bound(tmp.begin(), std::find(tmp.begin(), tmp.end(), bigGuys[j]), pend[j]), pend[j]);
		}
		else
		{
			for (std::size_t j = jacobsthal[i]; j > static_cast<std::size_t>(jacobsthal[i - 1]); j--)
				tmp.insert(std::lower_bound(tmp.begin(), std::find(tmp.begin(), tmp.end(), bigGuys[j]), pend[j]), pend[j]);
		}
	}
	if (odd != -1)
		tmp.insert(std::lower_bound(tmp.begin(), tmp.end(), odd), odd);
	mainChain = tmp;
}

// ================== deque ==================== //

std::deque<int> generate_jacobsthal_deq(int size) 
{
    std::deque<int> tmp;
    if (size < 2) return tmp;

    int i = 3;
    while (true) 
	{
		int j = jacobsthal2(i);
        if (j >= size - 1)
		{
            tmp.push_back(size - 1);
            break;
        }
        tmp.push_back(j);
        i++;
    }
    return tmp;
}

void PmergeMe::mergeInsertSort(std::deque<int>& mainChain)
{
	if (mainChain.size() <= 1) return ;
	int odd = -1;
	if (oddChecker(mainChain)) {
		odd = mainChain.back();
		mainChain.pop_back();
	}
	std::deque< std::pair<int, int> > pairs;
	for (std::size_t i = 0; i < mainChain.size(); i += 2)
	{
		pairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
		if (pairs.back().first < pairs.back().second) 
			std::swap (pairs.back().first, pairs.back().second);
	}
	std::deque<int> tmp;
	for (std::size_t i = 0; i < pairs.size(); i++)
		tmp.push_back(pairs[i].first);
	mergeInsertSort(tmp);
	std::deque<int> bigGuys(tmp);
	std::deque<int> pend;
	for (std::size_t i = 0; i < tmp.size(); i++)
	{
		for (std::size_t j = 0; j < pairs.size(); j++)
		{
			if (tmp[i] == pairs[j].first)
			{
				pend.push_back(pairs[j].second);
				pairs[j].first = -1;
				break ;
			}
		}
	}
	tmp.insert(tmp.begin(), pend[0]);
	std::deque<int> jacobsthal = generate_jacobsthal_deq(static_cast<int>(pend.size()));
	for (std::size_t i = 0; i < jacobsthal.size(); i++)
	{
		if (i == 0)
		{
			for (std::size_t j = jacobsthal[i]; j > 0; j--)
				tmp.insert(std::lower_bound(tmp.begin(), std::find(tmp.begin(), tmp.end(), bigGuys[j]), pend[j]), pend[j]);
		}
		else
		{
			for (std::size_t j = jacobsthal[i]; j > static_cast<std::size_t>(jacobsthal[i - 1]); j--)
				tmp.insert(std::lower_bound(tmp.begin(), std::find(tmp.begin(), tmp.end(), bigGuys[j]), pend[j]), pend[j]);
		}
	}
	if (odd != -1)
		tmp.insert(std::lower_bound(tmp.begin(), tmp.end(), odd), odd);
	mainChain = tmp;
}
