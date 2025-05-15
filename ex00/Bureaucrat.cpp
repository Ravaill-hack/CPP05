/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:59:32 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/15 11:19:58 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){}

Bureaucrat::Bureaucrat(const Bureaucrat & toCopy)
{
	*this = toCopy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this != &other)
	{
		_grade = other._grade;
		_name = other._name;
	}
	return (*this);
}
	
std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::setName(std::string name)
{
	_name = name;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 0)
		std::cout << "Grade too high" << std::endl;
	else if (grade > 150)
		std::cout << "Grade too low" << std::endl;
	else
		_grade = grade;
	return;
}

void	Bureaucrat::increaseGrade(int increment)
{
	if (_grade - increment < 0)
		_grade = 0;
	else if (_grade - increment > 150)
		_grade = 150;
	else
		_grade = _grade - increment;
	
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return (os);
}
