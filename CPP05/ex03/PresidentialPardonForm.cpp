/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:27:51 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:50:56 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("None") {
    std::cout << UNDERLINE "PresidentialPardonForm default constructor called" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
        AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << UNDERLINE "PresidentialPardonForm constructor called" RESET << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
    std::cout << UNDERLINE "PresidentialPardonForm copy constructor called" RESET << std::endl;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << UNDERLINE "PresidentialPardonForm copy assigment operator called" RESET << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << UNDERLINE "PresidentialPardonForm destructor called" RESET << std::endl;
}

const   std::string&    PresidentialPardonForm::getTarget() const {
    return _target;
}

void    PresidentialPardonForm::setTarget(const std::string& target) {
    _target = target;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned())
        throw   FormNotSignedException();
    if (executor.getGrade() > getExeGrade())
        throw   GradeTooLowException();
        
    std::cout << BOLD BFGGREEN << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream&   operator<<(std::ostream& out, const PresidentialPardonForm& form) {
    out << BOLD BFGCYAN "Name: " << form.getName() << RESET << std::endl;
    out << BOLD BFGYELLOW "Signed: " RESET << (form.getIsSigned() ? BOLD BFGGREEN "yes" RESET : BOLD BFGRED "no" RESET) << std::endl;
    out << BOLD BFGMAGEN "Grade required to sign: " RESET BOLD BFGYELLOW << form.getSignGrade() << RESET << std::endl;
    out << BOLD BFGMAGEN "Grade required to execute: " RESET BOLD BFGYELLOW << form.getExeGrade() << RESET << std::endl;
    out << BOLD BFGRED "The target is: " RESET BOLD BFGYELLOW << form.getTarget() << RESET << std::endl;
    
    return out;
}
