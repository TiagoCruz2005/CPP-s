/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 21:16:52 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 22:19:16 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(const std::string& other);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap&    operator=(const DiamondTrap& other);
        ~DiamondTrap();
        using ScavTrap::atack;
        void    whoAmI();
};

# endif