/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:51:47 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/13 20:47:44 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
# include <cctype>
# include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _dataBase = other._dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void    BitcoinExchange::loadDataBase(const std::string&    fileName) {
    std::ifstream file(fileName.c_str());
    std::string line;
    std::string::size_type pos;
    
    if (!file.is_open())
        throw   std::runtime_error("Error: could not open database file");

    std::getline(file, line);
    
    if (line.empty())
        throw   std::runtime_error("Error: the database is empty");
        
    if (line != "date,exchange_rate")
        throw   std::runtime_error("Error: the database header is incorrect");
        
    while (std::getline(file, line))
    {
        pos = line.find(',');
        if (pos == std::string::npos || !isValidLine(line, false))
            throw   std::runtime_error("Error: invalid database format");
            
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if (!isValidDate(date))
            throw   std::runtime_error("Error: database invalid date");
            
        if (!_dataBase.insert(std::make_pair(date, isValidValue(value, false))).second)
            throw   std::runtime_error("Error: duplicate date");   
    }
    if (_dataBase.empty())
        throw   std::runtime_error("Error: database contains no data");
}

bool    BitcoinExchange::isValidLine(const std::string& line, bool y) const {
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (!isdigit(static_cast<unsigned char>(line[i]))
            && line[i] != '-'
            && line[i] != '.'
            && line[i] != ' '
            && line[i] != ','
            && (!y || line[i] != '|'))
            return false;
        if (y && line[i] == ',')
            return false;
        if (!y && line[i] == '|')
            return false;
    }
    return true;
}

bool    BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (std::string::size_type i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
        
    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
        
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month > 12 || month < 1)
        return false;
        
    if (day < 1)
        return false;
        
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    
    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}

bool    BitcoinExchange::isLeapYear(int year) const {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return (year % 4 == 0);
}

float    BitcoinExchange::isValidValue(const std::string& value, bool y) const {
    std::istringstream stream(value);
    float val;
    char extra;

    if (!(stream >> val) || (stream >> extra))
        throw std::runtime_error("Error: invalid number");
    if (val > 1000 && y)
        throw std::runtime_error("Error: too large a number");
    if (val < 0)
        throw std::runtime_error("Error: not a positive number");
    return val;
}

void    BitcoinExchange::printDataBase() const {
    std::map<std::string, float>::const_iterator it;

    for (it = _dataBase.begin(); it != _dataBase.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
}

void    BitcoinExchange::parseInput(const std::string& fileName)
{
    std::ifstream file(fileName.c_str());
    std::string line;
    std::string::size_type pos;
    
    if (!file.is_open())
        throw   std::runtime_error("Error: could not open input file");
    std::getline(file, line);

    if (line.empty() || line != "date | value")
        throw   std::runtime_error("Error: invalid header");
    
    while (std::getline(file, line))
    {
        pos = line.find('|');
        if (pos == std::string::npos || !isValidLine(line, true))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        float val = 0;
        std::string date = line.substr(0, pos);
        std::string value;
        if (pos + 1 < line.size())
            value = line.substr(pos + 1);

        while (!date.empty() && date[date.length() - 1] == ' ')
            date.erase(date.length() - 1);

        while (!value.empty() && value[0] == ' ')
            value.erase(0, 1);

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        try
        {
            val = isValidValue(value, true);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }
        calculateValue(date, val);
    }
}

void    BitcoinExchange::calculateValue(std::string& date, float val) const {
    std::map<std::string, float>::const_iterator it;
    float result = 0;
    
    it = _dataBase.upper_bound(date);
    if (it == _dataBase.begin())
    {
        std::cout << "Error: no earlier exchange rate available" << std::endl;
        return ;
    }
    --it;
    
    result = val * it->second;
    std::cout << date << " => " << val << " = " << result << std::endl;
}
