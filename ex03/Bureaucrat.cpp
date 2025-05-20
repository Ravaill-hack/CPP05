/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:59:32 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 11:12:47 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << *this << std::endl;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy) : _name(toCopy._name + "_copy")
{
	*this = toCopy;
	std::cout << *this << std::endl;
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
	try
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
		std::cout << *this << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Couldn't create " << name << " because " << e.what() << std::endl;
		std::cerr << "Specify a grade between 1 and 150" << std::endl;
	}
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
	std::cout << "\nYou want to increment " << this->_name << " grade, which is currently of " << this->_grade <<std::endl;
	try
	{
		if (_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
		{
			_grade -= 1;
			std::cout << this->_name << "'s new grade is now " << this->_grade << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Couldn't increment " << this->_name << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "\nYou want to decrement " << this->_name << " grade, which is currently of " << this->_grade <<std::endl;
	try
	{
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			_grade += 1;
			std::cout << this->_name << "'s new grade is now " << this->_grade << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Couldn't decrement " << this->_name << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &formulaire)
{
	std::cout << "\n" << this->_name << " wants to sign " << formulaire.getName() <<std::endl;
	try
	{
		formulaire.beSigned(*this);
		std::cout << "Form " << formulaire.getName() << " has been successfully signed by " << this->_name << std::endl;
	}
	catch(const AForm::GradeTooLowException& el)
	{
		std::cerr << "Form " << formulaire.getName() << " couldn't be signed because " << this->_name << "'s " << el.what() << '\n';
	}
	catch(const AForm::AlreadySignedException& el)
	{
		std::cerr << "Form " << formulaire.getName() << " has been " << el.what() << '\n';
	}
}

void	Bureaucrat::executeForm(const AForm & form)
{
	std::cout << "\n" << this->_name << " wants to execute " << form.getName() <<std::endl;
	try
	{
		form.execute(*this);
		std::cout << "Form " << form.getName() << " has been successfully executed by " << this->_name << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "Form " << form.getName() << " couldn't be executed because " << e.what() << '\n';
	}
	catch(const AForm::FormNotSigned& e)
	{
		std::cerr << "Form " << form.getName() << " couldn't be executed because " << e.what() << '\n';
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
