/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:49:14 by corellan          #+#    #+#             */
/*   Updated: 2023/06/26 10:02:54 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
private:

	Intern(Intern const &rhs);

	Intern	&operator=(Intern const &rhs);

public:

	Intern(void);
	~Intern(void);

	AForm	*makeForm(std::string form, std::string target);
};

#endif