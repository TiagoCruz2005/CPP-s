/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:16:34 by tide-pau          #+#    #+#             */
/*   Updated: 2026/05/07 15:51:38 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        Contact();
        ~Contact();
        void    setfirstName(std::string firstName);
        void    setlastName(std::string lastName);
        void    setnickName(std::string nickName);
        void    setphoneNumber(std::string phoneNumber);
        void    setdarkestSecret(std::string darkestSecret);
        std::string    getfirstName();
        std::string    getlastName();
        std::string    getnickName();
        std::string    getphoneNumber();
        std::string    getdarkestSecret();
};

#endif