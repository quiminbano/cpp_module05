/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParameterMissing.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:32:13 by corellan          #+#    #+#             */
/*   Updated: 2023/06/18 18:20:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERMISSING_HPP
# define PARAMETERMISSING_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat::ParameterMissing : public std::exception
{
public:
	ParameterMissing(int flag);
	virtual const char	*what(void) const throw();
private:
	int			_flag;
};

#endif