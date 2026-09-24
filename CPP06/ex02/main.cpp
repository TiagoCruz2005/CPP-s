/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 01:02:40 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/24 01:19:39 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base * base = generate();
    
    identify(base);
    identify(*base);
    delete base;
}