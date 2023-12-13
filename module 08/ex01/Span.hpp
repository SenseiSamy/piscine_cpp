/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:52:12 by snaji             #+#    #+#             */
/*   Updated: 2023/12/13 19:21:15 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <list>

typedef std::list<int>::iterator list_it;

class	Span
{
	private:
		unsigned int	_size;
		std::list<int>	_data;

	public:
		Span(void);
		Span(const unsigned int n);
		Span(const Span &copy);
		~Span(void);

		Span	&operator=(const Span &copy);

		unsigned int	getSize(void) const;
		unsigned int	getSizeMax(void) const;
		int				getElement(unsigned int i) const;

		void			addNumber(const int n);
		list_it			addNumberRec(const int n, list_it min, list_it max) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			insert(std::vector<int>::iterator begin,
			std::vector<int>::iterator end);		
};

#endif