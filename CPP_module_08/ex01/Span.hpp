#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span 
{
    public:

        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        void shortestSpan() const;
        void longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            if ((std::distance(begin, end) + _storage.size()) > _N)
                throw std::out_of_range("Span is out of capacity");
            _storage.insert(_storage.end(), begin, end);
        }

        class FullSpanException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Span is full";
            }
        };

        class NoSpanException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Not enough elements to calculate span";
            }
        };

    private:

        Span();
        std::vector<int>    _storage;
        unsigned int _N;
};

#endif