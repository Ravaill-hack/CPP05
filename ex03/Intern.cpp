/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:27 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 11:16:32 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

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

AForm	*Intern::makeForm(const std::string form, const std::string target) const
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
		throw Intern::FormDoesNotExist();
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              EXCEPTIONS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const char * Intern::FormDoesNotExist::what() const throw()
{
	return ("Cannot create form, this form type does not exist");
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////
