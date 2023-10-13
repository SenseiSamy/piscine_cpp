/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:27:01 by snaji             #+#    #+#             */
/*   Updated: 2023/10/13 17:39:15 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{

	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;
	// delete i;
	// {
	// 	Cat* cat = new Cat();
	// 	cat->setBrain("Salut", 0);
	// 	cat->setBrain("Ca va", 1);
	// 	std::cout << cat->getBrain(0) << std::endl;
	// 	std::cout << cat->getBrain(1) << std::endl;
	// 	std::cout << cat->getBrain(50) << std::endl;
	// 	delete cat;
	// }
	// std::cout << "------------------------------------------------------" << std::endl;
	// {
	// 	Cat cat;
	// 	Cat catClone;
	// 	cat.setBrain("test cpy", 60);
	// 	catClone = cat;
	// 	std::cout << "CPY CAT:\t\t" << catClone.getBrain(60) << std::endl;

	// }
	// std::cout << "------------------------------------------------------" << std::endl;
	// {
	// 	Cat cat;
	// 	cat.setBrain("test cpy", 60);
	// 	Cat catClone(cat);
	// 	std::cout << "CPY CAT:\t\t" << catClone.getBrain(60) << std::endl;
	// }
	// std::cout << "------------------------------------------------------" << std::endl;
	// {
	// 	Cat test;
	// 	Cat test2 = test;
	// }
	// std::cout << "------------------------------------------------------" << std::endl;
	// std::cout << "------------------------------------------------------" << std::endl;
	// {
	// 	Dog* dog = new Dog();
	// 	dog->setBrain("Salut", 0);
	// 	dog->setBrain("Ca va", 103);
	// 	std::cout << dog->getBrain(0) << std::endl;
	// 	std::cout << dog->getBrain(1) << std::endl;
	// 	std::cout << dog->getBrain(50) << std::endl;
	// 	delete dog;
	// }
	// {
	// 	Dog dog;
	// 	Dog dogClone;
	// 	dog.setBrain("test cpy", 60);
	// 	dogClone = dog;
	// 	std::cout << "CPY dog:\t\t" << dogClone.getBrain(60) << std::endl;

	// }
	// std::cout << "------------------------------------------------------" << std::endl;

	// {
	// 	Dog dog;
	// 	dog.setBrain("test cpy", 60);
	// 	Dog dogClone(dog);
	// 	std::cout << "CPY dog:\t\t" << dogClone.getBrain(60) << std::endl;
	// }
	// std::cout << "------------------------------------------------------" << std::endl;

	// {
	// 	Dog test;
	// 	Dog test2 = test;
	// }
	// std::cout << "------------------------------------------------------" << std::endl;
	// {
	// 	Dog dog;
	// 	dog.setBrain("test cpy", -10);
	// 	dog.setBrain("test cpy", 10);
	// 	dog.setBrain("test cpy", 100);
	// }


	Animal	*tab[100];

	for (int i = 0; i < 50; ++i)
		tab[i] = new Dog();
	for (int i = 50; i < 100; ++i)
		tab[i] = new Cat();

	for (int i = 0; i < 100; ++i)
		delete tab[i];
}