/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:22:25 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/15 16:25:15 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    
}