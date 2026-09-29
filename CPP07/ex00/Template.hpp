/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 21:18:41 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/28 21:18:43 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <string>

template <typename T>
void    swap(T &a, T &b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T   max(T const &a, T const &b) {
    if (a == b)
        return b;
    else if (a > b)
        return a;
    else
        return b;
}

template <typename T>
T   min(T const &a, T const &b) {
    if (a == b)
        return b;
    else if (a < b)
        return a;
    else
        return b;
}

# endif