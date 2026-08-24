/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:18:35 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/24 19:16:40 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

const   char* Form::GradeTooHighException::what() const throw() {
    return "Grade requirement to high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade requirement to low!";    
}

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _exeGrade(150) {
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string& name, int signGrade, int exeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _exeGrade(exeGrade) {
    std::cout << "Form Constructor called" << std::endl;
    
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
    std::cout << "Form copy constructor called" << std::endl;
}

Form    &Form::operator=(const Form& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Name: " << form.getName() << std::endl;
    out << "Signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
    out << "Grade required to sign: " << form.getSignGrade() << std::endl;
    out << "Grade required to execute: " << form.getExeGrade() << std::endl;
}
