/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:45:50 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/09 18:05:57 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << BFGMAGEN << BOLD << "Dog Default constructor called" << RESET << std::endl;
    _brain = new Brain();
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog&    Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assigment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
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
