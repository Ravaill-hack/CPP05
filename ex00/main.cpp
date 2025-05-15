/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/15 14:13:49 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{

	Bureaucrat	Default_bureaucrat;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Servant("Servant", 150);
	Bureaucrat	Copy(Servant);

	std::cout << Default_bureaucrat << std::endl;
	std::cout << Boss << std::endl;
	std::cout << Servant << std::endl;
	std::cout << Copy << std::endl;

	try
	{
		Default_bureaucrat.decrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << Copy << std::endl;
	try
	{
		Copy.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << Copy << std::endl;
	return (0);
}
