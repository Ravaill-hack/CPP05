/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:41:39 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 10:20:53 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                CANONIC                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "Default target";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & toCopy) : AForm(toCopy.getName(), 145, 137)
{
	*this = toCopy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 GETTERS                                  ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

std::string		ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	ShrubberyCreationForm::execute(Bureaucrat const & bur) const
{
	if (this->getSigned())
	{
		if (bur.getGrade() <= this->getGradeToExec())
		{
			const std::string	outfile = _target + "_shrubbery";
			std::ofstream		outstream;
			
			outstream.open(outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
			if (!outstream)
				std::cerr << "Error: cannot create shrubbery outfile" << std::endl;
			else
			{
				outstream << "                                    " << std::endl;
				outstream << "       /\\                           " << std::endl;
				outstream << "      /  \\                 /\\       " << std::endl;
				outstream << "     /    \\            /\\ /  \\      " << std::endl;
				outstream << "    /      \\          /  \\_  _\\     " << std::endl;
				outstream << "   /___  ___\\        /    \\||       " << std::endl;
				outstream << "       ||           /__  __\\        " << std::endl;
				outstream << "              /\\       ||           " << std::endl;
				outstream << "             /  \\                   " << std::endl;
				outstream << "             /  \\         / *\\      " << std::endl;
				outstream << "            /    \\      ( ()   )    " << std::endl;
				outstream << "            /    \\     ( *)     )   " << std::endl;
				outstream << "           /      \\      (    )     " << std::endl;
				outstream << "          / /    \\ \\       ||       " << std::endl;
				outstream << "          /        \\                " << std::endl;
				outstream << "         /          \\               " << std::endl;
				outstream << "        /            \\              " << std::endl;
				outstream << "       /__/__|  |__\\__\\             " << std::endl;
				outstream << "             |  |                   " << std::endl;
				std::cout << outfile << " created" <<std::endl;

			}
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
	
}

