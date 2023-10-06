/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:52 by snaji             #+#    #+#             */
/*   Updated: 2023/10/06 19:29:17 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

class	Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(unsigned int grade);
		Bureaucrat(void)
};



#endif