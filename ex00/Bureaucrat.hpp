/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:28:18 by corellan          #+#    #+#             */
/*   Updated: 2023/06/19 12:22:27 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <stdexcept>
# include <string>
# include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
public:
	class GradeTooHighException;
	class GradeTooLowException;
	class ParameterMissing;

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &rhs);
	Bureaucrat(int grade);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(int idx);
	void		decrementGrade(int idx);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif