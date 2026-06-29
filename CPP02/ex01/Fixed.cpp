/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:49:17 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/19 00:57:41 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    if (number > (INT_MAX >> _fracbits) || number < (INT_MIN >> _fracbits))
        std::cout << "Warning: value out of range" << std::endl;
    _number = number << _fracbits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    _number = roundf(number * (1 << _fracbits));
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

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
        this->_number = other._number;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_number;
}

void Fixed::setRawBits(const int raw)
{
    this->_number = raw;
}

float Fixed::toFloat() const
{
    return (float)_number / (1 << _fracbits);
}

int Fixed::toInt() const
{
    return _number >> _fracbits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
