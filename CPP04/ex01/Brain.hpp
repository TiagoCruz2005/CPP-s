/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:46:37 by tide-pau          #+#    #+#             */
/*   Updated: 2026/07/09 18:01:20 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain&   operator=(const Brain& other);
        ~Brain();

        void    setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

# endif