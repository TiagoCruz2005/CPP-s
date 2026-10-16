/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:14:15 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/16 18:10:32 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class   Rpn
{
    private:
        std::stack<int> _stack;
    
    public:
        Rpn();
        Rpn(const Rpn& other);
        Rpn&    operator=(const Rpn& other);
        ~Rpn();

        void    parseArg(const std::string& rpn);
        void    consumeArg(const std::string& rpn);
        void    calc(char op);
        void    preventOverflow(int first, int sec, char op);
};

# endif