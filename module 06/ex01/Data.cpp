/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:06:57 by snaji             #+#    #+#             */
/*   Updated: 2023/11/13 17:38:22 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _s("") {}

Data::Data(const std::string &s): _s(s) {}

Data::Data(const Data &copy): _s(copy._s) {}

Data::~Data(void) {}

Data	&Data::operator=(const Data &copy)
{
	_s = copy._s;
	return (*this);
}

std::string Data::getString(void)
{
	return (_s);
}