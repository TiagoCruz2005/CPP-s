/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 23:51:29 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/08 14:14:17 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void    makeSound() const;
};

# endif