/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:07:16 by tide-pau          #+#    #+#             */
/*   Updated: 2026/04/22 13:29:03 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void) {}

Harl::Harl(std::string& level)
{
    _level = level;
}

Harl::~Harl(void)
{
    std::cout << std::endl << "\033[1mHarl as been terminated\033[0m" << std::endl;
}

void    Harl::debug(void)
{
    std::cout << std::endl << DEBUG << std::endl;
}

void    Harl::info(void)
{
    std::cout << std::endl << INFO << std::endl;
}

void    Harl::warning(void)
{
    std::cout << std::endl << WARNING << std::endl;
}

void    Harl::error(void)
{
    std::cout << std::endl << ERROR << std::endl;
}

void    Harl::basic(void)
{
    std::cout << std::endl << BASIC << std::endl;
}

void    Harl::complain(void)
{
    std::size_t i;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    i = 0;
    while (i < 4)
    {
        if (levels[i] == _level)
            break ;
        i++;
    }
    switch (i)
    {
        case (0):
            debug();
        case (1):
            info();
        case (2):
            warning();
        case (3):
            error();
            break ;
        default:
            basic();
    }
}
