/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:58:09 by snaji             #+#    #+#             */
/*   Updated: 2024/01/10 18:30:46 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

RPN::RPN(void): _expression(""), _stack(std::stack<int>()) {}

RPN::RPN(const std::string &expression):
	_expression(expression),
	_stack(std::stack<int>()) {}
	
RPN::RPN(const RPN &copy):
	_expression(copy._expression),
	_stack(copy._stack) {}

RPN::~RPN(void) {}

RPN	&RPN::operator=(const RPN &copy)
{
	this->_expression = copy._expression;
	this->_stack = copy._stack;
	return (*this);
}

void	RPN::newExp(const std::string &expression)
{
	_expression = expression;
}

static bool	fillStack(const std::string &exp, std::stack<int> &stack)
{
	std::string::const_iterator	it;

	if (exp.empty())
		return (false);
	it = exp.begin();
	while (it != exp.end())
	{
		if ()
	}
}	

int	RPN::solve(void)
{
	
}