/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:14:26 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/08 15:36:43 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called "<< std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat&    Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assigment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << BFGCYAN << BOLD << _type << RESET << ": MEOW!" << std::endl;
}
