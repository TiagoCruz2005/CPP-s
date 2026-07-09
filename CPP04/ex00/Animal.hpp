/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 23:22:35 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/08 17:59:58 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "colors.hpp"

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        ~Animal();
        virtual void    makeSound() const;
        std::string    getType() const;
};

# endif