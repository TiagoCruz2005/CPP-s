/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:18:38 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/26 16:09:36 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
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
    
        Form();
        Form(const std::string& name, int signGrade, int exeGrade);
        Form(const Form& other);
        Form    &operator=(const Form& other);
        ~Form();
        
        const std::string& getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool    getIsSigned() const;
        void    beSigned(const Bureaucrat& bureau);
};

std::ostream& operator<<(std::ostream& out, const Form &form);

# endif