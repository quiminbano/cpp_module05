/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:45:54 by corellan          #+#    #+#             */
/*   Updated: 2023/06/19 19:13:58 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Generic_form"), _signed(false), _grade(75), _execute(100)
{
	std::cout << "Default constructor called from the Form class" << std::endl;
	return ;
}

Form::Form(std::string name, int grade, int execute) : _name(name), _grade(grade), _execute(execute)
{
	std::cout << "Constructor called from the Form class, passing name " << this->_name;
	std::cout << ", grade " << this->_grade << ", and execute " << this->_execute;
	std::cout << " as parameters" << std::endl;
	this->_signed = false;
	return ;
}

Form::Form(Form const &rhs) : _name(rhs.getName()), _grade(rhs.getGrade()), _execute(rhs.getExecute())
{
	std::cout << "Copy constructor called from the Form class" << std::endl;
	*this = rhs;
	return ;
}
Form::~Form(void)
{
	std::cout << "Default destructor called from the Form class" << std::endl;
	return ;
}

Form	&Form::operator=(Form const &rhs)
{
	this->_signed = rhs.getSigned();
	return (*this);
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

const int	Form::getGrade(void) const
{
	return (this->_grade);
}

const int	Form::getExecute(void) const
{
	return (this->_execute);
}

void	Form::beSigned(Bureaucrat &person)
{
	
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
	return ("The grade of the form is too high to be signed or executed.");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("The grade of the form is too low to be signed or executed.");
}