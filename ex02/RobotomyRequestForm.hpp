/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:56:51 by corellan          #+#    #+#             */
/*   Updated: 2023/06/22 18:15:41 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
private:

	std::string	_target;
	RobotomyRequestForm(RobotomyRequestForm &rhs);

	RobotomyRequestForm	&operator=(RobotomyRequestForm &rhs);

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);

	void	execute(Bureaucrat &executer);
};

#endif