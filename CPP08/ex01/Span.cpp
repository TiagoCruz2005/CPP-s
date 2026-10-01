/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:52:11 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/01 15:11:50 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <algorithm>
# include "Span.hpp"

const char* Span::NoSpanCouldBeFoundException::what() const throw() {
    return "No span could be found";
}

const char* Span::SpanMaxSizeException::what() const throw() {
    return "Span is at max capacity";
}

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) {
    *this = other;
}

Span    Span::operator=(const Span& other) {
    if (this != &other)
    {
        _vector = other._vector;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int num) {
    if (_vector.size() >= _maxSize)
        throw SpanMaxSizeException();
    _vector.push_back(num);
}

int     Span::longestSpan() {
    if (_vector.size() < 2)
        throw NoSpanCouldBeFoundException();

    int biggest = *std::max_element(_vector.begin(), _vector.end());
    int smallest = *std::min_element(_vector.begin(), _vector.end());

    return (biggest - smallest);
}

int     Span::shortestSpan() {
    if (_vector.size() < 2)
        throw NoSpanCouldBeFoundException();
        
    std::vector<int> sorted(_vector);
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator it = sorted.begin();
    int smallest = *(it + 1) - *it;
    int gap;
    
    for (; it + 1 < sorted.end(); ++it)
    {
        gap = *(it + 1) - *it;
        if (smallest > gap)
            smallest = gap;
    }
    return smallest;
}

// prints every element of the span and also returning how many it printed.
int    Span::printAllElements() {
    std::vector<int>::iterator it = _vector.begin();
    int i = 0;
    
    for (; it != _vector.end(); ++it)
    {
        std::cout << *it << std::endl;
        i++;
    }
    return i;
}
