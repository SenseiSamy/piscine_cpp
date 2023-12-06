/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:36:35 by snaji             #+#    #+#             */
/*   Updated: 2023/12/06 02:35:36 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	int	i;

	{
		std::vector<int>	vector;

		for (i = 0; i < 10; ++i)
			vector.push_back(i);
		easyfind< std::vector<int> >(vector, 4) = 69;
		for (i = 0; i < 10; ++i)
			std::cout << vector[i] << " ";
		std::cout << "\n";
	}
	{
		std::list<int>				list;
		std::list<int>::iterator	it;

		for (i = 0; i < 10; ++i)
			list.push_back(i);
		easyfind< std::list<int> >(list, 9) = 42;
		for (it = list.begin(); it != list.end(); ++it)
			std::cout << *it << " ";
		std::cout << "\n";

		try
		{
			easyfind< std::list<int> >(list, 20) = 42;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}