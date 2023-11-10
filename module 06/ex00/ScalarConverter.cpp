/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:13:13 by snaji             #+#    #+#             */
/*   Updated: 2023/11/10 18:39:29 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

bool	ScalarConverter::isChar(const std::string &literal)
{
	return (literal.size() == 1 && (literal[0] >= 32 && literal[0] <= 126));
}

static bool	isNum(const std::string &literal)
{
	std::string			absValue;

	if (literal.size() == 0 || (literal.size() == 1 && literal[0] == '-'))
		return (false);
	absValue = literal[0] == '-' ? literal.substr(1) : literal;
	for (size_t i = 0; i < absValue.size(); ++i)
		if (absValue[i] < '0' || absValue[i] > '9')
			return (false);
	return (true);
}

bool	ScalarConverter::isInt(const std::string &literal)
{
	return (isNum(literal));
}

bool	ScalarConverter::isFloat(const std::string &literal)
{
	return (ScalarConverter::isDouble(literal.substr(0, literal.size() - 1))
		&& literal[literal.size() - 1] == 'f');
}

bool	ScalarConverter::isDouble(const std::string &literal)
{
	std::string	literal2 = literal[0] == '-' ? literal.substr(1) : literal;
	size_t		i = literal.find('.');
	std::string	integer;
	std::string	fractional;

	if (i == std::string::npos || i != literal.rfind('.'))
		return (false);
	integer = literal.substr(0, i);
	fractional = literal.substr(i + 1, std::string::npos);
	return (isNum(integer) && isNum(fractional));
}

bool	ScalarConverter::checkSpecial(const std::string &literal)
{
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
	{
		type = Float;
		if (literal == "+inff")
			floatValue = std::numeric_limits<float>::infinity();
		else if (literal == "-inff")
			floatValue = std::numeric_limits<float>::infinity() * -1;
		else
			floatValue = std::numeric_limits<float>::quiet_NaN();
	}
	else if (literal == "+inf" || literal == "-inf" || literal == "nan")
	{
		type = Double;
		if (literal == "+inf")
			doubleValue = std::numeric_limits<double>::infinity();
		else if (literal == "-inf")
			doubleValue = std::numeric_limits<double>::infinity() * -1;
		else
			doubleValue = std::numeric_limits<double>::quiet_NaN();
	}
	else
		return (false);
	return (true);
}

void	ScalarConverter::detectType(const std::string &literal)
{
	if (ScalarConverter::isInt(literal))
	{
		type = Int;
		std::stringstream(literal) >> intValue;
	}
	else if (ScalarConverter::isChar(literal))
	{
		type = Char;
		charValue = literal[0];
	}
	else if (ScalarConverter::isFloat(literal))
	{
		type = Float;
		std::stringstream(literal) >> floatValue;
	}
	else if (ScalarConverter::isDouble(literal))
	{
		type = Double;
		std::stringstream(literal) >> doubleValue;
	}
	else if (!checkSpecial(literal))
		type = None;
}

char	ScalarConverter::toChar(const int toConvert)
{
	if (toConvert <= std::numeric_limits<char>::max()
		&& toConvert >= std::numeric_limits<char>::min())
	{
		if (toConvert >= 32 && toConvert <= 126)
			return (static_cast<char>(toConvert));
		errors[Char] = NotPrintable;
		return (0);
	}
	errors[Char] = Overflow;
	return (0);
}

char	ScalarConverter::toChar(const float toConvert)
{
	if (toConvert <= std::numeric_limits<char>::max()
		&& toConvert >= std::numeric_limits<char>::min())
	{
		if (toConvert >= 32 && toConvert <= 126)
			return (static_cast<char>(toConvert));
		errors[Char] = NotPrintable;
		return (0);
	}
	errors[Char] = Overflow;
	return (0);
}

char	ScalarConverter::toChar(const double toConvert)
{
	if (toConvert <= std::numeric_limits<char>::max()
		&& toConvert >= std::numeric_limits<char>::min())
	{
		if (toConvert >= 32 && toConvert <= 126)
			return (static_cast<char>(toConvert));
		errors[Char] = NotPrintable;
		return (0);
	}
	errors[Char] = Overflow;
	return (0);
}

int		ScalarConverter::toInt(const char toConvert)
{
	return (static_cast<int>(toConvert));
}

int		ScalarConverter::toInt(const float toConvert)
{
	if (toConvert < std::numeric_limits<int>::max()
		&& toConvert > std::numeric_limits<int>::min())
		return (static_cast<int>(toConvert));
	errors[Int] = Overflow;
	return (0);
}

int		ScalarConverter::toInt(const double toConvert)
{
	if (toConvert < std::numeric_limits<int>::max()
		&& toConvert > std::numeric_limits<int>::min())
		return (static_cast<int>(toConvert));
	errors[Int] = Overflow;
	return (0);
}

float	ScalarConverter::toFloat(const char toConvert)
{
	return (static_cast<float>(toConvert));
}

float	ScalarConverter::toFloat(const int toConvert)
{
	return (static_cast<float>(toConvert));
}

float	ScalarConverter::toFloat(const double toConvert)
{
	if (toConvert != toConvert)
		return (std::numeric_limits<float>::quiet_NaN());
	if (toConvert < std::numeric_limits<float>::max()
		&& toConvert > std::numeric_limits<float>::min())
		return (static_cast<float>(toConvert));
	errors[Float] = Overflow;
	return (0.0f);
}

double	ScalarConverter::toDouble(const char toConvert)
{
	return (static_cast<double>(toConvert));
}

double	ScalarConverter::toDouble(const int toConvert)
{
	return (static_cast<double>(toConvert));
}

double	ScalarConverter::toDouble(const float toConvert)
{
	return (static_cast<double>(toConvert));
}

void	ScalarConverter::convertOtherTypes(void)
{
	switch (type)
	{
		case Char:
			intValue = toInt(charValue);
			floatValue = toFloat(charValue);
			doubleValue	= toDouble(charValue);
			break;
		case Int:
			charValue = toChar(intValue);
			floatValue = toFloat(intValue);
			doubleValue = toDouble(intValue);
			break;
		case Float:
			charValue = toChar(floatValue);
			intValue = toInt(floatValue);
			doubleValue = toDouble(floatValue);
			break;
		case Double:
			charValue = toChar(doubleValue);
			intValue = toInt(doubleValue);
			floatValue = toFloat(doubleValue);
			break;
		default:
			break;
	}
}

static std::string	getError(Error err)
{
	switch (err)
	{
		case NotPrintable:
			return ("Non displayable");
		case Overflow:
			return ("Overflow");
		default:
			return ("Undefined error");
	}
}

void	ScalarConverter::printConversion(void)
{
	if (errors[Char] == NoError)
		std::cout << "char: " << charValue << "\n";
	else
		std::cout << "char: " << getError(errors[Char]) << "\n";

	if (errors[Int] == NoError)
		std::cout << "int: " << intValue << "\n";
	else
		std::cout << "int: " << getError(errors[Int]) << "\n";

	if (errors[Float] == NoError)
		std::cout << "float: " << std::fixed << std::setprecision(1)
			<< floatValue << "f\n";
	else
		std::cout << "float: " << getError(errors[Float]) << "\n";

	if (errors[Double] == NoError)
		std::cout << "double: " << doubleValue << "\n";
	else
		std::cout << "double: " << getError(errors[Double]) << "\n";
}

void	ScalarConverter::convert(const std::string &literal)
{
	for (int i = 0; i < 4; ++i)
		errors[i] = NoError;
	detectType(literal);
	if (type == None)	
		std::cout << "Couldn't convert the string to any type.\n";
	else
	{
		std::cout << "\e[1mtype: ";
		switch (type)
		{
			case Char:
				std::cout << "char";
				break;
			case Int:
				std::cout << "int";
				break;
			case Float:
				std::cout << "float";
				break;
			case Double:
				std::cout << "double";
				break;
			default:
				break;
		}
		std::cout << "\n\e[0m";
		convertOtherTypes();
		printConversion();
	}
}

Type	ScalarConverter::type = None;
Error	ScalarConverter::errors[4] = {NoError, NoError, NoError, NoError};
char	ScalarConverter::charValue = 0;
int		ScalarConverter::intValue = 0;
float	ScalarConverter::floatValue = 0.0f;
double	ScalarConverter::doubleValue = 0.0;
