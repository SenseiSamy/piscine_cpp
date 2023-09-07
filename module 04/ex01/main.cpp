/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:27:01 by snaji             #+#    #+#             */
/*   Updated: 2023/09/07 18:40:38 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	Animal	*tab[100];

	for (int i = 0; i < 50; ++i)
		tab[i] = new Dog();
	for (int i = 50; i < 100; ++i)
		tab[i] = new Cat();

	for (int i = 0; i < 100; ++i)
		delete tab[i];
}