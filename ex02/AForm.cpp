/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:54 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 00:01:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Generic_AForm"), _signed(false), _grade(75), _execute(100), _exFlag(0)
{
	std::cout << "Default constructor called from the AForm class" << std::endl;
	if ((this->_grade > 150) || (this->_execute > 150))
		throw GradeTooLowException();
	else if ((this->_grade < 1) || (this->_execute < 1))
		throw GradeTooHighException();
	return ;
}

AForm::AForm(std::string name, int grade, int execute) : _name(name), _grade(grade), _execute(execute), _exFlag(0)
{
	std::cout << "Constructor called from the AForm class, passing name " << this->_name;
	std::cout << ", grade " << this->_grade << ", and execute " << this->_execute;
	std::cout << " as parameters" << std::endl;
	this->_signed = false;
	if ((this->_grade > 150) || (this->_execute > 150))
		throw GradeTooLowException();
	else if ((this->_grade < 1) || (this->_execute < 1))
		throw GradeTooHighException();
	return ;
}

AForm::AForm(AForm const &rhs) : _name(rhs.getName()), _grade(rhs.getGrade()), _execute(rhs.getExecute()), _exFlag(rhs.getExFlag())
{
	std::cout << "Copy constructor called from the AForm class" << std::endl;
	*this = rhs;
	return ;
}
AForm::~AForm(void)
{
	std::cout << "Default destructor called from the AForm class" << std::endl;
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	this->_signed = rhs.getSigned();
	return (*this);
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGrade(void) const
{
	return (this->_grade);
}

int	AForm::getExecute(void) const
{
	return (this->_execute);
}

int	AForm::getExFlag(void) const
{
	return (this->_exFlag);
}

void	AForm::beSigned(Bureaucrat &person)
{
	this->_exFlag = 0;
	if (person.getGrade() > this->_execute)
	{
		this->_exFlag = 1;
		this->_signed = false;
		throw (GradeTooLowException());
	}
	if ((person.getGrade() <= this->_grade))
		this->_signed = true;
	else
		this->_signed = false;
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	std::string	temp;

	if (rhs.getSigned() == true)
		temp = "signed";
	else
		temp = "not signed";
	o << rhs.getName() << ", sign status: " << temp << ", minimun to be signed: " << rhs.getGrade() << ", minimun to be executed: " << rhs.getExecute();
	return (o);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("The grade of the AForm or the bureaucrat is too high to execute the AForm.");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the AForm or the bureaucrat is too low to execute the AForm.");
}