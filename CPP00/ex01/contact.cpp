/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:53:23 by tide-pau          #+#    #+#             */
/*   Updated: 2026/05/12 12:30:06 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

Contact::Contact() {}

Contact::~Contact()
{
    
}

void    Contact::setfirstName(std::string firstName)
{
    _firstName = firstName;
}

void    Contact::setlastName(std::string lastName)
{
    _lastName = lastName;
}

void    Contact::setnickName(std::string nickName)
{
    _nickName = nickName;
}

void    Contact::setphoneNumber(std::string phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void    Contact::setdarkestSecret(std::string darkestSecret)
{
    _darkestSecret = darkestSecret;
}

std::string    Contact::getfirstName()
{
    return _firstName;
}

std::string     Contact::getlastName()
{
    return _lastName;
}

std::string     Contact::getnickName()
{
    return _nickName;
}

std::string     Contact::getphoneNumber()
{
    return _phoneNumber;
}

std::string     Contact::getdarkestSecret()
{
    return _darkestSecret;
}
