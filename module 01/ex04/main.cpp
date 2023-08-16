/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:07:11 by snaji             #+#    #+#             */
/*   Updated: 2023/08/16 17:57:01 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static bool	open_files(std::string name, std::ifstream &file,
	std::ofstream &file_replace)
{
	file.open(name.c_str());
	if (file.is_open() == false)
	{
		std::cout << "Unable to open input file" << std::endl;
		return (false);
	}
	file_replace.open((name + ".replace").c_str());
	if (file.is_open() == false)
	{
		file.close();
		std::cout << "Unable to open output file" << std::endl;
		return (false);
	}
	return (true);
}

void	replace_str(std::string &file, std::string s1, std::string s2)
{
	std::size_t	i;

	if (s1.empty())
		return ;
	i = file.find(s1);
	while (i != std::string::npos)
	{
		file.erase(i, s1.size());
		file.insert(i, s2);
		i = file.find(s1, i + s2.size());
	}
}

int	main(int ac, char **av)
{
	std::ifstream	file;
	std::ofstream	file_replace;
	std::string		file_copy;
	std::string		tmp;

	if (ac != 4)
		return (std::cout << "The program takes 3 arguments" << std::endl, 1);
	if (open_files(std::string(av[1]), file, file_replace) == false)
		return (1);
	while (std::getline(file, tmp))
		file_copy += tmp + "\n";
	file.close();
	replace_str(file_copy, std::string(av[2]), std::string(av[3]));
	file_replace << file_copy;
	file_replace.close();
	return (0);
}
