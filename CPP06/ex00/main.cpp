/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:35:15 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/21 13:43:38 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (std::cout << "Invalid number of arguments" << std::endl, 1);
    std::string literal = argv[1];
    ScalarConverter::convert(literal);
}