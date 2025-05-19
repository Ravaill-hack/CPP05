/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:41:31 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 10:44:16 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	_target = "Default target";
	std::cout << *this << ", target " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & toCopy) : AForm(toCopy.getName(), 25, 5)
{
	*this = toCopy;
	std::cout << *this << ", target " << _target << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	if (this != &other)
		_target = other._target;
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                          OTHER CONSTRUCTORS                              ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << *this << ", target " << _target << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 GETTERS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::string		PresidentialPardonForm::getTarget() const
{
	return (_target);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	PresidentialPardonForm::execute(Bureaucrat const & bur) const
{
	if (this->getSigned())
	{
		if (bur.getGrade() <= this->getGradeToExec())
		{
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
	
}

