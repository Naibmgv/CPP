#include "Span.hpp"

void Span::addNumber(int number)
{
    if (_storage.size() >= _N)
        throw FullSpanException();
    _storage.insert(_storage.end(), number);
}

void Span::longestSpan()
{
    
}
