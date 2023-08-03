/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:37:39 by snaji             #+#    #+#             */
/*   Updated: 2023/07/31 17:12:15 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::add(void)
{
	if (this->curr_id == 8)
		this->curr_id = 0;
	this->contacts[this->curr_id].fill();
	this->curr_id += 1;
}

static std::string	print_arg(std::string arg)
{
	size_t	size = arg.size();

	if (size > 10)
		return (arg.substr(0, 9) + ".");
	for (size_t i = 0; i < 10 - size; ++i)
		arg = " " + arg;
	return (arg);
}

void	PhoneBook::search(void) const
{
	int	id;

	for (size_t i = 0; i < 8; ++i)
		std::cout << "|" << print_arg(std::to_string(i + 1)) << "|"
			<< print_arg(this->contacts[i].first_name) << "|"
			<< print_arg(this->contacts[i].last_name) << "|" << std::endl;
	std::cout << "ID: ";
	std::cin >> id;
	if (id >= 1 && id <= 8)
	{
		std::cout << "First name: " << this->contacts[id - 1].first_name
			<< std::endl;
		std::cout << "Last name: " << this->contacts[id - 1].last_name
			<< std::endl;
		std::cout << "Nickname: " << this->contacts[id - 1].nickname
			<< std::endl;
		std::cout << "Phone number: " << this->contacts[id - 1].phone_number
			<< std::endl;
		std::cout << "Darkest secret: " << this->contacts[id - 1].secret
			<< std::endl;
	}
	else
		std::cout << "ID must be between 1 and 8" << std::endl;
}