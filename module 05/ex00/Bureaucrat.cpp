/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:55:52 by snaji             #+#    #+#             */
/*   Updated: 2023/10/07 19:19:21 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void): _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade):
	_name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::upgrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::downgrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The bureaucrat grade is too low");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}