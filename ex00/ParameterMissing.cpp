/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParameterMissing.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:52:24 by corellan          #+#    #+#             */
/*   Updated: 2023/06/18 19:04:28 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParameterMissing.hpp"

Bureaucrat::ParameterMissing::ParameterMissing(int flag) : _flag(flag)
{
	return ;
}

const char	*Bureaucrat::ParameterMissing::what(void) const throw()
{
	if (this->_flag == 1)
		return ("One or more parameters are missing. Default name setted. Also, the grade setted was too low. Minimun grade setted.");
	else if (this->_flag == 2)
		return ("One or more parameters are missing. Default name setted. Also, the grade setted was too high. Maximun grade setted.");
	else
		return ("One or more parameters are missing. Default values were setted");
}
