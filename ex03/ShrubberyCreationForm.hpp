/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:42:57 by corellan          #+#    #+#             */
/*   Updated: 2023/06/23 14:26:21 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:

	std::string	_target;
	ShrubberyCreationForm(ShrubberyCreationForm const &rhs);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);

	std::string	getTarget(void) const;
	void		execute(Bureaucrat &executor);
};

#endif