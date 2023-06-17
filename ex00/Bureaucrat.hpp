/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:28:18 by corellan          #+#    #+#             */
/*   Updated: 2023/06/17 17:57:19 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BEREAUCRAT_HPP
# include <stdexcept>
# include <string>
# include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
	int			_flag;
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &rhs);
	Bureaucrat(int grade);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	std::string	getName(void) const;
	int			getGrade(void) const;
	int			getFlag(void) const;
	void		incrementGrade(int idx);
	void		decrementGrade(int idx);
	void		GradeTooHighException(void) const;
	void		GradeTooLowException(void) const;
	void		parameterMissing(void);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif