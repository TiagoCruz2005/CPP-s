/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:18:35 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/26 16:27:57 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include "colors.hpp"

const   char* Form::GradeTooHighException::what() const throw() {
    return BOLD BFGRED "Grade requirement is to high!" RESET;
}

const char* Form::GradeTooLowException::what() const throw() {
    return BOLD BFGRED "Grade requirement is to low!" RESET;    
}

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _exeGrade(150) {
    std::cout << UNDERLINE "Form Default constructor called" RESET << std::endl;
}

Form::Form(const std::string& name, int signGrade, int exeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _exeGrade(exeGrade) {
    std::cout << UNDERLINE "Form Constructor called" RESET << std::endl;
    
    if (_signGrade > 150)
        throw Form::GradeTooLowException();
    else if (_signGrade < 1)
        throw Form::GradeTooHighException();
    
    if (_exeGrade > 150)
        throw Form::GradeTooLowException();
    else if (_exeGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned),
    _signGrade(other._signGrade), _exeGrade(other._exeGrade) {
    std::cout << UNDERLINE "Form copy constructor called" RESET << std::endl;
}

Form    &Form::operator=(const Form& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {
    std::cout << UNDERLINE "Form destructor called" RESET << std::endl;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExeGrade() const {
    return _exeGrade;
}

bool    Form::getIsSigned() const {
    return _isSigned;
}

void    Form::beSigned(const Bureaucrat& bureau) {
    if (bureau.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const std::string&  Form::getName() const {
    return _name;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << BOLD BFGCYAN "Name: " << form.getName() << RESET << std::endl;
    out << BOLD BFGYELLOW "Signed: " RESET << (form.getIsSigned() ? BOLD BFGGREEN "yes" RESET : BOLD BFGRED "no" RESET) << std::endl;
    out << BOLD BFGMAGEN "Grade required to sign: " RESET BOLD BFGYELLOW << form.getSignGrade() << RESET << std::endl;
    out << BOLD BFGMAGEN "Grade required to execute: " RESET BOLD BFGYELLOW << form.getExeGrade() << RESET << std::endl;

    return out;
}
