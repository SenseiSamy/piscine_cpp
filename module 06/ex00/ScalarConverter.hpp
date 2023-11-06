/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:53:04 by snaji             #+#    #+#             */
/*   Updated: 2023/11/06 15:47:41 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <sstream>

enum	Error
{
	NotPrintable,
	Overflow,
	NoError
};

enum	Type
{
	Char,
	Int,
	Float,
	Double,
	None
};

class	ScalarConverter
{
	private:
		static Type		type;
		static Error	errors[4];
		static char		charValue;
		static int		intValue;
		static float	floatValue;
		static double	doubleValue;

		static bool		isChar(const std::string &literal);
		static bool		isInt(const std::string &literal);
		static bool		isFloat(const std::string &literal);
		static bool		isDouble(const std::string &literal);
		static void		detectType(const std::string &literal);


		static char		toChar(const int toConvert);
		static char		toChar(const float toConvert);
		static char		toChar(const double toConvert);
		static int		toInt(const char toConvert);
		static int		toInt(const float toConvert);
		static int		toInt(const double toConvert);
		static float	toFloat(const char toConvert);
		static float	toFloat(const int toConvert);
		static float	toFloat(const double toConvert);
		static double	toDouble(const char toConvert);
		static double	toDouble(const int toConvert);
		static double	toDouble(const float toConvert);
		static void		convertOtherTypes(void);

		static void		printConversion(void);

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter(void);

		ScalarConverter	&operator=(const ScalarConverter &copy);

	public:
		static void	convert(const std::string &literal);
};

#endif