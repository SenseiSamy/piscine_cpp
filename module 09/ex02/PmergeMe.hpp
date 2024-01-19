/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:23:07 by snaji             #+#    #+#             */
/*   Updated: 2024/01/19 21:11:18 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <algorithm>

template <typename Iterator>
class	pair_iterator
{
	private:
		Iterator	_it;

	public:
		typedef typename std::iterator_traits<Iterator>::value_type	value_type;
		typedef typename std::iterator_traits<Iterator>::difference_type
			difference_type;
		typedef typename std::iterator_traits<Iterator>::pointer	pointer;
		typedef typename std::iterator_traits<Iterator>::reference	reference;

		pair_iterator(void) {}
		pair_iterator(Iterator it): _it(it) {}
		pair_iterator(const pair_iterator &copy): _it(copy._it) {}
		~pair_iterator(void) {}

		pair_iterator&	operator=(const pair_iterator &copy)
		{
			this->_it = copy._it;
			return (*this);
		}

		Iterator	base(void) const
		{
			return (_it);
		}

		reference	operator*(void) const
		{
			return (_it[1]);
		}

		pointer	operator->(void) const
		{
			return (&(operator*()));
		}

		pair_iterator&	operator++(void)
		{
			_it += 2;
			return (*this);
		}

		pair_iterator	operator++(int)
		{
			pair_iterator	tmp = *this;
			operator++();
			return (tmp);
		}

		pair_iterator&	operator--(void)
		{
			_it -= 2;
			return (*this);
		}

		pair_iterator	operator--(int)
		{
			pair_iterator	tmp = *this;
			operator--();
			return (tmp);
		}

		pair_iterator&	operator+=(int n)
		{
			_it += 2 * n;
			return (*this);
		}
		
		pair_iterator&	operator-=(int n)
		{
			_it -= 2 * n;
			return (*this);
		}

		reference	operator[](int pos)
		{
			return (_it[pos * 2 + 1]);
		}
};

template <typename Iterator>
bool	operator==(const pair_iterator<Iterator> &lhs,
	const pair_iterator<Iterator> &rhs)
{
	return (lhs.base() == rhs.base());
}

template <typename Iterator>
bool	operator!=(const pair_iterator<Iterator> &lhs,
	const pair_iterator<Iterator> &rhs)
{
	return (lhs.base() != rhs.base());
}

template <typename Iterator>
pair_iterator<Iterator>	operator+(pair_iterator<Iterator> it, int n)
{
	it += n;
	return (it);
}

template <typename Iterator>
pair_iterator<Iterator>	operator+(int n, pair_iterator<Iterator> it)
{
	it += n;
	return (it);
}

template <typename Iterator>
pair_iterator<Iterator>	make_pair_it(Iterator it)
{
	return (pair_iterator<Iterator>(it));
}

template <typename Iterator>
void	swap_pairs(pair_iterator<Iterator> a, pair_iterator<Iterator> b)
{
	typename std::iterator_traits<Iterator>::value_type	tmp;

	tmp = *a.base();
	*a.base() = *b.base();
	*b.base() = tmp;

	tmp = *(a.base() + 1);
	*(a.base() + 1) = *(b.base() + 1);
	*(b.base() + 1) = tmp;
}



















template <typename Iterator>
void	MergeInsertSort(Iterator first, Iterator last)
{
	std::size_t	size = std::distance(first, last);
	if (size < 2)
		return;
	
	bool		is_odd = (size % 2 != 0);
	Iterator	end = is_odd ? last - 1 : last;
	
	for (Iterator it = first; it != end; it += 2)
	{
		if (it[0] > it[1])
			std::swap(it[0], it[1]);
	}
}

#endif