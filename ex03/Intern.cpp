/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:27 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 11:55:08 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Intern::Intern()
{
	std::cout << "A random intern has been created" << std::endl;
}

Intern::~Intern(){}

Intern::Intern(const Intern & toCopy)
{
	std::cout << "A random intern has been created" << std::endl;
	(void)toCopy;
}

Intern & Intern::operator=(const Intern & other)
{
	(void)other;
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

AForm	*Intern::makeForm(const std::string form, const std::string target)
{
	int	i = 0;
	std::string	FormTypes[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *(*FunctionsTab[3])(const std::string &) = {NewPresidential, NewRobotomy, NewShrubbery};
	while (i < 3)
	{
		if (form == FormTypes[i])
			return (FunctionsTab[i](target));
		i++;
	}
	std::cerr << "Type " << form << " is not a valid form type" << std::endl;
	return (NULL);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

AForm *NewPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *NewRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *NewShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}
