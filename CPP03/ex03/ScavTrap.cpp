/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 21:16:03 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 21:16:05 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    _hitpoints = 100;
    _energypoints = 50;
    _atackdamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    _hitpoints = 100;
    _energypoints = 50;
    _atackdamage = 20;
}

ScavTrap&    ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap assigment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << BFGCYAN << BOLD << _name << RESET << " is now in GateKeeper mode" << std::endl;
}
