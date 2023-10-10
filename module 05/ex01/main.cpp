/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:10 by snaji             #+#    #+#             */
/*   Updated: 2023/10/10 19:28:36 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	Form		FORM1("High Grade", 5, 5);
	Form		FORM2("Medium Grade", 70, 70);
	Form		FORM3("Low Grade", 130, 130);

	Bureaucrat	CEO("CEO", 1);
	Bureaucrat	EMPLOYEE("Employee", 80);
	Bureaucrat	INTERN("Intern", 150);

	INTERN.signForm(FORM3);
	std::cout << FORM3 << std::endl;
	EMPLOYEE.signForm(FORM3);
	std::cout << FORM3 << std::endl;
	EMPLOYEE.signForm(FORM2);
	std::cout << FORM2 << std::endl;
	CEO.signForm(FORM2);
	std::cout << FORM2 << std::endl;
	CEO.signForm(FORM1);
	std::cout << FORM1 << std::endl;
	
	return (0);
}