/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:15:18 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/29 12:56:14 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

# include <string>

template <typename T, typename F>
void    iter(T *array, size_t lenght, F f) {
    for (size_t i = 0; i < lenght; i++)
        f(array[i]);
}

template <typename T>
void    printArray(T const *array, size_t size) {
    for (size_t i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}

# endif