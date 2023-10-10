/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:31:04 by snaji             #+#    #+#             */
/*   Updated: 2023/10/10 19:25:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Ansi.hpp"

Form::Form(void): _name(""), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned
	int execGrade): _name(name), _signed(false), _signGrade(signGrade),
	_execGrade(execGrade)
{
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooHighException();
	else if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy): _name(""), _signGrade(150), _execGrade(150)
{
	*this = copy;
}

Form::~Form(void) {}

Form	&Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string		Form::getName(void) const
{
	return (this->_name);
}

bool			Form::isSigned(void) const
{
	return (this->_signed);
}

unsigned int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

unsigned int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void			Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("the form grade is too low");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("the form grade is too high");
}

std::ostream	&operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << ansi::bold << f.getName() << ansi::reset;
	if (f.isSigned())
		os << ": " << ansi::bold << ansi::green << "signed";
	else
		os << ": " << ansi::bold << ansi::red << "not signed";
	os << ansi::reset << ", grade " << f.getSignGrade() << " signature, grade "
		<< f.getExecGrade() << " execution.";
	return (os);
}