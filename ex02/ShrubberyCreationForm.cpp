/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:52:23 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 21:15:55 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("unknown_name"), AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default constructor for the ShrubberyCreationForm class called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Constructor for the ShrubberyCreationForm class called using " << target << " as a target" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Default destructor for the ShrubberyCreationForm class called" << std::endl;
	return ;
}



void	ShrubberyCreationForm::execute(Bureaucrat &excecutor)
{
	std::ofstream	output;

	if (excecutor.getGrade() > this->getExecute())
		throw (GradeTooLowException());
	if (this->getSigned() == true)
	{
		output.open(this->_target + "_shrubbery");
		output << "     A     " << std::endl << "    / \\    " << std::endl << "   B   C   " << std::endl << "  / \\ / \\  " << std::endl << " C  D E  F " << std::endl;
		output.close();
	}
	return ;
}