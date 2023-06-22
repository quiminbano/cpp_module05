/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:42:57 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 18:15:48 by corellan         ###   ########.fr       */
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

	void	execute(Bureaucrat &executer);
};

#endif