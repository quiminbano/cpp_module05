/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:48:37 by corellan          #+#    #+#             */
/*   Updated: 2023/06/18 18:28:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade achieved is too low for the Bureaucrat. Setting the minimun");
}
