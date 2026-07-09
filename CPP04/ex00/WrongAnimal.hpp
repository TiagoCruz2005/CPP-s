/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:09:33 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/08 15:29:32 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "colors.hpp"

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal operator=(const WrongAnimal& other);
        ~WrongAnimal();
        void    makeSound() const;
        std::string getType() const;
};

# endif