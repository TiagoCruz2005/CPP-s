/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:42:38 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/19 16:33:20 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed x(17);
    Fixed y(10);
    
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    std::cout << std::endl;
    std::cout << "Sum: " << x + y << std::endl;
    std::cout << "Substraction: " << x - y << std::endl;
    std::cout << "Product: " << x * y << std::endl;
    std::cout << "Division: " << x / y << std::endl;
    std::cout << "Pre increment: " << ++x << " | " << ++y << std::endl;
    std::cout << "Pre decrement: " << --x << " | " << --y << std::endl;
    std::cout << "Pos increment: " << x++ << " | " << y++ << std::endl;
    std::cout << "Pos decrement: " << x-- << " | " << y-- << std::endl;
    
    return 0;
}
