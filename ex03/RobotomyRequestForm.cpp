/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:14:48 by corellan          #+#    #+#             */
/*   Updated: 2023/07/11 19:07:30 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default constructor for the RobotomyRequestForm class called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Constructor for the RobotomyRequestForm class called using " << target << " as a target" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm("RobotomyRequestForm", 72, 45), _target(rhs.getTarget())
{
	std::cout << "Copy constructor for the RobotomyRequestForm class called" << std::endl;
	*this = rhs;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "Copy assigment operator for the RobotomyRequestForm class called" << std::endl;
	if (this != &rhs)
		this->_target = rhs.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Default destructor for the RobotomyRequestForm class called" << std::endl;
	return ;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat &executor)
{
	int	number;

	std::srand(std::time(NULL));
	number = ((rand() % 2) + 1);
	if (this->getExecutedF() == true)
	{
		std::cout << "This form was already executed by a Bureaucrat before. Yay!! So, " << executor.getName() << " doesn't do anything" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getExecute())
		throw (GradeTooLowException());
	if (this->getSigned() == true)
	{
		std::cout << "bzzzz bzzzz, ";
		if (number == 2)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << this->_target << " failed his process of robotimization" << std::endl;
		this->setExecutedF(true);
	}
	else
		std::cout << "The execution of " << this->getName() << " failed, because " << executor.getName() << " it isn't grade enough to do it" << std::endl;
	return ;
}
