/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:19:05 by corellan          #+#    #+#             */
/*   Updated: 2023/06/17 17:59:43 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void) : _grade(150), _name("John Doe"), _flag(0)
{
	std::cout << "Default constructor of Bereaucrat class called" << std::endl;
	this->parameterMissing();
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
{
	std::cout << "Copy constructor of Bureaucrat class called" << std::endl;
	*this = rhs;
	return ;
}

Bureaucrat::Bureaucrat(int grade) : _name("John Doe"), _flag(0)
{
	std::cout << "Constructor for Bureaucrat class called with the grade " << grade << std::endl;
	if ((grade > 150) && (grade < 1))
	{
		if (grade > 150)
		{
			this->_grade = 150;
			this->_flag = 1;
			this->parameterMissing();
		}
		else
		{
			this->_grade = 1;
			this->_flag = 2;
			this->parameterMissing();
		}
	}
	this->parameterMissing();
}

Bureaucrat::Bureaucrat(std::string name) : _grade(150), _flag(0)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Constructor for Bureaucrat class called with the name " << name << " and the grade " << grade << std::endl;
	if ((grade > 150) && (grade < 1))
	{
		if (grade > 150)
		{
			this->_grade = 150;
			this->GradeTooLowException();
		}
		else
		{
			this->_grade = 1;
			this->GradeTooHighException();
		}
		return ;
	}
	this->_name = name;
	this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default destructor for Bureaucrat class called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Copy constructor for Bureaucrat class called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
		this->_flag = rhs.getFlag();
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

int	Bureaucrat::getFlag(void) const
{
	return (this->_flag);
}

void		Bureaucrat::incrementGrade(int idx)
{
	if ((this->_grade - idx) <= 0)
	{
		this->_grade = 1;
		return (this->GradeTooHighException());
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
		return (this->GradeTooLowException());
	}
	else
		(this->_grade)++;
	return ;
}

void		Bureaucrat::GradeTooHighException(void) const
{

	throw "The grade achieved is too high for the Bureaucrat. Setting the maximun";
}

void		Bureaucrat::GradeTooLowException(void) const
{
	throw "The grade achieved is too low for the Bureaucrat. Setting the minimun";
}

void		Bureaucrat::parameterMissing(void)
{
	if (this->_flag == 1)
	{
		this->_flag = 0;
		throw "One or more parameters are missing. Default values were setted. Also, the grade setted was too low. Minimun grade setted.";
	}
	else if (this->_flag == 2)
	{
		this->_flag = 0;
		throw "One or more parameters are missing. Default values were setted. Also, the grade setted was too high. Maximun grade setted.";
	}
	else
		throw "One or more parameters are missing. Default values were setted. Also, the grade setted was too high. Maximun grade setted.";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}