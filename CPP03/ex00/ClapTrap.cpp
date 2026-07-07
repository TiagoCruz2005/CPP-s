/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:04:21 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 13:58:42 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    _hitpoints = 10;
    _energypoints = 10;
    _atackdamage = 0;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "Constructor called" << std::endl;
    _name = name;
    _hitpoints = 10;
    _energypoints = 10;
    _atackdamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energypoints = other._energypoints;
        _atackdamage = other._atackdamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::atack(const std::string& target)
{
    if (_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    if (_energypoints != 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << std::endl;
        _energypoints--;
    }
    else
        std::cout << "ClapTrap " << _name << " has no more energy points to perform an attack" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (((int)_hitpoints - (int)amount) < 0)
    {
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitpoints = 0;
    }
    if (_hitpoints != 0)
    {
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitpoints -= amount;
    }
    else
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energypoints != 0)
    {
        std::cout << "ClapTrap " << _name << " regenerates" << amount << " hitpoints!" << std::endl;
        _hitpoints += amount;
        _energypoints--;
    }
    else
        std::cout << "ClapTrap " << _name << " has no more energypoints to perform repair" << std::endl;
}

std::string     ClapTrap::getName()
{
    return _name;
}
