/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:01:12 by snaji             #+#    #+#             */
/*   Updated: 2023/11/15 19:10:29 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	&min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	&max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif