/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:12:34 by snaji             #+#    #+#             */
/*   Updated: 2023/11/17 17:27:09 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	square(int &n)
{
	n = n * n;
}

void	toUpper(std::string &str)
{
	for (unsigned int i = 0; i < str.size(); ++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
}

int	main(void)
{
	int			i;
	int			tab1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string	tab2[5] = {"Hey", "comMeNt", "CA", "va", "????"};

	iter<int>(tab1, 10, &square);
	for (i = 0; i < 10; ++i)
		std::cout << tab1[i] << " ";
	std::cout << "\n";

	iter<std::string>(tab2, 5, &toUpper);
	for (i = 0; i < 5; ++i)
		std::cout << tab2[i] << " ";
	std::cout << "\n";

	return (0);
}