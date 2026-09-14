/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 19:39:10 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 19:23:21 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberryCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    AForm*   presi = new    PresidentialPardonForm("bob");
    AForm*   shrubb = new   ShrubberryCreationForm("bob");
    AForm*   robot = new    RobotomyRequestForm("bob");
    Bureaucrat  mason("Mason", 1);
    Bureaucrat  bad("badson", 150);
    
    try
    {
        std::cout << *shrubb << std::endl;
        std::cout << *robot << std::endl;
        std::cout << *presi << std::endl;

        std::cout << mason << std::endl;
        std::cout << bad << std::endl;

        mason.signForm(*shrubb);
        mason.signForm(*shrubb);
        mason.executeForm(*shrubb);
        mason.signForm(*robot);
        mason.executeForm(*robot);
        mason.signForm(*presi);
        mason.executeForm(*presi);
        
        std::cout << std::endl;
        for (int i = 0; i < 20; i++)
        {
            mason.executeForm(*robot);
            std::cout << std::endl;
        }
    }
    catch (const    std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete presi;
    delete shrubb;
    delete robot;
}
