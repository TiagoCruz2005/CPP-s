/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:16:23 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/29 15:51:03 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include "contact.hpp"
#include "colors.hpp"

#define CLEAR "\033[2J\033[H"
#define GENERICMESSAGE "---> Write:\n\033[96m[ADD]:\033[0m (To add a contact).\n\033[94m[SEARCH]:\033[0m (To search for contacts).\n\033[91m[EXIT]:\033[0m (To exit the program)."
#define INCORRECTINPUT "---> Error: Incorrect input ---> Please write one of the following:\n[ADD]\n[SEARCH]\n[EXIT]"
#define NOCONTACT "---> There are no contacts saved.\n---> Please add a contact with [ADD]."
#define EMPTYORONLYSPACES "---> Error: Incorrect input ---> This field must only contain letters and must not be empty.\nTry again:"
#define PHONENUMVALID "---> Error: Incorrect input ---> This field must only contain digits and must not be empty.\nTry again:"

class PhoneBook
{
    private:
        Contact Contacts[8];
        int num_cont;
        int i;
    public:
        PhoneBook();
        ~PhoneBook();
        void    add();
        void    addContact();
        void    searchContacts();
        void    printsearchTable();
        void    printContact(int index);
        int     getnumContacts();
        int     search();
};

int validatecontactFields(const std::string &str);
int validatephoneNumber(const std::string &str);
int isalldigits(const std::string &input);
std::string truncate(const std::string &str);

#endif