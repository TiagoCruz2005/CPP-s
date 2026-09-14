/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:48:24 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:57:38 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.hpp"
# include "ShrubberryCreationForm.hpp"
# include <iostream>
# include <fstream>

const char* ShrubberryCreationForm::FileCreationErrorException::what() const throw() {
    return BOLD BFGRED "File could not be created!" RESET;
}

ShrubberryCreationForm::ShrubberryCreationForm() : AForm("ShrubberryCreationForm", 145, 137), _target("None") {
    std::cout << UNDERLINE "ShrubberryCreationForm default construcotr called" RESET << std::endl;
}

ShrubberryCreationForm::ShrubberryCreationForm(const std::string& target) : AForm("ShrubberryCreationForm", 145, 137), _target(target) {
    std::cout << UNDERLINE "ShrubberryCreationForm construcotr called" RESET << std::endl;
}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm& other) : AForm(other) {
    std::cout << UNDERLINE "ShrubberryCreationForm copy constructor called" RESET << std::endl;
    _target = other._target;
}

ShrubberryCreationForm &ShrubberryCreationForm::operator=(const ShrubberryCreationForm& other) {
    std::cout << UNDERLINE "ShrubberryCreationForm copy assigment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {
    std::cout << UNDERLINE "ShrubberryCreationForm destructor called" RESET << std::endl;
}

void    ShrubberryCreationForm::setTarget(const std::string& target) {
    _target = target;
}

const std::string&    ShrubberryCreationForm::getTarget() const {
    return _target;
}

void    ShrubberryCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw   FormNotSignedException();
    if (executor.getGrade() > getExeGrade())
        throw   GradeTooLowException();

    std::string filename = _target + "_shrubberry";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw   FileCreationErrorException();
        
    file << "                                                         ." << std::endl;
    file << "                                              .         ;  " << std::endl;
    file << "                 .              .              ;%     ;;   " << std::endl;
    file << "                   ,           ,                :;%  %;   " << std::endl;
    file << "                    :         ;                   :;%;'     .,   " << std::endl;
    file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
    file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                            ;@%. :@%%  %@@%;       " << std::endl;
    file << "                              %@bd%%%bd%%:;     " << std::endl;
    file << "                                #@%%%%%:;;" << std::endl;
    file << "                                %@@%%%::;" << std::endl;
    file << "                                %@@@%(o);  . '         " << std::endl;
    file << "                                %@@@o%;:(.,'         " << std::endl;
    file << "                            `.. %@@@o%::;         " << std::endl;
    file << "                               `)@@@o%::;         " << std::endl;
    file << "                                %@@(o)::;        " << std::endl;
    file << "                               .%@@@@%::;         " << std::endl;
    file << "                               ;%@@@@%::;.          " << std::endl;
    file << "                              ;%@@@@%%:;;;. " << std::endl;
    file << "                          ...;%@@@@@%%:;;;;,.." << std::endl;

    file.close();
}

std::ostream&   operator<<(std::ostream& out, const ShrubberryCreationForm& form) {
    out << BOLD BFGCYAN "Name: " << form.getName() << RESET << std::endl;
    out << BOLD BFGYELLOW "Signed: " RESET << (form.getIsSigned() ? BOLD BFGGREEN "yes" RESET : BOLD BFGRED "no" RESET) << std::endl;
    out << BOLD BFGMAGEN "Grade required to sign: " RESET BOLD BFGYELLOW << form.getSignGrade() << RESET << std::endl;
    out << BOLD BFGMAGEN "Grade required to execute: " RESET BOLD BFGYELLOW << form.getExeGrade() << RESET << std::endl;
    out << BOLD BFGRED "The target is: " RESET BOLD BFGYELLOW << form.getTarget() << RESET << std::endl;
    
    return out;
}