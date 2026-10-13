/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:10:12 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/13 20:26:04 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    try
    {
        BitcoinExchange btc;

        btc.loadDataBase("data.csv");
        btc.parseInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}