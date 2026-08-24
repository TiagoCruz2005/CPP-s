/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 16:39:14 by tide-pau          #+#    #+#             */
/*   Updated: 2026/08/24 19:18:28 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat 
{   
    private:
        std::string _name;
        int _grade;
        
    public:    
        class   GradeTooHighException : public std::exception { 
            public: virtual const char* what() const throw();
        };

        class   GradeTooLowException : public std::exception {
            public: virtual const char* what() const throw();
        };
    
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        const std::string& getName() const;
        int   getGrade() const;
        void    increment();
        void    decrement();
        
        void    signForm(Form& form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

# endif