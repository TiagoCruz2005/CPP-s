/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 23:27:56 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/13 17:25:39 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
    _type = "Animal";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal&  Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assigment operator called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "Animal does some generic sound" << std::endl;
}

std::string    Animal::getType() const
{
    return _type;
}
