/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:41:33 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 15:55:18 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        class NameNotValidException : public std::exception {
            public: const char* what() const throw();
        };
    
        Intern();
        Intern(const Intern& other);
        Intern  operator=(const Intern& other);
        ~Intern();

        AForm*  makeForm(const std::string& formName, const std::string& formTarget) const;
};

# endif