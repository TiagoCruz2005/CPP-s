/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:07:34 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/30 14:11:39 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>

class ValueNotFoundException : public std::exception {
    public: 
        const char* what() const throw() {
            return "Easyfind could not found the value";
        }
};

template <typename T>
typename    T::iterator easyfind(T& container,  int num) {
    typename    T::iterator it = container.begin();

    for (; it != container.end(); ++it)
    {
        if (*it == num)
            return it;
    }
    throw ValueNotFoundException();
}

# endif