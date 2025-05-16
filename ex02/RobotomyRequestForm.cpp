/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:41:36 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/16 17:16:43 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "Default target";
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & toCopy) : AForm(toCopy.getName(), 72, 45)
{
	*this = toCopy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
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

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	RobotomyRequestForm::executeForm(Bureaucrat const & bur) const
{
	if (this->getSigned())
	{
		if (bur.getGrade() <= this->getGradeToExec())
		{
			//to complete
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
	
}

