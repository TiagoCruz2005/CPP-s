/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:23:20 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/16 16:25:29 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
# include <iostream>
# include <cstring>
# include <cctype>

int main(int argc, char *argv[])
{
    Rpn rpn;
    
    if (argc != 2)
        return (std::cout << "Error" << std::endl, 1);
    if (!argv[1] || !argv[1][0])
        return (std::cout << "Error" << std::endl, 1);
    try
    {
        rpn.parseArg(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
