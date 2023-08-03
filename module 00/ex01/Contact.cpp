/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:27:26 by snaji             #+#    #+#             */
/*   Updated: 2023/07/31 16:55:02 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
	std::cout << "First name: ";
	std::cin >> this->first_name;
	std::cout << "Last name: ";
	std::cin >> this->last_name;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	std::cout << "Phone number: ";
	std::cin >> this->phone_number;
	std::cout << "Darkest secret: ";
	std::cin >> this->secret;
}
