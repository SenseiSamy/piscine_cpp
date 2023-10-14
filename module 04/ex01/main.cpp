/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:27:01 by snaji             #+#    #+#             */
/*   Updated: 2023/10/14 17:08:05 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int	main(void)
{
	Animal	*tab[100];

	for (int i = 0; i < 50; ++i)
		tab[i] = new Dog();
	for (int i = 50; i < 100; ++i)
		tab[i] = new Cat();

	for (int i = 0; i < 100; ++i)
		delete tab[i];

	std::cout << "\n\e[1;3mDeep copy test\e[0m\n";
	{
		Cat	cat;
		Cat	catcopy;

		cat.setIdea(0, "coucou");
		cat.setIdea(20, "salut");
		cat.setIdea(45, "heyyy");
		catcopy = cat;
		std::cout << catcopy.getIdea(0) << std::endl;
		std::cout << catcopy.getIdea(20) << std::endl;
		std::cout << catcopy.getIdea(45) << std::endl;
		Cat	catcopy2(cat);
		std::cout << catcopy.getIdea(0) << std::endl;
		std::cout << catcopy.getIdea(20) << std::endl;
		std::cout << catcopy.getIdea(45) << std::endl;
	}	
}