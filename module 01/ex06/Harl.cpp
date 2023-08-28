/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:56:32 by snaji             #+#    #+#             */
/*   Updated: 2023/08/28 18:16:53 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pic"
		"kle-specialketchup burger. I really do !" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You did"
		"n’t putenough bacon in my burger ! If you did, I wouldn’t be asking fo"
		"r more !" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve bee"
		"n coming for years whereas you started working here since last month."
		<< std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now."
		<< std::endl << std::endl;
}

void	Harl::complain(enum Harl::e_comment level)
{
	switch (level)
	{
		case Harl::DEBUG:
			this->debug();
		case Harl::INFO:
			this->info();
		case Harl::WARNING:
			this->warning();
		case Harl::ERROR:
			this->error();
		default:
			break;
	}
}
