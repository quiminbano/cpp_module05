/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:42:17 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 12:18:08 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	emilia("Emilia", 150);
	Bureaucrat	matias("Matias", 1);
	Bureaucrat	rosa("Rosa", 50);
	Form		hive("Hive", 50, 100);

	std::cout << emilia << std::endl;
	std::cout << matias << std::endl;
	std::cout << rosa << std::endl;
	std::cout << hive << std::endl;

	hive.beSigned(rosa);
	rosa.signForm(hive);

	std::cout << hive << std::endl;

	matias.decrementGrade(101);
	std::cout << matias << std::endl;
	try
	{
		hive.beSigned(matias);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	matias.signForm(hive);

	std::cout << hive << std::endl;
	
	emilia.incrementGrade(51);
	hive.beSigned(emilia);
	emilia.signForm(hive);

	std::cout << hive << std::endl;

	try
	{
		Form	hive2;
		std::cout << hive2 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	hive3("Error_form", 4656, 34643);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	hive4("Error_form", 0, 80);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form	hive5("Error_form", 75, 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
