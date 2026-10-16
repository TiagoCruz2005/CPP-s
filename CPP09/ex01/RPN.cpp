/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:20:31 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/16 18:39:51 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
# include <sstream>
# include <iostream>
# include <cctype>
# include <cstring>
# include <stdexcept>
# include <climits>

Rpn::Rpn() {}

Rpn::Rpn(const Rpn& other) {
    *this = other;
}

Rpn &Rpn::operator=(const Rpn& other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

Rpn::~Rpn() {}

void    Rpn::parseArg(const std::string& rpn) {
    if (rpn.length() < 2)
        throw std::runtime_error("Error");
    for (unsigned int i = 0; i < rpn.length(); i++)
    {
        if (!isdigit(rpn[i]) && !std::strchr("+-/* ", rpn[i]))
            throw std::runtime_error("Error");
    }
    consumeArg(rpn);
}

void    Rpn::consumeArg(const std::string& rpn) {
    std::istringstream iss(rpn);
    std::string token;

    while (iss >> token)
    {
        if (token.length() != 1)
            throw std::runtime_error("Error");
        if (isdigit(token[0]))
        {
            _stack.push((token[0] - '0'));
            continue ;
        }
        if (std::strchr("+-/*", token[0]))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            calc(token[0]);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;
}

void    Rpn::calc(char op) {
    int sec = _stack.top();
    _stack.pop();
    int first = _stack.top();
    _stack.pop();
    
    switch (op)
    {
        case ('+'):
            preventOverflow(first, sec, '+');
            _stack.push(first + sec);
            break ;
        case ('-'):
            preventOverflow(first, sec, '-');
            _stack.push(first - sec);
            break ;
        case ('*'):
            preventOverflow(first, sec, '*');
            _stack.push(first * sec);
            break ;
        case ('/'):
            if (sec == 0)
                throw std::runtime_error("Error");
            if (first == INT_MIN && sec == -1)
                throw std::runtime_error("Error");
            _stack.push(first / sec);
            break;
    }
}

void    Rpn::preventOverflow(int first, int sec, char op) {
    switch (op)
    {
        case ('+'):
            if (sec > 0 && first > INT_MAX - sec)
                throw std::runtime_error("Error");
            if (sec < 0 && first < INT_MIN - sec)
                throw std::runtime_error("Error");
            break ;
        case ('-'):
            if (sec < 0 && first > INT_MAX + sec)
                throw std::runtime_error("Error");
            if (sec > 0 && first < INT_MIN + sec)
                throw std::runtime_error("Error");
            break ;
        case ('*'):
            if (first > 0)
            {
                if (sec > 0 && first > INT_MAX / sec)
                    throw std::runtime_error("Error");
                if (sec < 0 && sec < INT_MIN / first)
                    throw std::runtime_error("Error");
            }
            else if (first < 0)
            {
                if (sec > 0 && first < INT_MIN / sec)
                    throw std::runtime_error("Error");
                if (sec < 0 && first < INT_MAX / sec)
                    throw std::runtime_error("Error");
            }
    }
}
