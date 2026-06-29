/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 20:46:32 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/26 19:53:49 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Delault constructor called" << std::endl;
    _name = "Default";
    _hitpoints = 10;
    _energypoints = 10;
    _atackdamage = 0;
}

ClapTrap::ClapTrap(const std::string& name)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
    _name = name;
    _hitpoints = 10;
    _energypoints = 10;
    _atackdamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap    &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assigment operator called" << std::endl;
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
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void    ClapTrap::atack(const std::string& target)
{
    if (_energypoints != 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _atackdamage << " pints of damage!" << std::endl;
        _energypoints--;
    }
    else
        std::cout << "ClapTrap " << _name << " has no more energy points to perform an attack" << std::endl; 
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
        _hitpoints -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energypoints == 0)
        std::cout << "ClapTrap " << _name << " has no more energy points to perform repair!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " regenerates!" << std::endl;
        _energypoints--;
        _hitpoints += amount;
    }
}
