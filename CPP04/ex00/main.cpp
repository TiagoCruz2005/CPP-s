/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:25:27 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/08 16:37:44 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete i;
    delete j;
    delete meta;

    std::cout << std::endl;

    const WrongAnimal* meta2 = new WrongAnimal();
    const Animal* x = new Dog();
    const WrongAnimal* y = new WrongCat();
    std::cout << x->getType() << " " << std::endl;
    std::cout << y->getType() << " " << std::endl;
    y->makeSound(); //will output the Wrong sound!
    x->makeSound();
    meta2->makeSound();
    delete x;
    delete y;
    delete meta2;

    return 0;
}