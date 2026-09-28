/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:44:14 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/23 16:05:12 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "data.hpp"
# include <stdint.h>

class   Serializer
{
    private:
        Serializer();
        Serializer(const    Serializer& other);
        Serializer  operator=(const Serializer& other);
        ~Serializer();
    
    public:
        static  uintptr_t   serialize(Data* ptr);
        static  Data*       deserialize(uintptr_t   raw);
    
};

# endif