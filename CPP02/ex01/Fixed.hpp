/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:56:24 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/19 00:56:02 by tide-pau         ###   ########.fr       */
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
        int _number;
        static const int _fracbits = 8;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        
        int getRawBits(void) const ;
        void    setRawBits(const int raw);
        
        float toFloat(void) const ;
        int toInt(void) const ;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

# endif