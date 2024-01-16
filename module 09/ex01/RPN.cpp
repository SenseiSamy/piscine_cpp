/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:58:09 by snaji             #+#    #+#             */
/*   Updated: 2024/01/16 18:35:44 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <iostream>

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

static bool	isExprValid(const std::string &exp)
{
	int	i = 0;

	while (exp[i])
	{
		if (i % 2 == 0)
		{
			if ((exp[i] < '0' || exp[i] > '9') && exp[i] != '+' &&
				exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
				return (false);
		}
		else
			if (exp[i] != ' ')
				return (false);
		++i;
	}
	return (true);
}	

int	RPN::solve(void)
{
	std::string::const_iterator	it;
	int	nb1, nb2;

	if (!isExprValid(_expression))
		throw std::invalid_argument("invalid expression");

	it = _expression.begin();
	while (it != _expression.end())
	{
		if (*it == ' ')
		{
			++it;
			continue;
		}
		if (*it == '-' || *it == '+' || *it == '*' || *it == '/')
		{
			if (_stack.size() < 2)
				throw std::invalid_argument("invalid expression");
			nb2 = _stack.top();
			_stack.pop();
			nb1 = _stack.top();
			_stack.pop();
			if (*it == '+')
				_stack.push(nb1 + nb2);
			else if (*it == '-')
				_stack.push(nb1 - nb2);
			else if (*it == '*')
				_stack.push(nb1 * nb2);
			else
				_stack.push(nb1 / nb2);
		}
		else
			_stack.push(*it - '0');
		++it;
	}
	
	return (_stack.top());
}