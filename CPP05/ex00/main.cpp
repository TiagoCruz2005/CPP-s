/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 16:38:12 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/24 17:02:38 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Tiago", 5);

        std::cout << a << std::endl;
        for (int i = a.getGrade(); i > -5; i--)
        {
            try
            {
                a.increment();
                std::cout << a << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Thiago", 145);

        std::cout << b << std::endl;
        for (int i = b.getGrade(); i < 155; i++)
        {
            try
            {
                b.decrement();
                std::cout << b << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        for (int i = b.getGrade(); i != 140; i--)
            b.increment();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}