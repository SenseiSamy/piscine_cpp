/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:52 by snaji             #+#    #+#             */
/*   Updated: 2023/10/09 20:06:18 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class	Form;
class	Bureaucrat;

# include "Form.hpp"

class	Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const unsigned int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &copy);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void			upgrade(void);
		void			downgrade(void);
		void			signForm(Form &f);

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);

#endif