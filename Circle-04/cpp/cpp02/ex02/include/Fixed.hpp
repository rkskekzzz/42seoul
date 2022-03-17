#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixed_pointer;
        static const int fractional_bit = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed&);

        Fixed& operator=(const Fixed &);
        Fixed operator+(const Fixed &) const;
        Fixed operator-(const Fixed &) const;
        Fixed operator*(const Fixed &) const;
        Fixed operator/(const Fixed &) const;

        Fixed& operator++(void);
        Fixed& operator--(void);
        const Fixed operator++(int);
        const Fixed operator--(int);

        bool operator<(const Fixed& rvalue) const;
        bool operator>(const Fixed& rvalue) const;
        bool operator<=(const Fixed& rvalue) const;
        bool operator>=(const Fixed& rvalue) const;
        bool operator==(const Fixed& rvalue) const;
        bool operator!=(const Fixed& rvalue) const;

        static const Fixed& max(const Fixed& value1, const Fixed& value2);
        static const Fixed& min(const Fixed& value1, const Fixed& value2);

        int toInt(void) const;
        float toFloat(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif

