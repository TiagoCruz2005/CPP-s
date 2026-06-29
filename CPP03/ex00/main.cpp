/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:26:31 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/22 19:48:22 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
    ClapTrap    tiago("Tiago");
    ClapTrap    bob("Bob");

    tiago.atack(bob.getName());
    bob.takeDamage(4);

    return (0);
}
