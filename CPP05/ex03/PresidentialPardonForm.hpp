/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 13:00:02 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/14 14:12:43 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm  &operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();

        void    setTarget(const std::string& target);
        const std::string&    getTarget() const;
        
        void    execute(Bureaucrat const &executor) const;
};

std::ostream&   operator<<(std::ostream& out, const PresidentialPardonForm& form);

# endif