/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:23:55 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 10:36:17 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

AForm::AForm() : _name("default form"), _gradeToSign(150), _gradeToExec(150)
{
	_signed = false;
}

AForm::~AForm(){}

AForm::AForm(const AForm & toCopy) : _name(toCopy._name), _gradeToSign(toCopy._gradeToSign), _gradeToExec(toCopy._gradeToExec)
{
	_signed = toCopy._signed;
}

AForm & AForm::operator=(const AForm & other)
{
	if (this != & other)
		_signed = other._signed;
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                          OTHER CONSTRUCTORS                              ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	_signed = false;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               GETTERS                                    ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const std::string	AForm::getName() const
{
	return(_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              EXCEPTIONS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char * AForm::FormNotSigned::what() const throw()
{
	return ("form needs to be signed first");
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                             OTHER MEMBERS                                ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	AForm::beSigned(const Bureaucrat & Bur)
{
	if (Bur.getGrade() >= _gradeToSign)
	{
		std::cerr << Bur.getName() << " couldn't sign " << _name << " because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		if (_signed == false)
		{
			std::cerr << Bur.getName() << " signed " << _name << std::endl;
			_signed = true;
		}
		else
			std::cout << _name << " is already signed" << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & os, const AForm & FormToPrint)
{
	os << "Form " << FormToPrint.getName()
		<< ", grade to sign: " << FormToPrint.getGradeToSign()
		<< ", grade to exec: " << FormToPrint.getGradeToExec();
	return (os);
}