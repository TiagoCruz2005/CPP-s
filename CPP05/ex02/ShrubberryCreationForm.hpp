/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 14:06:19 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/10 18:03:21 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberryCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        class FileCreationErrorException : public std::exception {
            public: const char* what() const throw();
        };
        
        ShrubberryCreationForm();
        ShrubberryCreationForm(const std::string& target);
        ShrubberryCreationForm(const ShrubberryCreationForm& other);
        ShrubberryCreationForm& operator=(const ShrubberryCreationForm& other);
        ~ShrubberryCreationForm();

        void    setTarget(const std::string& target);
        const std::string&    getTarget() const;
        
        void    execute(Bureaucrat const & executor) const;
};

std::ostream&   operator<<(std::ostream& out, const ShrubberryCreationForm& form);

# endif