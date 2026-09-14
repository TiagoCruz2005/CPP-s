/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 19:39:10 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 16:46:03 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Intern.hpp"

int main()
{
    Bureaucrat  mason("mason", 1);
    Intern  intern;
    AForm*  form;
    
    try
    {
        form = intern.makeForm("Robotommy", "bob");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    mason.signForm(*form);
    mason.executeForm(*form);
    std::cout << *form << std::endl;
    std::cout << mason << std::endl;
    
    delete form;
}
