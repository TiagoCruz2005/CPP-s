/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:49:54 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/06 16:44:53 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Brain.hpp"

Brain::Brain()
{
    std::cout << BFGMAGEN << BOLD << "Brain Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    std::cout << BFGMAGEN << BOLD << "Brain copy constructor called" << RESET << std::endl;
}

Brain&   Brain::operator=(const Brain& other)
{
    std::cout << BFGMAGEN << BOLD << "Brain copy assigment operator called" << RESET << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << BFGMAGEN << BOLD << "Brain destructor called" << RESET << std::endl;
}

void    Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return  _ideas[index];
    return "";
}
