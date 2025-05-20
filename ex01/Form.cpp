/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:23:55 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 10:19:08 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Form::Form() : _name("default form"), _gradeToSign(150), _gradeToExec(150)
{
	_signed = false;
}

Form::~Form(){}

Form::Form(const Form & toCopy) : _name(toCopy._name), _gradeToSign(toCopy._gradeToSign), _gradeToExec(toCopy._gradeToExec)
{
	_signed = toCopy._signed;
}

Form & Form::operator=(const Form & other)
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

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	_signed = false;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               GETTERS                                    ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const std::string	Form::getName() const
{
	return(_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              EXCEPTIONS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const char * Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char * Form::AlreadySignedException::what() const throw()
{
	return ("already signed");
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                             OTHER MEMBERS                                ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	Form::beSigned(const Bureaucrat & Bur)
{
	if (_signed == true)
		throw Form::AlreadySignedException();
	else if (Bur.getGrade() >= _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              NON MEMBERS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & os, const Form & FormToPrint)
{
	os << "Form " << FormToPrint.getName()
		<< ", grade to sign: " << FormToPrint.getGradeToSign()
		<< ", grade to exec: " << FormToPrint.getGradeToExec();
	return (os);
}