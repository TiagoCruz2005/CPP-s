/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayOutOfBound.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:32:29 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/29 17:33:24 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAYOUTOFBOUND_HPP
# define ARRAYOUTOFBOUND_HPP

# include <string>

class ArrayOutOfBoundException : public std::exception {
    public: const char *what() const throw();
};

# endif