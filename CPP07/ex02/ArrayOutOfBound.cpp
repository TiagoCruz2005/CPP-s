/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayOutOfBound.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 17:33:28 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/29 17:34:26 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ArrayOutOfBound.hpp"

const   char*   ArrayOutOfBoundException::what() const throw() {
    return "Array index out of bounds";
}