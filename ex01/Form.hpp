/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:04:08 by corellan          #+#    #+#             */
/*   Updated: 2023/07/11 09:16:07 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class	Form
{
private:

	const std::string	_name;
	bool				_signed;
	const int			_grade;
	const int			_execute;
	int					_signedFlag;

	Form(Form const &rhs);

	Form	&operator=(Form const &rhs);

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

	Form(void);
	Form(std::string name, int grade, int execute);
	~Form(void);

	const std::string	getName(void) const;
	bool				getSigned(void) const;
	int					getGrade(void) const;
	int					getExecute(void) const;
	void				setSignedFlag(int flag);
	int					getSignedFlag(void) const;
	void				beSigned(Bureaucrat &person);
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif