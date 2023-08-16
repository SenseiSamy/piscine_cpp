/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:22:39 by snaji             #+#    #+#             */
/*   Updated: 2023/08/16 19:32:13 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pic"
		"kle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You did"
		"n’t putenough bacon in my burger ! If you did, I wouldn’t be asking fo"
		"r more !" << std::endl;
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

	try
	{
		f = Harl::_comments.at(level);
		(this->*f)();
	}
	catch (std::out_of_range)
	{
		std::cerr << "This level of comment does not exist." << std::endl;
	}
}

Harl::harlmap	Harl::init_map(void)
{
	Harl::harlmap	map;

	map["DEBUG"] = &Harl::debug;
	map["INFO"] = &Harl::info;
	map["WARNING"] = &Harl::warning;
	map["ERROR"] = &Harl::error;
	return (map);
}

Harl::harlmap	Harl::_comments = Harl::init_map();
