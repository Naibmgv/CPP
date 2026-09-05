#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &src) : _N(src._N), _storage(src._storage) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_storage = other._storage;
	}
	return *this;
}

void Span::addNumber(int number)
{
    if (_storage.size() >= _N)
        throw FullSpanException();
    _storage.insert(_storage.end(), number);
}

int Span::longestSpan() const
{
    if (_storage.size() < 2)
		throw NoSpanException();
	int min = *std::min_element(_storage.begin(), _storage.end());
	int max = *std::max_element(_storage.begin(), _storage.end());

	return max - min;
}

int Span::shortestSpan() const
{
	if (_storage.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp = _storage;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = tmp[1] - tmp[0];
	for (std::size_t i = 0; i < tmp.size() - 1; i++)
	{
		if ((tmp[i + 1] - tmp[i]) < minSpan)
			minSpan = tmp[i + 1] - tmp[i];
	}
	return minSpan;
}
