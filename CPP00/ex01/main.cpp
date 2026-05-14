/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:20:27 by tide-pau          #+#    #+#             */
/*   Updated: 2026/05/13 17:40:38 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

int main()
{
    std::string line;
    PhoneBook phonebook;

    std::cout << CLEAR << std::endl;
    std::cout << GENERICMESSAGE << std::endl;
    while (true)
    {
        if (!getline(std::cin, line))
            return 1;
        if (line == "ADD")
            phonebook.add();
        else if (line == "SEARCH")
        {
            if (phonebook.search())
                continue ;
        }
        else if (line == "EXIT")
            break ;
        else
        {
            std::cout << CLEAR << std::endl;
            std::cout << INCORRECTINPUT << std::endl;
        }
            
    }
    return 0;
}
