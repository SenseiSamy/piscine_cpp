/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:27:26 by snaji             #+#    #+#             */
/*   Updated: 2023/09/11 21:21:18 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

Contact::Contact(void): first_name(""), last_name(""), nickname(""),
	phone_number(""), secret("")
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::fill(void)
{
	std::string	input;

	std::cout << std::setw(20) << "First name: \e[1m";
	std::getline(std::cin, this->first_name);
	std::cout << "\e[0m" << std::setw(20) << "Last name: \e[1m";
	std::getline(std::cin, this->last_name);
	std::cout << "\e[0m" << std::setw(20) << "Nickname: \e[1m";
	std::getline(std::cin, this->nickname);
	std::cout << "\e[0m" << std::setw(20) << "Phone number: \e[1m";
	std::getline(std::cin, this->phone_number);
	std::cout << "\e[0m" << std::setw(20) << "Darkest secret: \e[1m";
	std::getline(std::cin, this->secret);
	std::cout << "\e[0m";
}
