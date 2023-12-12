/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:52:12 by snaji             #+#    #+#             */
/*   Updated: 2023/12/12 19:03:20 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class	Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_data;

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
		unsigned int	addNumberRec(const int n, const int min, const int max)
			const;
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			insert(std::vector<int>::iterator begin,
			std::vector<int>::iterator end);		
};

#endif