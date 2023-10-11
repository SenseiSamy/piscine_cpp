/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:01:56 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 19:40:26 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern	&operator=(const Intern &copy);
		
		AForm	*makeShrubberyCreationForm(const std::string &target);
		AForm	*makeRobotomyRequestForm(const std::string &target);
		AForm	*makePresidentialPardonForm(const std::string &target);
		AForm	*makeForm(const std::string &form, const std::string &target);
};

#endif