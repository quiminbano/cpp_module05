/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:04:08 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 00:03:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CPP
# define AFORM_CPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class	AForm
{
private:

	const std::string	_name;
	bool				_signed;
	const int			_grade;
	const int			_execute;
	int					_exFlag;

	AForm(Form const &rhs);

	AForm	&operator=(AForm const &rhs);

public:

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

	AForm(void);
	AForm(std::string name, int grade, int execute);
	~AForm(void);

	const std::string	getName(void) const;
	bool				getSigned(void) const;
	int					getGrade(void) const;
	int					getExecute(void) const;
	int					getExFlag(void) const;
	virtual void		beSigned(Bureaucrat &person) = 0;
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif