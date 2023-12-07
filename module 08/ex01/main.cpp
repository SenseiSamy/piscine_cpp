/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:54:04 by snaji             #+#    #+#             */
/*   Updated: 2023/12/07 21:27:48 by snaji            ###   ########.fr       */
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
	for (int i = 0; i < 100000; ++i)
		span.addNumber(std::rand());
	end = clock() - begin;
	std::cout << "Took " << (float)end / CLOCKS_PER_SEC << " seconds\n";
}
