/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ansi.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:21:53 by snaji             #+#    #+#             */
/*   Updated: 2023/10/10 19:20:22 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_HPP
# define ANSI_HPP
# include <iostream>

namespace ansi
{
	std::ostream	&reset(std::ostream &os);

	std::ostream	&bold(std::ostream &os);
	std::ostream	&dim(std::ostream &os);
	std::ostream	&italic(std::ostream &os);
	std::ostream	&underline(std::ostream &os);
	std::ostream	&blinking(std::ostream &os);
	std::ostream	&inverse(std::ostream &os);
	std::ostream	&hidden(std::ostream &os);
	std::ostream	&strike(std::ostream &os);

	std::ostream	&black(std::ostream &os);
	std::ostream	&red(std::ostream &os);
	std::ostream	&green(std::ostream &os);
	std::ostream	&yellow(std::ostream &os);
	std::ostream	&blue(std::ostream &os);
	std::ostream	&magenta(std::ostream &os);
	std::ostream	&cyan(std::ostream &os);
	std::ostream	&white(std::ostream &os);
	std::string		c256(unsigned int n);
	std::string		rgb(unsigned int r, unsigned int g,
		unsigned int b);
}

#endif