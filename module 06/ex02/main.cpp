/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:05:41 by snaji             #+#    #+#             */
/*   Updated: 2023/11/15 18:42:16 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Ansi.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	int		i;
	
	std::srand(std::time(NULL));
	i = std::rand() % 3;
	if (i == 0)
		return (dynamic_cast<Base *>(new A));
	else if (i == 1)
		return (dynamic_cast<Base *>(new B));
	else
		return (dynamic_cast<Base *>(new C));
}

void	identify(Base *p)
{
	std::cout << ansi::bold;
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B\n";
	else
		std::cout << "C\n";
	std::cout << ansi::reset;
}

void	identify(Base &p)
{
	std::cout << ansi::bold;
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B\n";
	else
		std::cout << "C\n";
	std::cout << ansi::reset;
}

int	main(void)
{
	Base	*ptr;
	
	std::cout << ansi::bold << "Generating a random A, B or C..\n\n"
		<< ansi::reset;
	ptr = generate();

	std::cout << ansi::italic << "Calling identify(Base *p)\n" << ansi::reset
		<< "The type is : " << ansi::reset;
	identify(ptr);

	std::cout << ansi::italic << "\nCalling identify(Base &p)\n" << ansi::reset
		<< "The type is : " << ansi::reset;
	identify(*ptr);
}