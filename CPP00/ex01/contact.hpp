/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:16:34 by tide-pau          #+#    #+#             */
/*   Updated: 2026/06/29 15:31:19 by tide-pau         ###   ########.fr       */
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
        void    setfirstName(const std::string &firstName);
        void    setlastName(const std::string &lastName);
        void    setnickName(const std::string &nickName);
        void    setphoneNumber(const std::string &phoneNumber);
        void    setdarkestSecret(const std::string &darkestSecret);
        const std::string&      getfirstName() const;
        const std::string&      getlastName() const;
        const std::string&      getnickName() const;
        const std::string&      getphoneNumber() const;
        const std::string&      getdarkestSecret() const;
};

#endif