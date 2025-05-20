/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 09:50:46 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{

	std::cout << "\n=== Declaration ===" << std::endl;
	
	Bureaucrat	Default_bureaucrat;
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Servant("Servant", 150);
	Bureaucrat	Copy(Servant);

	std::cout << Default_bureaucrat << std::endl;
	std::cout << Boss << std::endl;
	std::cout << Servant << std::endl;
	std::cout << Copy << std::endl;

	std::cout << "\n=== Attemptimg to decrement or increment grade ===" << std::endl;
	
	Default_bureaucrat.decrementGrade();
	Copy.incrementGrade();
	
	return (0);
}
