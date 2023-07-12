/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:19:05 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 14:56:30 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "ParameterMissing.hpp"

Bureaucrat::Bureaucrat(void) : _name("John_Doe"),  _grade(150)
{
	std::cout << "Default constructor of Bereaucrat class called" << std::endl;
	throw (ParameterMissing(0));
}

Bureaucrat::Bureaucrat(int grade) : _name("John_Doe")
{
	std::cout << "Constructor for Bureaucrat class called with the grade " << grade << std::endl;
	if ((grade > 150) || (grade < 1))
	{
		if (grade > 150)
		{
			this->_grade = 150;
			throw (ParameterMissing(1));
		}
		else
		{
			this->_grade = 1;
			throw (ParameterMissing(2));
		}
	}
	else
		throw (ParameterMissing(0));
	return ;
}

Bureaucrat::Bureaucrat(std::string name) : _grade(150)
{
	std::cout << "Constructor for Bureaucrat class called with the name " << name << std::endl;
	throw (ParameterMissing(0));
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Constructor for Bureaucrat class called with the name " << name << " and the grade " << grade << std::endl;
	if ((grade > 150) || (grade < 1))
	{
		if (grade > 150)
		{
			this->_grade = 150;
			throw (GradeTooLowException());
		}
		else
		{
			this->_grade = 1;
			throw (GradeTooHighException());
		}
	}
	this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default destructor for Bureaucrat class called" << std::endl;
	return ;
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade(int idx)
{
	if ((this->_grade - idx) <= 0)
	{
		this->_grade = 1;
		throw (GradeTooHighException());
	}
	else
		(this->_grade)--;
	return ;
}

void		Bureaucrat::decrementGrade(int idx)
{
	if ((this->_grade + idx) > 150)
	{
		this->_grade = 150;
		throw (GradeTooLowException());
	}
	else
		(this->_grade)++;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}