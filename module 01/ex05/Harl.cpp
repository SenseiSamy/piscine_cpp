/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:22:39 by snaji             #+#    #+#             */
/*   Updated: 2023/09/12 19:42:26 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	this->_comments[0] = "DEBUG";
	this->_comments[1] = "INFO";
	this->_comments[2] = "WARNING";
	this->_comments[3] = "ERROR";
	this->_functions[0] = &Harl::debug;
	this->_functions[1] = &Harl::info;
	this->_functions[2] = &Harl::warning;
	this->_functions[3] = &Harl::error;
}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pic"
		"kle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You did"
		"n’t put enough bacon in my burger ! If you did, I wouldn’t be asking f"
		"or more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve bee"
		"n coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f)(void);

	f = NULL;
	for (int i = 0; i < 4; ++i)
		if (this->_comments[i].compare(level) == 0)
			f = this->_functions[i];
	if (f)
		(this->*f)();
}
