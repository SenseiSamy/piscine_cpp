/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:10:11 by snaji             #+#    #+#             */
/*   Updated: 2024/01/19 21:12:17 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int>	a;
	a.push_back(5);
	a.push_back(7);
	a.push_back(8);
	a.push_back(4);
	a.push_back(2);
	a.push_back(1);
	a.push_back(6);
	a.push_back(9);

	MergeInsertSort(a.begin(), a.end());

	for (std::vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
	{
		std::cout << *iter << " ";
	}		
}