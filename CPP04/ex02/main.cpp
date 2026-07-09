/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:00:29 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/09 18:24:28 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
    const int n = 10;
    Animal* array[n];
    
    for (int i = 0; i < (n / 2); i++)
    
        array[i] = new Dog();
    for (int i = (n / 2); i < n; i++)
        array[i] = new Cat();
    
    for (int i = 0; i < n; i++)
        array[i]->makeSound();
    
    for (int i = 0; i < n; i++)
        delete array[i];

    std::cout << std::endl;
    Dog dog;
    dog.setIdea(0, "Ola boas");
    dog.setIdea(1, "Como vais");

    Dog dog2(dog);
    std::cout << "Dog 2 idea 0:" << dog2.getIdea(0) << std::endl;
    
    dog2.setIdea(0, "Oi!");

    std::cout << std::endl;

    std::cout << "Dog 1 idea 0: " << dog.getIdea(0) << std::endl;
    std::cout << "Dog 2 idea 0 after modification: " << dog2.getIdea(0) << std::endl;
    
    return 0;
}