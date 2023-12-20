/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:54:04 by snaji             #+#    #+#             */
/*   Updated: 2023/12/12 19:12:32 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	main(void)
{
	Span	span(100000);
	
	clock_t	begin = clock();
	clock_t	end;

	std::srand(std::time(NULL));
	for (int i = 0; i < 10; ++i)
		span.addNumber(std::rand() % 1000);

	end = clock() - begin;

	std::cout << "Took " << (float)end / CLOCKS_PER_SEC << " seconds\n";

	std::cout << span.shortestSpan() << "\n";
	std::cout << span.longestSpan() << "\n";
}
