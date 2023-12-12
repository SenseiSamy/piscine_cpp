/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:00:59 by snaji             #+#    #+#             */
/*   Updated: 2023/12/12 19:09:48 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <limits>

Span::Span(void): _size(0) {}

Span::Span(const unsigned int n): _size(n), _data(std::vector<int>()) {}

Span::Span(const Span &copy): _size(copy._size), _data(copy._size) {}

Span::~Span(void) {}

Span	&Span::operator=(const Span &copy)
{
	this->_size = copy._size;
	this->_data = copy._data;
	return (*this);
}

unsigned int	Span::getSize(void) const
{
	return (_data.size());
}

unsigned int	Span::getSizeMax(void) const
{
	return (_size);
}

int	Span::getElement(unsigned int i) const
{
	return (_data[i]);
}

// void	Span::addNumber(const int n)
// {
// 	unsigned int	i;

// 	if (_data.size() >= _size)
// 		throw std::out_of_range("the span is full");
// 	i = 0;
// 	while (i < _data.size() && _data[i] < n)
// 		++i;
	
// 	_data.insert(_data.begin() + i, n);
// 	++_size;
// }

unsigned int	Span::addNumberRec(const int n, const int min, const int max)
	const
{
	unsigned int	i;

	if (n < _data[min])
		return (min);
	if (n > _data[max - 1])
		return (max);
	i = min + (max - min) / 2;
	if (_data[i - 1] <= n && _data[i] >= n)
		return (i);
	if (n > _data[i])
		return (addNumberRec(n, i, max));
	return (addNumberRec(n, min, i));
}

void	Span::addNumber(const int n)
{
	unsigned int	i;

	if (_data.size() >= _size)
		throw std::out_of_range("the span is full");
	if (_data.size() == 0)
		_data.push_back(n);
	else
	{
		i = addNumberRec(n, 0, _data.size());
		_data.insert(_data.begin() + i, n);
	}
}

unsigned int	Span::shortestSpan(void) const
{
	unsigned int	shortest;
	unsigned int	i;

	if (_data.size() <= 1)
		throw std::range_error("need at least 2 numbers in span");

	shortest = std::numeric_limits<unsigned int>::max();
	for (i = 1; i < _data.size(); ++i)
		if ((unsigned int)(_data[i] - _data[i - 1]) < shortest)
			shortest = _data[i] - _data[i - 1];
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (_data.size() <= 1)
		throw std::range_error("need at least 2 numbers in span");

	return (_data[_data.size() - 1] - _data[0]);
}

void	Span::insert(std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}
