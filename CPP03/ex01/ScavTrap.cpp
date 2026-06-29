/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:42:26 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/26 19:56:53 by tide-pau         ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}


