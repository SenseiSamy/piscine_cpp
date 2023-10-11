/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:31:04 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 17:55:02 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Ansi.hpp"

AForm::AForm(void): _name(""), _signed(false), _signGrade(150), _execGrade(150)
{}

AForm::AForm(const std::string &name, const unsigned int signGrade, const
	unsigned int execGrade): _name(name), _signed(false), _signGrade(signGrade),
	_execGrade(execGrade)
{
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooHighException();
	else if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy): _name(""), _signGrade(150), _execGrade(150)
{
	*this = copy;
}

AForm::~AForm(void) {}

AForm	&AForm::operator=(const AForm &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string		AForm::getName(void) const
{
	return (this->_name);
}

bool			AForm::isSigned(void) const
{
	return (this->_signed);
}

unsigned int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

unsigned int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void			AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("the form grade is too low");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("the form grade is too high");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("the form is not signed");
}

std::ostream	&operator<<(std::ostream &os, const AForm &f)
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