/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:15:20 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/13 17:26:45 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    _type = "Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assigment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << BFGCYAN << BOLD << _type << RESET << " makes some generic sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}
