/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:04:03 by snaji             #+#    #+#             */
/*   Updated: 2024/01/09 17:50:55 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>
# include <fstream>
# include <sstream>

class	Date
{
	private:
		int				_year;
		unsigned int	_month;
		unsigned int	_day;

	public:
		Date(void);
		Date(const std::string &date);
		Date(const Date &copy);
		~Date(void);

		Date	&operator=(const Date &copy);
		bool	operator==(const Date &other) const;
		bool	operator>(const Date &other) const;
		bool	operator<(const Date &other) const;
		
		std::string	print(void) const;
		bool		isValid(void) const;
};

class	BitcoinExchange
{
	private:
		std::map<Date, float>	_database;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &copy);

		void	filldatabase(const std::string &filename);
		std::map<Date, float>::const_iterator	begin(void) const;
		std::map<Date, float>::const_iterator	end(void) const;
};

#endif