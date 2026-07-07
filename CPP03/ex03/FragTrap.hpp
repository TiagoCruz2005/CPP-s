/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 21:15:44 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/06 21:21:23 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class   FragTrap : virtual  public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        FragTrap    &operator=(const FragTrap& other);
        ~FragTrap();
        void    hightFivesGuys(void);
};

# endif