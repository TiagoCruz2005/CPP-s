/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:16:29 by tide-pau          #+#    #+#             */
/*   Updated: 2026/05/14 13:50:37 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

PhoneBook::PhoneBook(void) 
{
    num_cont = 0;
    i = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook has been destroyed" << std::endl;
}

int PhoneBook::getnumContacts()
{
    return num_cont;
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

int isalldigits(std::string input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (input[i] >= '0' && input[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}

int validatecontactFields(std::string &str)
{
    if (str.empty())
        return 0;
    for (size_t i = 0; i < str.size(); i++)
        if (std::isdigit(str[i]))
            return 0;
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isspace(str[i]))
            return 1;
    return 0;
}

int validatephoneNumber(std::string &str)
{
    if (str.empty())
        return 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}

void    PhoneBook::addContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    int i;

    i = this->i;
    std::cout << CLEAR << std::endl;
    std::cout << BFGCYAN << "Write down the contact information" << RESET << std::endl;
    std::cout << BFGCYAN << "First name: " << RESET << std::endl;
    if (!getline(std::cin, firstName))
        return ;
    while (!validatecontactFields(firstName))
    {
        std::cout << BFGRED << EMPTYORONLYSPACES << RESET << std::endl;
        if (!getline(std::cin, firstName))
            return ;
    }
    Contacts[i].setfirstName(firstName);
    
    std::cout << BFGCYAN << "Last name: " << RESET << std::endl;
    if (!getline(std::cin, lastName))
        return ;
    while (!validatecontactFields(lastName))
    {
        std::cout << BFGRED << EMPTYORONLYSPACES << RESET << std::endl;
        if (!getline(std::cin, lastName))
            return ;
    }
    Contacts[i].setlastName(lastName);
    
    std::cout << BFGCYAN << "Nick name: " << RESET << std::endl;
    if (!getline(std::cin, nickName))
        return ;
    while (!validatecontactFields(nickName))
    {
        std::cout << BFGRED << EMPTYORONLYSPACES << RESET << std::endl;
        if (!getline(std::cin, nickName))
            return ;
    }
    Contacts[i].setnickName(nickName);
        
    std::cout << BFGCYAN << "Phone number: " << RESET << std::endl;
    if (!getline(std::cin, phoneNumber))
        return ;
    while (!validatephoneNumber(phoneNumber))
    {
        std::cout << BFGRED << PHONENUMVALID << RESET << std::endl;
        if (!getline(std::cin, phoneNumber))
            return ;
    }
    Contacts[i].setphoneNumber(phoneNumber);

    std::cout << BFGCYAN << "Darkest secret: " << RESET << std::endl;
    if (!getline(std::cin, darkestSecret))
        return ;
    while (!validatecontactFields(darkestSecret))
    {
        std::cout << BFGRED << EMPTYORONLYSPACES << RESET << std::endl;
        if (!getline(std::cin, darkestSecret))
            return ;
    }
    Contacts[i].setdarkestSecret(darkestSecret); 
    
    this->i++;
    if (num_cont < 8)
        num_cont++;
    if (this->i >= 8)
        this->i = 0;
}

void    PhoneBook::printsearchTable()
{
    std::cout << BBGWHITE << FGBLUE;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|  INDEX   |FIRST NAME| LAST NAME| NICK NAME|" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    for(int j = 0; j < num_cont; j++)
    {
        std::cout << "|" << std::setw(10) << j + 1;
        std::cout << "|" << std::setw(10) << truncate(Contacts[j].getfirstName());
        std::cout << "|" << std::setw(10) << truncate(Contacts[j].getlastName());
        std::cout << "|" << std::setw(10) << truncate(Contacts[j].getnickName()) << "|" << std::endl;
    }
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << RESET << std::endl;
    std::cout << "Select a contact by index" << std::endl;
}

void    PhoneBook::printContact(int index)
{
    std::cout << CLEAR << BFGBLUE;
    std::cout << "First name: " << Contacts[index - 1].getfirstName() << std::endl;
    std::cout << "Last name: " << Contacts[index - 1].getlastName() << std::endl;
    std::cout << "Nick name: " << Contacts[index - 1].getdarkestSecret() << std::endl;
    std::cout << "Phone number: " << Contacts[index - 1].getphoneNumber() << std::endl;
    std::cout << "Darkest secret: " << Contacts[index - 1].getdarkestSecret() << RESET << std::endl;
    std::cout << '\n';
}

void     PhoneBook::add()
{
    addContact();
    std::cout << CLEAR << std::endl;
    std::cout << GENERICMESSAGE << std::endl;
}

int     PhoneBook::search()
{
    if (getnumContacts() == 0)
    {
        std::cout << CLEAR << std::endl;
        std::cout << NOCONTACT << std::endl;
        return 1;
    }
    std::cout << CLEAR << std::endl;
    searchContacts();
    std::cout << CLEAR << std::endl;
    std::cout << GENERICMESSAGE << std::endl;
    return 0;
}

void    PhoneBook::searchContacts()
{
    std::string input;
    int index;
    
    printsearchTable();
    if (!getline(std::cin, input))
        return ;
    while (!isalldigits(input) || !input[0])
    {
        std::cout << "---> Error: Incorrect input ---> Must not be empty and must contain only digits." << std::endl;
        if (!getline(std::cin, input))
            return ;
    }
    std::istringstream ss(input);
    ss >> index;
    while (index < 1 || index > num_cont)
    {
        std::cout << "---> Error: Invalid index ---> Please write a valid index" << std::endl;
        if (!getline(std::cin, input))
            return ;
        std::istringstream num(input);
        num >> index;
    }
    printContact(index);
    std::cout << "Press any key to continue" << std::endl;
    if (!getline(std::cin, input))
        return ;
}
