/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:54 by corellan          #+#    #+#             */
/*   Updated: 2023/07/11 19:07:14 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Generic_AForm"), _signed(false), _grade(75), _execute(100), _executed_f(false), _signedFlag(0), _executedFlag(0)
{
	std::cout << "Default constructor called from the AForm class" << std::endl;
	if ((this->_grade > 150) || (this->_execute > 150))
		throw GradeTooLowException();
	else if ((this->_grade < 1) || (this->_execute < 1))
		throw GradeTooHighException();
	return ;
}

AForm::AForm(std::string name, int grade, int execute) : _name(name), _grade(grade), _execute(execute)
{
	std::cout << "Constructor called from the AForm class, passing name " << this->_name;
	std::cout << ", grade " << this->_grade << ", and execute " << this->_execute;
	std::cout << " as parameters" << std::endl;
	this->_signed = false;
	this->_executed_f = false;
	this->_signedFlag = 0;
	this->_executedFlag = 0;
	if ((this->_grade > 150) || (this->_execute > 150))
		throw GradeTooLowException();
	else if ((this->_grade < 1) || (this->_execute < 1))
		throw GradeTooHighException();
	return ;
}

AForm::AForm(AForm const &rhs) : _name(rhs.getName()), _grade(rhs.getGrade()), _execute(rhs.getExecute()), _executed_f(rhs.getExecutedF()), _signedFlag(rhs.getSignedFlag()), _executedFlag(rhs.getExecutedFlag())
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

void	AForm::setSigned(bool u)
{
	this->_signed = u;
	return ;
}

bool	AForm::getExecutedF(void) const
{
	return (this->_executed_f);
}

int		AForm::getSignedFlag(void) const
{
	return (this->_signedFlag);
}

int		AForm::getExecutedFlag(void) const
{
	return (this->_executedFlag);
}

void	AForm::setSignedFlag(int number)
{
	this->_signedFlag = number;
	return ;
}

void	AForm::setExecutedFlag(int number)
{
	this->_executedFlag = number;
	return ;
}

void	AForm::setExecutedF(bool condition)
{
	this->_executed_f = condition;
	return ;
}

void	AForm::beSigned(Bureaucrat &person)
{
	if (this->_signed == true)
	{
		std::cout << "This form was already signed by a Bureaucrat before. Yay!! So, " << person.getName() << " doesn't do anything" << std::endl;
		return ;
	}
	if (person.getGrade() < 0)
		throw (GradeTooHighException());
	if (person.getGrade() > 150)
		throw (GradeTooLowException());
	if ((person.getGrade() <= this->getGrade()))
		this->setSigned(true);
	else
		this->setSigned(false);
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
	return ("The grade of AForm or the bureaucrat is too high to sign it or execute it.");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("The grade of AForm or the bureaucrat is too low to sign it or execute it.");
}