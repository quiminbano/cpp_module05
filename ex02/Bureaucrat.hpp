/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:28:18 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 15:03:37 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <stdexcept>
# include <string>
# include <iostream>

class	AForm;

class	Bureaucrat
{
private:

	std::string const	_name;
	int					_grade;

	Bureaucrat(Bureaucrat const &rhs);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

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

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);

	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(int idx);
	void				decrementGrade(int idx);
	void				signForm(AForm &form);
	void				executeForm(AForm &form);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif