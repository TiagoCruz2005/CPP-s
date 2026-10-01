/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 12:12:37 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/01 15:08:03 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>

class   Span
{
    private:
        std::vector<int> _vector;
        unsigned int    _maxSize;

    public:
        class   NoSpanCouldBeFoundException : public std::exception {
            public: const char* what() const throw();
        };

        class   SpanMaxSizeException : public std::exception {
            public: const char* what() const throw();
        };
        
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span    operator=(const Span& other);
        ~Span();

        void    addNumber(int num);
        
        int     shortestSpan();
        int     longestSpan();
        int     printAllElements();
        
        template<typename Iterator>
        void    addNumber(Iterator begin, Iterator end);
};

template <typename Iterator>
void    Span::addNumber(Iterator begin, Iterator end) {
    for (; begin != end; ++begin)
            addNumber(*begin);
}

# endif