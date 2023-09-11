/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:33:37 by snaji             #+#    #+#             */
/*   Updated: 2023/09/11 22:01:54 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string	input;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int n = 1; n < argc; ++n)
		{
			input = std::string(argv[n]);
			for (std::string::iterator it = input.begin(); it != input.end();
				++it)
				*it = toupper(*it);
			std::cout << input;
		}
		std::cout << std::endl;
	}
	return (0);
}
