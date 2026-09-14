/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 18:06:41 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:45:50 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        class RobotomyFailException : public std::exception {
            public: const char* what() const throw();
        };

    RobotomyRequestForm();
    RobotomyRequestForm(const   std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();

    const std::string&  getTarget() const;
    void    setTarget(std::string& target);

    void    execute(Bureaucrat const & executor) const;
};

std::ostream&   operator<<(std::ostream& out, const RobotomyRequestForm& form);

# endif