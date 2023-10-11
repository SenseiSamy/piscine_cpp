/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:07:00 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 19:56:51 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Ansi.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern(void) {}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm	*Intern::makeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}


AForm	*Intern::makeForm(const std::string &form, const std::string &target)
{
	AForm		*Form;
	std::string	str[3] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
	AForm 		*(Intern::*forms[3])(const std::string &) = 
		{&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};
	
	for (int i = 0; i < 3; ++i)
		if (form == str[i])
		{
			Form = (this->*forms[i])(target);
			std::cout << ansi::bold << "Intern" << ansi::reset << " creates For"
				"m " << ansi::bold << Form->getName() << ansi::reset
				<< std::endl;
			return (Form);
		}
	std::cout << ansi::bold << "Intern" << ansi::reset << " couldn't create '"
		<< form << "' because this form doesn't exist." << std::endl;
	return (NULL);
}