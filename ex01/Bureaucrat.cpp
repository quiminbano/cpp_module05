/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:19:05 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 14:59:07 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("John_Doe"),  _grade(150)
{
	std::cout << "Default constructor of Bereaucrat class called" << std::endl;
	return ;
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
		this->_grade -= idx;
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
		this->_grade += idx;
	return ;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSigned() == true && form.getSignedFlag() == 0)
	{
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		form.setSignedFlag(1);
	}
	else if (form.getSigned() == true && form.getSignedFlag() == 1)
		std::cout << this->_name << " couldn't sign " << form.getName() << " because the form was already signed by another Bureaucrat" << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName() << " because the Bureaucrat is not grade enough to do it" << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade achieved is too high for the Bureaucrat. Setting the maximun");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade achieved is too low for the Bureaucrat. Setting the minimun");
}
