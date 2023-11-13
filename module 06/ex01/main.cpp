/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:33:00 by snaji             #+#    #+#             */
/*   Updated: 2023/11/13 17:38:30 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data("coucou");
	Data		*data2;
	uintptr_t	ptr;

	ptr = Serializer::serialize(&data);
	data2 = Serializer::deserialize(ptr);
	std::cout << data2->getString();
}