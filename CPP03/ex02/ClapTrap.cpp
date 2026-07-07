/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:06:56 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 17:02:37 by tide-pau         ###   ########.fr       */
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
    if (_hitpoints == 0)
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << BFGRED << BOLD << " is already dead!" << RESET << std::endl;
    else if (_energypoints != 0)
    {
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << " attacks " << BFGYELLOW << BOLD << target << RESET << std::endl;
        _energypoints--;
    }
    else
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << " has no more energy points to perform an attack" << std::endl; 
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints == 0)
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << BFGRED << BOLD << " is already dead!" << RESET << std::endl;
    else if (((int)_hitpoints - (int)amount) < 0)
    {
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << " took " << BFGRED << BOLD << amount << RESET << " points of damage!" << std::endl;
        _hitpoints = 0;
    }
    else
    {
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << " took " << BFGRED << BOLD << amount << RESET << " points of damage!" << std::endl;
        _hitpoints -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitpoints == 0)
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << BFGRED << BOLD << " is already dead!" << RESET << std::endl;
    else if (_energypoints == 0)
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << " has no more energy points to perform repair!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << BFGCYAN << BOLD << _name << RESET << " regenerates!" << std::endl;
        _energypoints--;
        _hitpoints += amount;
    }
}

unsigned int    ClapTrap::getAttackDamage() const
{
    return _atackdamage;
}

std::string&    ClapTrap::getName()
{
    return _name;
}
