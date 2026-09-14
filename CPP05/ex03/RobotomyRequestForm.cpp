/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 18:15:56 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:51:01 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "colors.hpp"
# include "RobotomyRequestForm.hpp"
# include <cstdlib>

const char* RobotomyRequestForm::RobotomyFailException::what() const throw() {
    return BOLD BFGRED "The requested Robotomy failed!" RESET;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("None") {
    std::cout << UNDERLINE "RobotomyRequestForm default construcotr called" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << UNDERLINE "RobotomyRequestForm constructor called" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
    std::cout << UNDERLINE "RobotomyRequestForm copy constructor called" RESET << std::endl;
    _target = other._target;
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << UNDERLINE "RobotomyRequestForm copy assigment operator called" RESET << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << UNDERLINE "RobotomyRequestForm destructor called" RESET << std::endl;
}

const std::string&  RobotomyRequestForm::getTarget() const {
    return  _target;
}

void    RobotomyRequestForm::setTarget(std::string& target) {
    _target = target;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw   FormNotSignedException();
    if (executor.getGrade() > getExeGrade())
        throw   GradeTooLowException();

    std::cout << "Makes some drilling noises" << std::endl;
        
    if (rand() % 2 == 0)
        std::cout << BOLD BFGGREEN << _target << " has been robotomized succesfully!" RESET << std::endl;
    else
        std::cout << BOLD BFGRED "Oh no the robotomy has failed!" RESET << std::endl;
}

std::ostream&   operator<<(std::ostream& out, const RobotomyRequestForm& form) {
    out << BOLD BFGCYAN "Name: " << form.getName() << RESET << std::endl;
    out << BOLD BFGYELLOW "Signed: " RESET << (form.getIsSigned() ? BOLD BFGGREEN "yes" RESET : BOLD BFGRED "no" RESET) << std::endl;
    out << BOLD BFGMAGEN "Grade required to sign: " RESET BOLD BFGYELLOW << form.getSignGrade() << RESET << std::endl;
    out << BOLD BFGMAGEN "Grade required to execute: " RESET BOLD BFGYELLOW << form.getExeGrade() << RESET << std::endl;
    out << BOLD BFGRED "The target is: " RESET BOLD BFGYELLOW << form.getTarget() << RESET << std::endl;

    return out;
}
