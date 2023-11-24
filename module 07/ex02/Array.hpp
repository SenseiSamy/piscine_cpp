/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:32:10 by snaji             #+#    #+#             */
/*   Updated: 2023/11/23 20:23:55 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <cstddef>
#include <stdexcept>

template <typename T>
class	Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void): _array(NULL), _size(0) {}

		Array(unsigned int n): _size(n)
		{
			_array = new T[_size];
		}
		
		Array(const Array &copy)
		{
			*this = copy;
		}

		~Array(void)
		{
			delete[] _array;
		}

		Array	&operator=(const Array &copy)
		{
			delete[] this->_array;
			this->_array = new T[copy._size];
			for (unsigned int i = 0; i < copy._size; ++i)
				this->_array[i] = copy._array[i];
			this->_size = copy._size;
			return (*this);
		}

		T		&operator[](unsigned int index)
		{
			if (index >= _size)
				throw (std::out_of_range("index out of range"));
			return (_array[index]);
		}
		
		unsigned int	size() const
		{
			return (_size);
		}
};

#endif