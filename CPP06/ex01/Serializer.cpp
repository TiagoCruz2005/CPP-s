/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:44:16 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/23 16:12:13 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    (void)other;
}

Serializer  Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t   Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t   raw) {
    return (reinterpret_cast<Data*>(raw));
}