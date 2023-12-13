/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:00:59 by snaji             #+#    #+#             */
/*   Updated: 2023/12/13 19:21:58 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <limits>

Span::Span(void): _size(0) {}

Span::Span(const unsigned int n): _size(n), _data(std::list<int>()) {}

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
	std::list<int>::const_iterator	it = _data.begin();

	std::advance(it, i);
	return (*it);
}

// unsigned int	Span::addNumberRec(const int n, const int min, const int max)
// 	const
// {
// 	unsigned int	i;

// 	if (n < _data[min])
// 		return (min);
// 	if (n > _data[max - 1])
// 		return (max);
// 	i = min + (max - min) / 2;
// 	if (_data[i - 1] <= n && _data[i] >= n)
// 		return (i);
// 	if (n > _data[i])
// 		return (addNumberRec(n, i, max));
// 	return (addNumberRec(n, min, i));
// }

list_it	Span::addNumberRec(const int n, list_it min, list_it max)
	const
{
	list_it	it = min;
	list_it	it2;
	int		dist;

	if (n < *min)
		return (min);
	if (n > *max)
		return (++max);
	dist = std::distance(min, max);
	std::advance(it, dist / 2 - 1);
	it2 = it;
	std::advance(it2, 1);
	if (*it <= n && *it2 >= n)
		return (it);
	if (n > *it)
		return (addNumberRec(n, it, max));
	return (addNumberRec(n, min, it));
}

void	Span::addNumber(const int n)
{
	list_it	it;

	if (_data.size() >= _size)
		throw std::out_of_range("the span is full");
	if (_data.size() == 0)
		_data.push_back(n);
	else
	{
		it = addNumberRec(n, _data.begin(), --_data.end());
		_data.insert(it, n);
	}
}

// unsigned int	Span::shortestSpan(void) const
// {
// 	unsigned int	shortest;
// 	unsigned int	i;

// 	if (_data.size() <= 1)
// 		throw std::range_error("need at least 2 numbers in span");

// 	shortest = std::numeric_limits<unsigned int>::max();
// 	for (i = 1; i < _data.size(); ++i)
// 		if ((unsigned int)(_data[i] - _data[i - 1]) < shortest)
// 			shortest = _data[i] - _data[i - 1];
// 	return (shortest);
// }

// unsigned int	Span::longestSpan(void) const
// {
// 	if (_data.size() <= 1)
// 		throw std::range_error("need at least 2 numbers in span");

// 	return (_data[_data.size() - 1] - _data[0]);
// }

void	Span::insert(std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}
