/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:27 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 14:12:02 by lmatkows         ###   ########.fr       */
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
	if (form == "PresidentialPardonForm")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else if (form == "RobotomyRequestForm")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "ShrubberyCreationForm")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else
	{
		std::cerr << "Type " << form << " is not a valid form type" << std::endl;
		return (NULL);
	}
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////
