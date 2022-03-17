#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed {
    private:
        int fixed_pointer;
        static const int fractional_bit = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed&);
        Fixed& operator=(const Fixed &);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif

