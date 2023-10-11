/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:10 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 19:55:39 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	AForm		*Form;
	Bureaucrat	C("Jean", 1);
	Intern		D;

	Form = D.makeForm("shrubbery creation", "42");
	C.signForm(*Form);
	C.executeForm(*Form);
	Form = D.makeForm("robotomy request", "mountain");
	C.signForm(*Form);
	C.executeForm(*Form);
	Form = D.makeForm("presidential pardon", "lukas");
	C.signForm(*Form);
	C.executeForm(*Form);
	Form = D.makeForm("help", "idk");
	return (0);
}