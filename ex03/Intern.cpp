/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:27 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 11:52:20 by lmatkows         ###   ########.fr       */
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
	int	i = 0;

	std::cout << "A random intern has been created" << std::endl;
	while (i < 100)
	{
		_adrForms[i] = NULL;
		i++;
	}
}

Intern::~Intern()
{
	int	i = 0;

	while (_adrForms[i] != NULL)
	{
		delete _adrForms[i];
		i++;
	}
}

Intern::Intern(const Intern & toCopy)
{
	int	i = 0;

	std::cout << "A random intern has been created" << std::endl;
	while (i < 100)
	{
		_adrForms[i] = NULL;
		i++;
	}
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
		int	i = 0;
		std::cout << "Intern creates " << form << std::endl;
		while (_adrForms[i] == NULL)
			i++;
		_adrForms[i] = new PresidentialPardonForm(target);
		return (_adrForms[i]);
	}
	else if (form == "RobotomyRequestForm")
	{
		int	i = 0;
		std::cout << "Intern creates " << form << std::endl;
		while (_adrForms[i] == NULL)
			i++;
		_adrForms[i] = new RobotomyRequestForm(target);
		return (_adrForms[i]);
	}
	else if (form == "ShrubberyCreationForm")
	{
		int	i = 0;
		std::cout << "Intern creates " << form << std::endl;
		while (_adrForms[i] == NULL)
			i++;
		_adrForms[i] = new ShrubberyCreationForm(target);
		return (_adrForms[i]);
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
