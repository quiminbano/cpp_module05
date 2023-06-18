/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:32:06 by corellan          #+#    #+#             */
/*   Updated: 2023/06/18 17:41:47 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat::GradeTooHighException : public std::exception
{
public:
	virtual const char	*what(void) const throw();
};

#endif