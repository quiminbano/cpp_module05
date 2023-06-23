/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:56:51 by corellan          #+#    #+#             */
/*   Updated: 2023/06/23 14:41:10 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
private:

	std::string	_target;
	RobotomyRequestForm(RobotomyRequestForm const &rhs);

	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);

	std::string	getTarget(void) const;
	void		execute(Bureaucrat &executor);
};

#endif