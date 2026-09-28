/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:12:52 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/23 16:24:49 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"
# include <iostream>

int main()
{
    Data    data;
    Data    data2;
    uintptr_t   raw;
    uintptr_t   raw2;
    
    
    data.num = 2;
    data.str = "boas";

    std::cout << &data << std::endl;
    std::cout << &data2 << std::endl;
    
    raw = Serializer::serialize(&data);
    raw2 = Serializer::serialize(&data2);
    
    std::cout << std::endl;

    std::cout << raw << std::endl;
    std::cout << raw2 << std::endl;

    std::cout << std::endl;
    
    std::cout << Serializer::deserialize(raw) << std::endl;
    std::cout << Serializer::deserialize(raw2) << std::endl;

    std::cout << std::endl;
    
    std::cout << Serializer::serialize(&data) << std::endl;
    std::cout << Serializer::serialize(&data2) << std::endl;
}