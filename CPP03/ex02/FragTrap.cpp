/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:12:57 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 22:30:54 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitpoints = 100;
    _energypoints = 100;
    _atackdamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    _name = name;
    _hitpoints = 100;
    _energypoints = 100;
    _atackdamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap&    FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assigment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void    FragTrap::hightFivesGuys(void)
{
    if (_hitpoints == 0)
        std::cout << "FragTrap " << BFGCYAN << BOLD << _name << RESET << BFGRED << BOLD << " is already dead!" << RESET << std::endl;
    else
        std::cout << "FragTrap " << BFGCYAN << BOLD << _name << RESET << " ---> " << "Hey guys lets all do an " << BFGYELLOW << BOLD << "HightFive!" << RESET << std::endl;
}
