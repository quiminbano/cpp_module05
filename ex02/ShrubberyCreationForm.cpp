/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:52:23 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 18:12:33 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default constructor for the ShrubberyCreationForm class called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Default destructor for the ShrubberyCreationForm class called" << std::endl;
	return ;
}

void	ShrubberyCreationForm::beSigned(Bureaucrat &person)
{
	if (person.getGrade() < 0)
	{
		this->setSigned(false);
		throw (GradeTooHighException());
	}
	if (person.getGrade() > 150)
	{
		this->setSigned(false);
		throw (GradeTooLowException());
	}
	if ((person.getGrade() <= this->getGrade()))
	{
		this->setSigned(true);
		output.open(person.getName() + "_shrubbery");
		output << "     A     " << std::endl << "    / \\    " << std::endl << "   B   C   " << std::endl << "  / \\ / \\  " << std::endl << " C  D E  F " << std::endl;
		output.close();
	}
	else
		this->setSigned(false);
}