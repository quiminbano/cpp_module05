/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:54 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 15:19:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Generic_form"), _signed(false), _grade(75), _execute(100), _signedFlag(0)
{
	std::cout << "Default constructor called from the Form class" << std::endl;
	if ((this->_grade > 150) || (this->_execute > 150))
		throw GradeTooLowException();
	else if ((this->_grade < 1) || (this->_execute < 1))
		throw GradeTooHighException();
	return ;
}

Form::Form(std::string name, int grade, int execute) : _name(name), _grade(grade), _execute(execute), _signedFlag(0)
{
	std::cout << "Constructor called from the Form class, passing name " << this->_name;
	std::cout << ", grade " << this->_grade << ", and execute " << this->_execute;
	std::cout << " as parameters" << std::endl;
	this->_signed = false;
	if ((this->_grade > 150) || (this->_execute > 150))
		throw GradeTooLowException();
	else if ((this->_grade < 1) || (this->_execute < 1))
		throw GradeTooHighException();
	return ;
}

Form::~Form(void)
{
	std::cout << "Default destructor called from the Form class" << std::endl;
	return ;
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getGrade(void) const
{
	return (this->_grade);
}

int	Form::getExecute(void) const
{
	return (this->_execute);
}

void	Form::setSignedFlag(int flag)
{
	this->_signedFlag = flag;
	return ;
}

int	Form::getSignedFlag(void) const
{
	return (this->_signedFlag);
}

void	Form::beSigned(Bureaucrat &person)
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
	if ((person.getGrade() <= this->_grade))
		this->_signed = true;
	else
		this->_signed = false;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	std::string	temp;

	if (rhs.getSigned() == true)
		temp = "signed";
	else
		temp = "not signed";
	o << rhs.getName() << ", sign status: " << temp << ", minimun to be signed: " << rhs.getGrade() << ", minimun to be executed: " << rhs.getExecute();
	return (o);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("The grade of the form or the bureaucrat is too high to sign it or execute it.");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the form or the bureaucrat is too low to sign it or execute it.");
}