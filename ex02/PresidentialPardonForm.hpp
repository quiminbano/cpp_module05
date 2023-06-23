/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:05:58 by corellan          #+#    #+#             */
/*   Updated: 2023/06/23 14:26:32 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
private:

	std::string	_target;
	PresidentialPardonForm(PresidentialPardonForm const &rhs);

	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string name);
	~PresidentialPardonForm(void);

	std::string	getTarget(void) const;
	void		execute(Bureaucrat &executor);
};

#endif