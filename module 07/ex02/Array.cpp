/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:45:47 by snaji             #+#    #+#             */
/*   Updated: 2023/11/17 18:14:11 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstddef>

template <typename T>
Array<T>::Array(void): _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	*this = copy;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _array;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &copy)
{
	delete[] this->_array;
	this->array = new T[copy._size];
	for (unsigned int i; i < copy._size; ++i)
		this->_array[i] = copy._array[i];
	this->_size = copy._size;
}

template <typename T>
int	&Array<T>::operator[](int index)
{
	
}