/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:22:53 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:35:28 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool    _isSigned;
        const int _signGrade;
        const int _exeGrade;

    public:
        class GradeTooHighException : public std::exception {
            public: const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public: const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public: const char* what() const throw();
        };

        class FormIsSignedException : public std::exception {
            public: const char* what() const throw();
        };

        AForm();
        AForm(const std::string& name, int signGrade, int exeGrade);
        AForm(const AForm& other);
        AForm    &operator=(const AForm& other);
        virtual ~AForm();
        
        const std::string& getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool    getIsSigned() const;
        void    beSigned(const Bureaucrat& bureau);

        virtual void    execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm &Aform);

# endif