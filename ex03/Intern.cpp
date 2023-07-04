/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:03:06 by corellan          #+#    #+#             */
/*   Updated: 2023/06/26 11:19:32 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Default constructor for Intern class called" << std::endl;
	return ;
}

Intern::Intern(Intern const &rhs)
{
	std::cout << "Copy constructor for Intern class called" << std::endl;
	*this = rhs;
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	std::cout << "Copy assigment operator for Intern class called" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Default destructor for Intern class called" << std::endl;
	return ;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	AForm	*ptr;

	(!form.compare("ShrubberyCreationForm")) ? (ptr = new ShrubberyCreationForm(target)) : ((!form.compare("RobotomyRequestForm")) ? (ptr = new RobotomyRequestForm(target)) : ((!form.compare("PresidentialPardonForm")) ? (ptr = new PresidentialPardonForm(target)) : (ptr = NULL)));
	(!ptr) ? (std::cout << "The form that the Intern is trying to create doesn't exist") : (std::cout << "Intern creates " << form);
	std::cout << std::endl;
	return (ptr);
}
