/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:10 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 18:54:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	ShrubberyCreationForm	F1("42");
	RobotomyRequestForm		F2("Mountain");
	PresidentialPardonForm	F3("Lukas");
	
	Bureaucrat				A("Didier", 100);
	Bureaucrat				B("Henri", 60);
	Bureaucrat				C("Jean", 1);

	A.signForm(F1);
	A.executeForm(F1);
	B.signForm(F2);
	B.executeForm(F2);
	C.executeForm(F2);
	B.signForm(F3);
	C.signForm(F3);
	C.executeForm(F3);
	return (0);
}