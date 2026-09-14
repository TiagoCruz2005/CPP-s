/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:22:59 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:36:24 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include "colors.hpp"

const   char* AForm::GradeTooHighException::what() const throw() {
    return BOLD BFGRED "Grade requirement is to high!" RESET;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return BOLD BFGRED "Grade requirement is to low!" RESET;    
}

const char* AForm::FormNotSignedException::what() const throw() {
    return BOLD BFGRED "Cannot execute, the Form is not signed!" RESET;
}

const char* AForm::FormIsSignedException::what() const throw() {
    return BOLD BFGYELLOW "The Form is already signed!" RESET;
}

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _exeGrade(150) {
    std::cout << UNDERLINE "AForm Default constructor called" RESET << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int exeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _exeGrade(exeGrade) {
    std::cout << UNDERLINE "AForm Constructor called" RESET << std::endl;
    
    if (_signGrade > 150)
        throw AForm::GradeTooLowException();
    else if (_signGrade < 1)
        throw AForm::GradeTooHighException();
    
    if (_exeGrade > 150)
        throw AForm::GradeTooLowException();
    else if (_exeGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _isSigned(other._isSigned),
    _signGrade(other._signGrade), _exeGrade(other._exeGrade) {
    std::cout << UNDERLINE "AForm copy constructor called" RESET << std::endl;
}

AForm    &AForm::operator=(const AForm& other) {
    std::cout << UNDERLINE "AForm copy assigment operator called" RESET << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << UNDERLINE "AForm destructor called" RESET << std::endl;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExeGrade() const {
    return _exeGrade;
}

bool    AForm::getIsSigned() const {
    return _isSigned;
}

void    AForm::beSigned(const Bureaucrat& bureau) {
    if (_isSigned)
        throw FormIsSignedException();
    if (bureau.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const std::string&  AForm::getName() const {
    return _name;
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform) {
    out << BOLD BFGCYAN "Name: " << Aform.getName() << RESET << std::endl;
    out << BOLD BFGYELLOW "Signed: " RESET << (Aform.getIsSigned() ? BOLD BFGGREEN "yes" RESET : BOLD BFGRED "no" RESET) << std::endl;
    out << BOLD BFGMAGEN "Grade required to sign: " RESET BOLD BFGYELLOW << Aform.getSignGrade() << RESET << std::endl;
    out << BOLD BFGMAGEN "Grade required to execute: " RESET BOLD BFGYELLOW << Aform.getExeGrade() << RESET << std::endl;

    return out;
}
