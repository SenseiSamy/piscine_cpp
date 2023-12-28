/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:00:03 by snaji             #+#    #+#             */
/*   Updated: 2023/12/28 02:05:24 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template <typename T>
class	MutantStack: public std::stack<T>
{
	public:
		class	iterator
		{
			private:
				T*	ptr;

			public:
				iterator(void): ptr(0) {}
				iterator(T *ptr): ptr(ptr) {}
				iterator(const iterator &copy): ptr(copy.ptr) {}
				~iterator(void) {}

				iterator	&operator++(void)
				{
					++ptr;
					return (*this);
				}

				iterator	operator++(int)
				{
					iterator	tmp = *this;

					++ptr;
					return (tmp);
				}

				iterator	&operator--(void)
				{
					--ptr;
					return (*this);
				}

				iterator	operator--(int)
				{
					iterator	tmp = *this;

					--ptr;
					return (tmp);
				}

				T	&operator*(void) const
				{
					return (*ptr);
				}

				bool	operator==(const iterator &other)
				{
					return (this->ptr == other.ptr);
				}

				bool	operator!=(const iterator &other)
				{
					return (this->ptr != other.ptr);
				}

				iterator	&operator+(int n)
				{
					while (n--)
						++ptr;
					return (*this);
				}

				iterator	&operator-(int n)
				{
					while (n--)
						--ptr;
					return (*this);
				}
		};
	
		MutantStack(void) {}
		MutantStack(const MutantStack &copy)
		{
			*this = copy;
		}
		~MutantStack(void) {}
		MutantStack	&operator=(const MutantStack &copy)
		{
			this->c = copy.c;
		}

		iterator	begin(void)
		{
			return (iterator(&this->c[0]));
		}

		iterator	end(void)
		{
			return (iterator(&this->c[this->size()]));
		}
};

#endif