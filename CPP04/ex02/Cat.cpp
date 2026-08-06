/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:45:16 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/06 16:45:37 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << BFGGREEN << BOLD << "Cat default constructor called " << RESET << std::endl;
    _brain = new Brain();
    _type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << BFGGREEN << BOLD << "Cat copy constructor called" << RESET << std::endl;
    _brain = new Brain(*other._brain);
}

Cat&    Cat::operator=(const Cat& other)
{
    std::cout << BFGGREEN << BOLD << "Cat copy assigment operator called" << RESET << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << BFGGREEN << BOLD << "Cat destructor called" << RESET << std::endl;
    delete _brain;
}

void    Cat::makeSound() const
{
    std::cout << BFGGREEN << BOLD << _type << RESET << ": MEOW!" << std::endl;
}

void    Cat::setIdea(int index, const std::string& idea)
{
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return _brain->getIdea(index);
}

std::string Cat::getType() const
{
    return _type;
}
