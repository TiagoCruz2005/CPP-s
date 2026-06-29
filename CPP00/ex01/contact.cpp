/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:53:23 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/29 15:32:11 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

Contact::Contact() {}

Contact::~Contact()
{
    
}

void    Contact::setfirstName(const std::string &firstName)
{
    _firstName = firstName;
}

void    Contact::setlastName(const std::string &lastName)
{
    _lastName = lastName;
}

void    Contact::setnickName(const std::string &nickName)
{
    _nickName = nickName;
}

void    Contact::setphoneNumber(const std::string &phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void    Contact::setdarkestSecret(const std::string &darkestSecret)
{
    _darkestSecret = darkestSecret;
}

const std::string&    Contact::getfirstName() const
{
    return _firstName;
}

const std::string&     Contact::getlastName() const
{
    return _lastName;
}

const   std::string&     Contact::getnickName() const
{
    return _nickName;
}

const   std::string&     Contact::getphoneNumber() const
{
    return _phoneNumber;
}

const    std::string&     Contact::getdarkestSecret() const
{
    return _darkestSecret;
}
