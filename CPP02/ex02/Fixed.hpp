/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:16:42 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/19 02:50:01 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

class Fixed
{
    private:
        int _num;
        static const int _fracbits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &other);
        ~Fixed();
        
        Fixed   &operator=(const Fixed &other);
        Fixed   operator+(const Fixed &other) const;
        Fixed   operator-(const Fixed &other) const;
        Fixed   operator*(const Fixed &other) const;
        Fixed   operator/(const Fixed &other) const;
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);
        bool    operator<(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator>(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;
        
        static  Fixed& min(Fixed& a, Fixed& b);
        static  const Fixed& min(const Fixed& a, const Fixed& b);
        static  Fixed& max(Fixed& a, Fixed& b);
        static  const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits(void) const;
        void    setRawBits(const int raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);

# endif