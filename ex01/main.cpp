/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:42:17 by corellan          #+#    #+#             */
/*   Updated: 2023/06/19 15:12:41 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "ParameterMissing.hpp"

int	main(void)
{
	Bureaucrat	emilia("Emilia", 150);
	Bureaucrat	matias("Matias", 1);
	Bureaucrat	rosa("Rosa", 50);

	std::cout << emilia << std::endl;
	std::cout << matias << std::endl;
	std::cout << rosa << std::endl;
	try
	{
		emilia.decrementGrade(1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		matias.incrementGrade(1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		rosa.incrementGrade(100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	john;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
