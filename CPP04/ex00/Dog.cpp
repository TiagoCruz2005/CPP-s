/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 23:58:27 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/13 17:26:14 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog Default constructor called" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << BFGCYAN << BOLD << _type << RESET << ": WOOF!" << std::endl;
}
