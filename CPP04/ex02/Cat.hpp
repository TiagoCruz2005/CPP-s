/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:45:32 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/09 18:06:51 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain*  _brain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat&    operator=(const Cat& other);
        ~Cat();
        void    makeSound() const;

        void    setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

# endif