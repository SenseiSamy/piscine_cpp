/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:27:53 by snaji             #+#    #+#             */
/*   Updated: 2023/12/28 02:07:53 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	MutantStack<int> mstack;

	for (int i = 1; i < 20; ++i)
		mstack.push(i);
	
	std::cout << "\e[1mStack methods\e[0m\n";
	std::cout << "top element is = " << mstack.top() << "\n";
	std::cout << "calling mstack.pop()\n";
	mstack.pop();
	std::cout << "top element is = " << mstack.top() << "\n";
	std::cout << "stack size is " << mstack.size() << "\n";

	MutantStack<int>::iterator	it;

	std::cout << "\n\e[1mIterator test\e[0m\n";
	std::cout << "printing the stack from beginning to end\n";
	it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\nprinting the stack from end to beginning\n";
	it = mstack.end() - 1;
	while (it != mstack.begin() - 1)
	{
		std::cout << *it << " ";
		--it;
	}
}
