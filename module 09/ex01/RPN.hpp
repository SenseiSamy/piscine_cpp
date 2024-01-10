/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:35:56 by snaji             #+#    #+#             */
/*   Updated: 2024/01/10 18:26:08 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <stack>

class	RPN
{
	private:
		std::string		_expression;
		std::stack<int>	_stack;

	public:
		RPN(void);
		RPN(const std::string &expression);
		RPN(const RPN &copy);
		~RPN(void);

		RPN	&operator=(const RPN &copy);

		void	newExp(const std::string &expresssion);
		int		solve(void);
};

#endif