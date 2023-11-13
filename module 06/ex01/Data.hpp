/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:40 by snaji             #+#    #+#             */
/*   Updated: 2023/11/13 17:37:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <string>

class	Data
{
	private:
		std::string	_s;	

	public:
		Data(void);
		Data(const std::string &s);
		Data(const Data &copy);
		~Data(void);

		Data	&operator=(const Data &copy);

		std::string	getString(void);
};

#endif