/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:45:50 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/06 16:46:09 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << BFGCYAN << BOLD << "Dog Default constructor called" << RESET << std::endl;
    _brain = new Brain();
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << BFGCYAN << BOLD << "Dog copy constructor called" << RESET << std::endl;
    _brain = new Brain(*other._brain);
}

Dog&    Dog::operator=(const Dog& other)
{
    std::cout << BFGCYAN << BOLD << "Dog copy assigment operator called" << RESET << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << BFGCYAN << BOLD << "Dog destructor called" << RESET << std::endl;
    delete _brain;
}

void    Dog::makeSound() const
{
    std::cout << BFGCYAN << BOLD << _type << RESET << ": WOOF!" << std::endl;
}


void    Dog::setIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return _brain->getIdea(index);
}

std::string Dog::getType() const
{
    return _type;
}
