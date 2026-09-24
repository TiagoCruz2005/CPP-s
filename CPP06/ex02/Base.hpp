/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:27:38 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/24 01:18:21 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BASE_HPP
# define BASE_HPP

class   Base
{
    public:
        virtual ~Base();
};

Base *  generate(void);
void    identify(Base*  p);
void    identify(Base&  p);

# endif