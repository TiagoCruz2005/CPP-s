/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:48:03 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/01 14:47:29 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _num = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    if (num > (INT_MAX >> _fracbits) || num < (INT_MIN >> _fracbits))
        std::cerr << "Warning: value out of range" << std::endl;
    _num = num * (1 << _fracbits);
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    if (num > (INT_MAX >> _fracbits) || num < (INT_MIN >> _fracbits))
        std::cerr << "Warning: value out of range" << std::endl;
    _num = roundf(num * (1 << _fracbits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
        this->_num = other._num;
    return *this;
}

std::ostream&   operator<<(std::ostream& out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed   Fixed::operator+(const Fixed &other) const
{
    return Fixed(toFloat() + other.toFloat());
}

Fixed   Fixed::operator-(const Fixed &other) const
{
    return Fixed(toFloat() - other.toFloat());
}

Fixed   Fixed::operator*(const Fixed &other) const
{
    return Fixed(toFloat() * other.toFloat());
}

Fixed   Fixed::operator/(const Fixed &other) const
{
    return Fixed(toFloat() / other.toFloat());
}

bool    Fixed::operator<(const Fixed &other) const
{
    return _num < other._num;
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return _num <= other._num;
}

bool    Fixed::operator>(const Fixed &other) const
{
    return _num > other._num;
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return _num >= other._num;
}

bool    Fixed::operator==(const Fixed &other) const
{
    return _num == other._num;
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return _num != other._num;
}

int     Fixed::getRawBits(void) const
{
    return _num;
}

void    Fixed::setRawBits(const int raw)
{
    _num = raw;
}

float   Fixed::toFloat(void) const
{
    return (float)_num / (1 << _fracbits); 
}

int     Fixed::toInt(void) const
{
    return _num >> _fracbits;
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed&   Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed&   Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

Fixed&  Fixed::operator++()
{
    ++_num;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_num;
    return tmp;
}

Fixed&  Fixed::operator--()
{
    --_num;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed   tmp(*this);
    --_num;
    return tmp;
}
