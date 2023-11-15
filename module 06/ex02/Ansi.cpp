/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ansi.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:33:56 by snaji             #+#    #+#             */
/*   Updated: 2023/10/10 19:21:07 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ansi.hpp"
#include <sstream>

std::ostream	&ansi::reset(std::ostream &os)
{
	return (os << "\e[0m");
}

std::ostream	&ansi::bold(std::ostream &os)
{
	return (os << "\e[1m");	
}

std::ostream	&ansi::dim(std::ostream &os)
{
	return (os << "\e[2m");	
}

std::ostream	&ansi::italic(std::ostream &os)
{
	return (os << "\e[3m");	
}

std::ostream	&ansi::underline(std::ostream &os)
{
	return (os << "\e[4m");	
}

std::ostream	&ansi::blinking(std::ostream &os)
{
	return (os << "\e[5m");	
}

std::ostream	&ansi::inverse(std::ostream &os)
{
	return (os << "\e[7m");	
}

std::ostream	&ansi::hidden(std::ostream &os)
{
	return (os << "\e[8m");	
}

std::ostream	&ansi::strike(std::ostream &os)
{
	return (os << "\e[9m");	
}

std::ostream	&ansi::black(std::ostream &os)
{
	return (os << "\e[30m");	
}

std::ostream	&ansi::red(std::ostream &os)
{
	return (os << "\e[31m");	
}

std::ostream	&ansi::green(std::ostream &os)
{
	return (os << "\e[32m");	
}

std::ostream	&ansi::yellow(std::ostream &os)
{
	return (os << "\e[33m");	
}

std::ostream	&ansi::blue(std::ostream &os)
{
	return (os << "\e[34m");	
}

std::ostream	&ansi::magenta(std::ostream &os)
{
	return (os << "\e[35m");	
}

std::ostream	&ansi::cyan(std::ostream &os)
{
	return (os << "\e[36m");	
}

std::ostream	&ansi::white(std::ostream &os)
{
	return (os << "\e[37m");	
}

std::string	ansi::c256(unsigned int n)
{
	std::stringstream	os;

	os << "\e[38;5;" << n << "m";
	return (os.str());
}

std::string	ansi::rgb(unsigned int r, unsigned int g,
	unsigned int b)
{
	std::stringstream	os;

	os << "\e[38;2;" << r << ";" << g << ";" << b << "m";
	return (os.str());	
}
	