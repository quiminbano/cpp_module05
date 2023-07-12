/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:51:52 by corellan          #+#    #+#             */
/*   Updated: 2023/07/12 11:22:20 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	emilia("Emilia", 150);
	Bureaucrat	matias("Matias", 1);
	Bureaucrat	rosa("Rosa", 50);
	AForm		*tree;
	AForm		*roboto;
	AForm		*president;
	AForm		*carlos;
	Intern		hiver;

	std::cout << std::endl;
	tree = hiver.makeForm("ShrubberyCreationForm", "hive");
	roboto = hiver.makeForm("RobotomyRequestForm", "bocal");
	president = hiver.makeForm("PresidentialPardonForm", "madonna");

	std::cout << std::endl;
	carlos = hiver.makeForm("GenericForm", "myHouse");
	std::cout << "Carlos Pointer: " << carlos << std::endl;

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

	std::cout << std::endl;
	president->execute(matias);
	matias.executeForm(*president);

	std::cout << std::endl;
	delete tree;
	delete roboto;
	delete president;
	return (0);
}
