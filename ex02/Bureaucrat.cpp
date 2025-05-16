/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:59:32 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/16 17:08:02 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy) : _name(toCopy._name + "_copy")
{
	*this = toCopy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                          OTHER CONSTRUCTORS                              ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else
		_grade = grade;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               GETTERS                                    ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += 1;
}

void	Bureaucrat::signForm(AForm &formulaire)
{
	try
	{
		formulaire.beSigned(*this);
	}
	catch(const AForm::GradeTooHighException& eh)
	{
		std::cerr << eh.what() << '\n';
	}
	catch(const AForm::GradeTooLowException& el)
	{
		std::cerr << el.what() << '\n';
	}
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              EXCEPTIONS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error; grade too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error; grade too low");
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (os);
}
