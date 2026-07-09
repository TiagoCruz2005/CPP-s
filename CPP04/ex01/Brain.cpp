/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:49:54 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/09 18:04:32 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain&   Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assigment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
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
