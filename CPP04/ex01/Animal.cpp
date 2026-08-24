/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:44:25 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/06 16:38:28 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"

Animal::Animal()
{
    std::cout << BFGYELLOW << BOLD << "Animal Default constructor called" << RESET << std::endl;
    _type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << BFGYELLOW << BOLD << "Animal copy constructor called" << RESET << std::endl;
    *this = other;
}

Animal&  Animal::operator=(const Animal& other)
{
    std::cout << BFGYELLOW << BOLD << "Animal copy assigment operator called" << RESET << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << BFGYELLOW << BOLD << "Animal destructor called" << RESET << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << BFGYELLOW << BOLD << "Animal does some generic sound" << RESET << std::endl;
}

std::string    Animal::getType() const
{
    return _type;
}
