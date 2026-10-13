/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tide-pau <tide-pau@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:41:09 by tide-pau          #+#    #+#             */
/*   Updated: 2026/10/13 20:13:34 by tide-pau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class   BitcoinExchange
{
    private:
        std::map<std::string, float> _dataBase;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    loadDataBase(const std::string&   fileName);
        void    parseInput(const std::string& fileName);

        void    printDataBase() const;
        bool    isValidLine(const std::string& line, bool y) const;
        bool    isValidDate(const std::string& date) const;
        bool    isLeapYear(int year) const;
        float   isValidValue(const std::string& value, bool y) const;
        void    calculateValue(std::string& date, float val) const;
};

# endif