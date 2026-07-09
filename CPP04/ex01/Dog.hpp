/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:46:13 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/09 17:59:45 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*  _brain;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        void    makeSound() const;

        void    setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

# endif