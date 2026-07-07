/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:58:43 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 17:19:30 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
    ClapTrap bob("bob");
    ScavTrap boby("boby");
    FragTrap lou("lou");
    
    bob.atack(boby.getName());
    boby.takeDamage(bob.getAttackDamage());
    boby.atack(lou.getName());
    lou.takeDamage(boby.getAttackDamage());
    
    std::cout << std::endl;
    
    FragTrap    loucopy(lou);
    loucopy.beRepaired(20);
    lou.atack(boby.getName());
    boby.takeDamage(lou.getAttackDamage());
    
    std::cout << std::endl;
    
    boby.takeDamage(500);
    boby.beRepaired(500);
    ScavTrap dummy;
    boby = dummy;
    boby.takeDamage(50);

    std::cout << std::endl;
    
    lou.hightFivesGuys();
    loucopy.takeDamage(500);
    loucopy.hightFivesGuys();
}
