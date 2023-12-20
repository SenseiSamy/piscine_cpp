/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:54:04 by snaji             #+#    #+#             */
/*   Updated: 2023/12/21 00:16:08 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Ansi.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	{
		Span	span(10);

		std::cout << ansi::bold << "TEST 1: 10 random numbers (0 to 10000)\n"
			<< ansi::reset;

		for (int i = 0; i < 10; ++i)
			span.addNumber(std::rand() % 10000);

		std::cout << "shortest span: " << span.shortestSpan() << "\n";
		std::cout << "longest span: " << span.longestSpan() << "\n\n";
	}
	{
		Span	span(100);

		std::cout << ansi::bold << "TEST 2: 100 random numbers (0 to 10000)\n"
			<< ansi::reset;

		for (int i = 0; i < 100; ++i)
			span.addNumber(std::rand() % 10000);

		std::cout << "shortest span: " << span.shortestSpan() << "\n";
		std::cout << "longest span: " << span.longestSpan() << "\n\n";
	}
	{
		Span	span(100000);

		std::cout << ansi::bold << "TEST 3: 100000 random numbers (0 to MAXINT"
			")\n" << ansi::reset;

		for (int i = 0; i < 100000; ++i)
			span.addNumber(std::rand());

		std::cout << "shortest span: " << span.shortestSpan() << "\n";
		std::cout << "longest span: " << span.longestSpan() << "\n\n";
	}
	{
		Span	span(10);
		
		std::cout << ansi::bold << "TEST 4: add to full span\n"
			<< ansi::reset;

		for (int i = 0; i < 10; ++i)
			span.addNumber(std::rand() % 1000);
		
		try
		{
			span.addNumber(10);
		}
		catch (std::exception &e)
		{
			std::cout << "ERROR: " << e.what() << "\n";
		}
	}
}
