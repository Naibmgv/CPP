#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        float   toFloat(void) const;
        int     toInt(void) const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 _raw;
        static const int    _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif