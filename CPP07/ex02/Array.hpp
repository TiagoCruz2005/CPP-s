/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:24:53 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/29 18:00:01 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include "ArrayOutOfBound.hpp"

template <typename T>
class Array {
    private:
        T   *_data;
        unsigned int    _size;
        
    public:
        Array();
        Array(unsigned  int n);
        Array(const Array &other);
        Array&   operator=(Array const &other);
        ~Array();
        
        T&  operator[](unsigned int i);
        T   const   &operator[](unsigned int i) const;
        unsigned int   size() const;
};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    _data = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) {
    *this = other;
}

template <typename T>
Array<T>   &Array<T>::operator=(const Array& other) {
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
T&  Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw ArrayOutOfBoundException();
    return _data[i];
}

template <typename T>
T   const   &Array<T>::operator[](unsigned int i) const {
    if (i >= _size)
        throw ArrayOutOfBoundException();
    return _data[i];
}

template <typename T>
unsigned int    Array<T>::size() const {
    return _size;
}

# endif