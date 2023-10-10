/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:15:10 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 01:20:55 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	ShrubberyCreationForm	A("ici");
	Bureaucrat				B("Jean", 1);

	B.signForm(A);
	A.execute(B);
	return (0);
}