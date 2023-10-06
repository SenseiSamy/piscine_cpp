/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:52 by snaji             #+#    #+#             */
/*   Updated: 2023/10/06 19:59:56 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

class	Bureaucrat:
{
	private:
		const std::string	_name;
		unsigned int		grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &copy);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;
		void			upgrade(void);
		void			downgrade(void);

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
}

#endif