/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 10:23:36 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{

	try
	{
        Bureaucrat boss("Boss", 1);      
        Bureaucrat MyleneFarmer("Mylene Farmer", 140);        // Grade moyen
        Bureaucrat Jul("Jul", 150); // Grade le plus bas

        ShrubberyCreationForm shrubForm("Monica Bellucci");
        RobotomyRequestForm robotForm("Brad Pitt");
        PresidentialPardonForm pardonForm("Valerie Damido");

        std::cout << "\n=== Attempting to execute forms without signing ===" << std::endl;
        try
		{
            shrubForm.execute(boss);
        }
		catch (std::exception &e)
		{
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n=== Signing forms ===" << std::endl;
        boss.signForm(shrubForm);
        boss.signForm(robotForm);
        boss.signForm(pardonForm);

        std::cout << "\n=== Trying to sign already signed form ===" << std::endl;
        boss.signForm(shrubForm); // déjà signé

        std::cout << "\n=== Executing forms with sufficient grade ===" << std::endl;
        boss.executeForm(shrubForm);
        boss.executeForm(robotForm);
        boss.executeForm(pardonForm);

        std::cout << "\n=== Trying to execute with insufficient grade ===" << std::endl;
        MyleneFarmer.executeForm(robotForm); // pas assez de grade

        std::cout << "\n=== Trying to sign with insufficient grade ===" << std::endl;
        Jul.signForm(shrubForm); // grade trop bas

    }
	catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
