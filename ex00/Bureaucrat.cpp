/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:59:32 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/15 11:41:25 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradTooHighException();
	}
	else if (grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradTooLowException();
	}
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy)
{
	*this = toCopy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this != &other)
	{
		_grade = other._grade;
		std::cout << "Name can't be changed because of const sting type" << std::endl;
	}
	return (*this);
}
	
const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade(int increment)
{
	if (increment < 0)
	{
		std::cout << "Increase value must be positive" << std::endl;	
		return;
	}
	if (_grade - increment < 1)
		_grade = 1;
	else
		_grade = _grade - increment;
}

void	Bureaucrat::decreaseGrade(int decrement)
{
	if (decrement < 0)
	{
		std::cout << "Decrease value must be positive" << std::endl;	
		return;
	}
	if (_grade + decrement > 150)
		_grade = 150;
	else
		_grade = _grade + decrement;
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (os);
}

const char * Bureaucrat::GradTooHighException::what() const throw()
{
	return ("Error; grade too high");
}

const char * Bureaucrat::GradTooLowException::what() const throw()
{
	return ("Error; grade too low");
}
