/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 21:16:49 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/07 12:13:49 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "Default";
    _hitpoints = 100;
    _energypoints = 50;
    _atackdamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap constructor called" << std::endl;
    _name = name;
    _hitpoints = 100;
    _energypoints = 50;
    _atackdamage = 30;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap assigment operator called" << std::endl;
    return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap is speaking...\nMy Name is: " << BFGYELLOW << BOLD << _name << RESET << "\nMy ClapTrap Name is: " << BFGCYAN << BOLD << ClapTrap::_name << RESET << std::endl;
}
