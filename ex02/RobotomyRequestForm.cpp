/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:41:36 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 10:33:02 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "Default target";
	std::cout << _name << " with target " << _target << " has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & toCopy) : AForm(toCopy.getName(), 72, 45)
{
	*this = toCopy;
	std::cout << _name << " with target " << _target << " has been created by copy" << std::endl;
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

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << _name << " with target " << _target << " has been created" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 GETTERS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::string		RobotomyRequestForm::getTarget() const
{
	return (_target);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	RobotomyRequestForm::execute(Bureaucrat const & bur) const
{
	if (this->getSigned())
	{
		if (bur.getGrade() <= this->getGradeToExec())
		{
			std::srand(std::time(NULL));
			std::cout << "DRRRRRRRRZBIPBIPBIPBIP" << std::endl;
			if (std::rand() % 2 == 0)
				std::cout << _target << " has been robotomized successfully" << std::endl;
			else
				std::cout << _target << " robotomization failed" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
	
}

