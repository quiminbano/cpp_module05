/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:51:52 by corellan          #+#    #+#             */
/*   Updated: 2023/07/11 19:11:51 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	emilia("Emilia", 150);
	Bureaucrat	matias("Matias", 1);
	Bureaucrat	rosa("Rosa", 50);
	AForm		*tree;
	AForm		*roboto;
	AForm		*president;

	tree = new ShrubberyCreationForm("hive");
	roboto = new RobotomyRequestForm("bocal");
	president = new PresidentialPardonForm("Madonna");

	std::cout << std::endl;
	tree->beSigned(emilia);
	emilia.signForm(*tree);
	try
	{
		tree->execute(emilia);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	emilia.executeForm(*tree);
	
	std::cout << std::endl;
	tree->beSigned(matias);
	matias.signForm(*tree);
	tree->execute(matias);
	matias.executeForm(*tree);

	std::cout << std::endl;
	tree->beSigned(emilia);
	emilia.signForm(*tree);
	try
	{
		tree->execute(emilia);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	emilia.executeForm(*tree);

	std::cout << std::endl;
	roboto->beSigned(rosa);
	rosa.signForm(*roboto);
	try
	{
		roboto->execute(rosa);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	rosa.executeForm(*roboto);

	std::cout << std::endl;
	roboto->beSigned(matias);
	matias.signForm(*roboto);
	roboto->execute(matias);
	matias.executeForm(*roboto);

	std::cout << std::endl;
	matias.decrementGrade(10);
	president->beSigned(matias);
	matias.signForm(*president);
	try
	{
		president->execute(matias);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	matias.executeForm(*president);
	matias.incrementGrade(10);
	president->execute(matias);
	matias.executeForm(*president);
	
	std::cout << std::endl;
	delete tree;
	delete roboto;
	delete president;
	return (0);
}
