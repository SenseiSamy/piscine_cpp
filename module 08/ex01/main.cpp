/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:54:04 by snaji             #+#    #+#             */
/*   Updated: 2023/12/13 19:07:49 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main(void)
{
	Span				span(10000000);
	clock_t				begin;
	clock_t				end;

	std::srand(std::time(NULL));

	begin = clock();
	// for (int i = 0; i < 10000000; ++i)
	// 	span.addNumber(std::rand() % 50);
	span.addNumber(1);
	span.addNumber(50);
	span.addNumber(10);
	end = clock() - begin;

	// std::cout << span.shortestSpan() << "\n";
	// std::cout << span.longestSpan() << "\n";


	std::cout << "Took " << (float)end / CLOCKS_PER_SEC << " seconds\n";
}
