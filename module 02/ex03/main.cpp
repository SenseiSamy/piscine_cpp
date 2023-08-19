/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:17:04 by snaji             #+#    #+#             */
/*   Updated: 2023/08/19 17:40:52 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(const Point a, const Point b, const Point c, const Point p);

int main(void)
{
	Point	A(5.3f, 8.36f);
	Point	B(10.2f, 4.5f);
	Point	C(3.5f, 3.0f);

	Point	P1(6.0f, 5.5f); //Point in triangle
	Point	P2(3.5f, 6.5f); //Point not in triangle

	std::cout << bsp(A, B, C, P1) << std::endl;
	std::cout << bsp(A, B, C, P2) << std::endl;

	return (0);
}
