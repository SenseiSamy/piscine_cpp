/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:14:30 by snaji             #+#    #+#             */
/*   Updated: 2023/10/11 18:52:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Ansi.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm("RobotomyRequestForm", 72, 45), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &
	copy)
{
	this->_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!this->isSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::cout << ansi::italic << "*Drilling noises* " << ansi::reset;
		std::srand(std::time(NULL));
		if (std::rand() % 2 == 0)
			std::cout << ansi::green << this->_target << " has been successfully "
				"robotomized" << ansi::reset << std::endl;
		else
			std::cout << ansi::red << "The robotomy failed" << ansi::reset
				<< std::endl;
	}
}
