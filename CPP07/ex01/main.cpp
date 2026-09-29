/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:23:35 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/29 12:55:04 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "iter.hpp"

static void    sum5(int &num) {
    num += 5;
}

static void    addSomething(std::string&   str) {
    str += "Something";
}

int main()
{
    int intarray[3] = {1, 2, 3};
    std::string strarray[3] = {"boas", "como", "vais"};
    
    ::printArray(intarray, 3);
    std::cout << std::endl;
    ::printArray(strarray, 3);
    std::cout << std::endl;

    ::iter(intarray, 3, sum5);
    ::iter(strarray, 3, addSomething);

    ::printArray(intarray, 3);
    std::cout << std::endl;
    
    ::printArray(strarray, 3);
    std::cout << std::endl;

}
