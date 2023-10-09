/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:00:56 by snaji             #+#    #+#             */
/*   Updated: 2023/10/09 20:07:31 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class	Form;
class	Bureaucrat;

# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:
		Form(void);
		Form(const std::string &name, const unsigned int signGrade,
			const unsigned int execGrade);
		Form(const Form &copy);
		~Form(void);

		Form			&operator=(const Form &copy);

		std::string		getName(void) const;
		bool			isSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		void			beSigned(Bureaucrat &b);
		
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

std::ostream	&operator<<(std::ostream &os, const Form &f);

#endif