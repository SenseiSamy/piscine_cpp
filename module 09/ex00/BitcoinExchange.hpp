/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:04:03 by snaji             #+#    #+#             */
/*   Updated: 2023/12/29 20:27:19 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>
# include <fstream>

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
};

class	BitcoinExchange
{
	private:
		

	public:
		std::map<Date, float>	_database;
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &copy);

		void	filldatabase(const std::string &filename);
};

#endif