/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:33:32 by snaji             #+#    #+#             */
/*   Updated: 2023/09/20 17:57:20 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\e[3m\e[1mCreating 3 Animal\e[0m" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "\e[3m\e[1mPrinting the types\e[0m" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl << "\e[3m\e[1mCalling the makeSound method\e[0m"
		<< std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << std::endl << "\e[3m\e[1mDeleting the 3 Animal\e[0m"
		<< std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl << "\e[3m\e[1mSame tests with WrongAnimal and "
		"WrongCat\e[0m" << std::endl;

	const WrongAnimal *a = new WrongAnimal();
	const WrongAnimal *b = new WrongCat();
	
	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;

	a->makeSound();
	b->makeSound();

	delete a;
	delete b;

	return (0);
}