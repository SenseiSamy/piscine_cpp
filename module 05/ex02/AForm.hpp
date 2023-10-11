/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:00:56 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 17:54:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>

class	AForm;
class	Bureaucrat;

# include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:
		AForm(void);
		AForm(const std::string &name, const unsigned int signGrade,
			const unsigned int execGrade);
		AForm(const AForm &copy);
		virtual ~AForm(void) = 0;

		AForm	&operator=(const AForm &copy);

		std::string		getName(void) const;
		bool			isSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		void			beSigned(Bureaucrat &b);
		virtual void	execute(const Bureaucrat &executor) const = 0;
		
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
		class	FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const AForm &f);

#endif