/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:28:48 by snaji             #+#    #+#             */
/*   Updated: 2023/11/24 23:05:57 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int	main(void)
{
	{
		Array<int>	ArrayInt(20);
		
		for (int i = 0; i < 20; ++i)
			ArrayInt[i] = i * 3;
		std::cout << "Taille de ArrayInt: " << ArrayInt.size() << "\n";
		for (int i = 0; i < 20; ++i)
			std::cout << ArrayInt[i] << " ";
		std::cout << "\n";
	}
	{
		Array<std::string>	ArrayString(4);
		Array<std::string>	ArrayStringCopy;
		
		ArrayString[0] = "Coucou";
		ArrayString[1] = "comment";
		ArrayString[2] = "ca";
		ArrayString[3] = "va?";
	
		ArrayStringCopy = ArrayString;
		ArrayStringCopy[0] = "Salut";
		
		std::cout << "Taille de ArrayString: " << ArrayString.size() << "\n";
		for (int i = 0; i < 4; ++i)
			std::cout << ArrayString[i] << " ";
		std::cout << "\n";

		std::cout << "Taille de ArrayStringCopy: " << ArrayString.size()
			<< "\n";
		for (int i = 0; i < 4; ++i)
			std::cout << ArrayStringCopy[i] << " ";
		std::cout << "\n";

		try
		{
			ArrayString[4] = "trop loin";
		}
		catch (std::out_of_range &exception)
		{
			std::cout << "Exception: " << exception.what() << "\n";
		}
	}
	{
		Array<char>	C(0);
	}
}