/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:34:32 by tide-pau          #+#    #+#             */
/*   Updated: 2026/09/21 15:00:10 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter&  ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}



bool    ScalarConverter::isLiteral(std::string&  str) {
    std::string identifiers[6];
    identifiers[0] = "+inff";
    identifiers[1] = "-inff";
    identifiers[2] = "nanf";
    identifiers[3] = "+inf";
    identifiers[4] = "-inf";
    identifiers[5] = "nan";

    for (int i = 0; i < 6; i++)
    {
        if (str == identifiers[i])
            return true;
    }
    return false;
}

bool    ScalarConverter::isValidChar(std::string&    str) {
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
        return true;
    return false;
}

bool    ScalarConverter::isValidNumber(std::string&  str) {
    char*   end;
    double  val = strtod(str.c_str(), &end);
    errno = 0;
    size_t dot = str.find('.');

    if (dot != std::string::npos)
    {
        if (!isdigit(str[dot + 1]))
            return false;
        if (str[dot + 1] == 'f')
            return false;
    }
    (void)val;
    if (end == str.c_str() || errno == ERANGE)
        return false;
    if (*end == '\0')
        return true;
    if (*end == 'f' && *(end + 1) == '\0')
        return true;
    return false;
}

int    ScalarConverter::checkForType(std::string&    str) {
    char*   end;
    double  val = strtod(str.c_str(), &end);

    if (val > MAXFLOAT || val < -MAXFLOAT)
        return 0;
    else if (val > MAXINT || val < MININT)
        return 1;
    else if (val <= MAXINT || val >= MININT)
        return 2;
    else
        return 3;
}

void    ScalarConverter::printLiterals(std::string  f, std::string d) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    ScalarConverter::verifyLiterals(std::string&  str) {
    std::string impo = "impossible";
    if (str == "+inf" || str == "+inff")
        printLiterals("+inff", "+inf");
    else if (str == "-inf" || str == "-inff")
        printLiterals("-inff", "-inf");
    else
        printLiterals("nanf", "nan");

}

bool    ScalarConverter::verifyIfStartIsValid(std::string&  str) {
    if (str[0] == '+' || str[0] == '-' || isdigit(str[0]))
        return true;
    else
        return false;
}

void    ScalarConverter::printIfIsChar(std::string&  str)
{
    float   f = static_cast<float>(str[0]);
    double  d = static_cast<double>(str[0]);
    
    if (isprint(str[0]))
        std::cout << "char: " << str[0] << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;

    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == static_cast<int>(f))
        std::cout << ".0";
    std::cout << std::endl;
}

int     ScalarConverter::checkOriginalType(std::string& str) {
    if (str.find('.') != std::string::npos)
    {
        if (str[str.length() - 1] == 'f')
            return FLOAT;
        else
            return DOUBLE;
    }
    else
        return INT;
}

void     ScalarConverter::printIfInt(int val) {
    if (val <= MAXCHAR && val >= MINCHAR)
    {
        if (isprint(static_cast<char>(val)))
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << val << std::endl;
    std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void    ScalarConverter::printIfFloat(float val) {
    int i = static_cast<int>(val);
    if (i <= MAXCHAR && i >= MINCHAR)
    {
        if (isprint(static_cast<unsigned char>(i)))
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    if (val == static_cast<int>(val))
    {
        std::cout << "float: " << val << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << val << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
}

void    ScalarConverter::printIfDouble(double val) {
    int i = static_cast<int>(val);
    if (i <= MAXCHAR && i >= MINCHAR)
    {
        if (isprint(static_cast<unsigned char>(i)))
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    if (val == static_cast<int>(val))
    {
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
        std::cout << "double: " << val << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << val << std::endl;
    }
}

void    ScalarConverter::numberConvertions(std::string& str, int ret) {
    char* end;
    double  val = strtod(str.c_str(), &end);
    
    switch (ret)
    {
        case (0):
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
            std::cout << "double: " << val << std::endl;
            break;
        case (1):
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(val) << std::endl;
            break;
        case (2):
            switch(checkOriginalType(str))
            {
                case (INT):
                    printIfInt(static_cast<int>(val));
                    break;
                case (FLOAT):
                    printIfFloat(static_cast<float>(val));
                    break;
                case (DOUBLE):
                    printIfDouble(static_cast<double>(val));
            }
        break;
    }
}

void    ScalarConverter::convert(std::string&    literal) {

    if (isLiteral(literal))
    {
        verifyLiterals(literal);
        return ;
    }
    else if (isValidChar(literal))
    {
        printIfIsChar(literal);
        return ;
    }
    else if (isValidNumber(literal) && verifyIfStartIsValid(literal))
    {
        numberConvertions(literal, checkForType(literal));
        return;
    }
    else
        std::cout << "Error: Invalid input" << std::endl;
}
