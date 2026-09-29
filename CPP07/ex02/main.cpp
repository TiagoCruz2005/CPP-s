/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:01:00 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/29 18:17:21 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Array.hpp"

int main()
{
    Array<int> n(3);
    Array<int> big(50);
    Array<std::string> str(3);

    for (unsigned int i = 0; i < 50; i++)
        big[i] = i;

    n[0] = 7;
    n[1] = 9;
    n[2] = 5;

    str[0] = "ola";
    str[1] = "boas";
    str[2] = "como vais";

    std::cout << "Int array size: " << n.size() << std::endl;
    std::cout << "String array size: " << str.size() << std::endl;

    std::cout << std::endl;

    for (unsigned int i = 0; i < n.size(); i++)
        std::cout << "Int array " << i << " element value: " << n[i] << std::endl;
    
    for (unsigned int i = 0; i < str.size(); i++)
        std::cout << "String array " << i << " element value: " << str[i] << std::endl;

    std::cout << std::endl;

    n = big;
    for (unsigned int i = 0; i < n.size(); i++)
        std::cout << "After assigment operator int array " << i << " element value: " << n[i] << std::endl;
    
    std::cout << std::endl;
        
    Array<std::string> strc(str);
    for (unsigned int i = 0; i < str.size(); i++)
        std::cout << "After copy constructor string array " << i << " element value: " << str[i] << std::endl;
}
