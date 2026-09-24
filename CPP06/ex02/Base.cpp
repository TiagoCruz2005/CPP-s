/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:32:43 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/24 01:18:34 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base() {}

void    identify(Base*    p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base&    p) {
    try
    {
        A&  a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    try
    {
        B&  b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    try
    {
        C&  c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return ;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
}

Base*   generate(void) {
    int rand;
    switch(rand = std::rand() % 3)
    {
        case (0):
            return (new A());
        case(1):
            return (new B());
    }
    return (new C());
}