/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:21:13 by corellan          #+#    #+#             */
/*   Updated: 2023/06/23 17:35:46 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default constructor for the PresidentialPardonForm class called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Constructor for the PresidentialPardonForm class called using " << target << " as a target" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm("PresidentialPardonForm", 25, 5), _target(rhs.getTarget())
{
	std::cout << "Copy constructor for the PresidentialPardonForm class called" << std::endl;
	*this = rhs;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "Copy assigment operator for the PresidentialPardonForm class called" << std::endl;
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Default destructor for the PresidentialPardonForm class called" << std::endl;
	return ;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat &executor)
{
	if (executor.getGrade() > this->getExecute())
		throw (GradeTooLowException());
	if (this->getSigned() == true)
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		std::cout << "The execution of " << this->getName() << " failed, because " << executor.getName() << " it isn't grade enough to do it" << std::endl;
	return ;
}
