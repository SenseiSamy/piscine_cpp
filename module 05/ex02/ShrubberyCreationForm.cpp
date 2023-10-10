/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:54:37 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 01:18:28 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include "Trees.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm("ShrubberyCreationForm", 145, 137)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const
	ShrubberyCreationForm &copy)
{
	this->_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	file;

	if (this->isSigned() && executor.getGrade() <= this->getExecGrade())
	{
		file.open((this->_target + "_shrubbery").c_str());
		file << TREES;
		file.close();
	}
}
