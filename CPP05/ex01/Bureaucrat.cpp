/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 16:39:09 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/26 16:23:55 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too hight!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low!";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << UNDERLINE "Bureaucrat Default constructor called" RESET<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    std::cout << UNDERLINE "Bureaucrat Constructor called" RESET << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << UNDERLINE "Bureaucrat Copy constructor called" RESET << std::endl;
    *this = other;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << UNDERLINE "Bureaucrat Copy assigment operator called" RESET << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _grade = other._grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::increment() {
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    --_grade;
}

void    Bureaucrat::decrement() {
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    ++_grade;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << BOLD BFGCYAN << bureaucrat.getName() << RESET;
    out << BOLD BFGMAGEN ", bureaucrat grade " RESET;
    out << BOLD BFGYELLOW << bureaucrat.getGrade() << RESET;
    return out;
}

Bureaucrat::~Bureaucrat() {
    std::cout << UNDERLINE "Bureaucrat Destructor called" RESET << std::endl;
}

void    Bureaucrat::signForm(Form& form) {
    try
    {
        form.beSigned(*this);
        std::cout << BOLD BFGGREEN << _name << " signed " << form.getName() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << BOLD BFGRED << _name << " couldn't sign "
        << form.getName() << " because " RESET << e.what() << std::endl;
    }
}