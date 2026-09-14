/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:53:56 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 16:44:01 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "colors.hpp"
# include "Intern.hpp"

const   char*   Intern::NameNotValidException::what() const throw() {
    return BOLD BFGRED "The provided name is not valid!" RESET;
}

Intern::Intern() {
    std::cout << UNDERLINE "Intern default constructor called" RESET << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << UNDERLINE "Intern copy constructor called" RESET << std::endl;
    (void)other;
}

Intern  Intern::operator=(const Intern& other) {
    std::cout << UNDERLINE "Intern copy assigment operator called" RESET << std::endl;
    (void)other;
    return (*this);
}

Intern::~Intern() {
    std::cout << UNDERLINE "Intern destructor called" RESET << std::endl;
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& formTarget) const {
    std::string forms[3];
    std::string internmsg = "Intern creates";
    forms[0] = "Robotomy";
    forms[1] = "Shrubberry";
    forms[2] = "Presidential";
    int i;

    for (i = 0; i < 3; i++)
    {
        if (formName == forms[i])
            break ;
    }
    switch (i)
    {
        case (0):
            std::cout << BOLD BFGCYAN << internmsg << RESET BOLD BFGYELLOW " RobotomyRequestForm" RESET << std::endl;
            return new  RobotomyRequestForm(formTarget);
        case (1):
            std::cout << BOLD BFGCYAN << internmsg << RESET BOLD BFGYELLOW " ShrubberryCreationForm" RESET << std::endl;
            return new  ShrubberryCreationForm(formTarget);
        case (2):
            std::cout << BOLD BFGCYAN << internmsg << RESET BOLD BFGYELLOW " PresidentialPardonForm" RESET << std::endl;
            return new  PresidentialPardonForm(formTarget);
        default:
            throw   NameNotValidException();
    }
}
