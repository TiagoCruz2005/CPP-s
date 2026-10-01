/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:26:54 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/01 15:14:43 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <list>
# include "colors.hpp"

int main()
{
    Span    span = Span(5);
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    std::list<int> list;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << std::endl;

    for (int i = 0; i < 10000; i++)
        list.push_back((rand() % 10000) + 1);
    
    try
    {
        span.addNumber(5);
        span.addNumber(3);
        span.addNumber(2);
        span.addNumber(10);
        span.addNumber(9);
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    Span longspan = Span(50000);
    
    longspan.addNumber(list.begin(), list.end());
    std::cout << "\nLongest span: " << longspan.longestSpan() << std::endl;
    std::cout << "Shortest span: " << longspan.shortestSpan() << std::endl;
    
/*
    longspan.addNumber(list.begin(), list.end());
    longspan.addNumber(list.begin(), list.end());
    longspan.addNumber(list.begin(), list.end());
    
    std::cout << longspan.printAllElements() << std::endl;
*/ 
    return 0;
}
