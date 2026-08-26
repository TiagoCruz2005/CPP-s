/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:31:14 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/26 16:36:37 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"
# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form    form("Form1", 75, 50);
        Bureaucrat  t("Tiago", 65);
        Bureaucrat  b("Bruno", 100);

        std::cout << form << std::endl;
        std::cout << b << std::endl;
        std::cout << t << std::endl << std::endl;
        
        b.signForm(form);
        std::cout << form << std::endl;
        t.signForm(form);
        std::cout << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
