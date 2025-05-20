/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 10:15:30 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "\n=== Declaration ===" << std::endl;
	
	Bureaucrat	Default_bureaucrat;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Intrigant("Un intrigant a la cour", 15);
	Bureaucrat	Servant("Servant", 150);
	Bureaucrat	Copy(Servant);
	Form		Def_form;
	Form		newSale("Transaction", 20, 10);

	std::cout << Default_bureaucrat << std::endl;
	std::cout << Boss << std::endl;
	std::cout << Servant << std::endl;
	std::cout << Copy << std::endl;
	std::cout << Def_form << std::endl;
	std::cout << newSale << std::endl;

	std::cout << "\n=== Attemptimg to decrement or increment grade ===" << std::endl;
	
	Default_bureaucrat.decrementGrade();
	Copy.incrementGrade();

	std::cout << Default_bureaucrat << std::endl;
	std::cout << Boss << std::endl;
	std::cout << Servant << std::endl;

	std::cout << "\n=== Attemptimg to sign forms ===" << std::endl;

	Servant.signForm(newSale);
	Boss.signForm(newSale);
	Intrigant.signForm(newSale);

	return (0);
}
