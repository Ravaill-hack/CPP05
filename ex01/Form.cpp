/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:23:55 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/15 15:26:10 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Form::Form() : _signed(false), _name("default form"), _gradeToSign(150), _gradeToExec(150){}

Form::~Form(){}

Form::Form(const Form & toCopy) : _signed(toCopy._signed), _name(toCopy._name), _gradeToSign(toCopy._gradeToSign), _gradeToExec(toCopy._gradeToExec){}

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

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _signed(false), _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){}

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

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                             OTHER MEMBERS                                ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	Form::beSigned(const Bureaucrat & Bur)
{
	if (Bur.getGrade() >= _gradeToSign)
	{
		std::cerr << Bur.getName() << " couldn't sign " << _name << " because ";
		throw Form::GradeTooLowException();
	}
	else
	{
		std::cerr << Bur.getName() << " signed " << _name << std::endl;
		_signed = true;
	}
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