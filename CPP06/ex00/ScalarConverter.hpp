/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:57:37 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/21 13:56:53 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALarCONVERTER_HPP
# define SCALarCONVERTER_HPP

# include <string>
# include <limits>

# define MAXINT     std::numeric_limits<int>::max()
# define MININT     std::numeric_limits<int>::min()
# define MAXFLOAT   std::numeric_limits<float>::max()
# define MAXDOUBLE  std::numeric_limits<double>::max()
# define MAXCHAR    std::numeric_limits<char>::max()
# define MINCHAR    std::numeric_limits<unsigned char>::min()

# define FLOAT 1
# define DOUBLE 0
# define INT 2
# define CHAR 3

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&  operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:

        static  bool    isLiteral(std::string&  str);
        static  bool    isValidChar(std::string& str);
        static  bool    isValidNumber(std::string& str);
        static  bool    verifyIfStartIsValid(std::string&  str);
        
        static  void    printIfIsChar(std::string& str);
        static  void    printIfInt(int val);
        static  void    printIfFloat(float val);
        static  void    printIfDouble(double val);

        static  int     checkOriginalType(std::string& str);
        static  int     checkForType(std::string&   str);
        static  void    verifyLiterals(std::string& str);
        static  void    numberConvertions(std::string& str, int ret);
        static  void    printLiterals(std::string  f, std::string d);
        
        static  void    convert(std::string& literal);
};

# endif