/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:52:23 by corellan          #+#    #+#             */
/*   Updated: 2023/06/23 17:34:45 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("unknown_name")
{
	std::cout << "Default constructor for the ShrubberyCreationForm class called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Constructor for the ShrubberyCreationForm class called using " << target << " as a target" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm("ShrubberyCreationForm", 145, 137), _target(rhs.getTarget())
{
	std::cout << "Copy constructor for the ShrubberyCreationForm class called" << std::endl;
	*this = rhs;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "Copy assigment operator for the ShrubberyCreationForm class called" << std::endl;
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Default destructor for the ShrubberyCreationForm class called" << std::endl;
	return ;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat &executor)
{
	std::ofstream	output;

	if (executor.getGrade() > this->getExecute())
		throw (GradeTooLowException());
	if (this->getSigned() == true)
	{
		output.open(this->_target + "_shrubbery");
		std::cout << "executing the form. Now the file " << this->_target << "_shrubbery is created" << std::endl; 
		output << "     A     " << std::endl << "    / \\    " << std::endl << "   B   C   " << std::endl << "  / \\ / \\  " << std::endl << " C  D E  F " << std::endl;
		output.close();
	}
	else
		std::cout << "The execution of " << this->getName() << " failed, because " << executor.getName() << " it isn't grade enough to do it" << std::endl;
	return ;
}