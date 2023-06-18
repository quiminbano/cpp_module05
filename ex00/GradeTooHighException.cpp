/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:41 by corellan          #+#    #+#             */
/*   Updated: 2023/06/18 17:47:01 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade achieved is too high for the Bureaucrat. Setting the maximun");
}
