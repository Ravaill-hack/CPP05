/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/16 14:18:32 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{

	Bureaucrat	Default_bureaucrat;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Servant("Servant", 150);
	Form		Def_form;
	Form		newSale("Transaction", 20, 10);

	std::cout << Default_bureaucrat << std::endl;
	std::cout << Boss << std::endl;
	std::cout << Servant << std::endl;
	std::cout << Def_form << std::endl;
	std::cout << newSale << std::endl;

	try
	{
		newSale.beSigned(Servant);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
