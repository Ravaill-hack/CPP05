/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 11:53:56 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{

	try
	{
		std::cout << "\n=== Bureaucrats creation ===" << std::endl;
        Bureaucrat boss("Boss", 1);      
        Bureaucrat MyleneFarmer("Mylene Farmer", 140);        // Grade moyen
        Bureaucrat Jul("Jul", 150); // Grade le plus bas

		std::cout << "\n=== Interns creation ===" << std::endl;
        Intern Intern01;      
        Intern aRandomIntern;
        Intern anotherRandomIntern;

		std::cout << "\n=== Forms creation ===" << std::endl;
        AForm 	*shrubForm;
        AForm 	*robotForm;
        AForm 	*pardonForm;
		//AForm	*testForm;

		shrubForm = Intern01.makeForm("ShrubberyCreationForm", "Monica Bellucci");
		robotForm = Intern01.makeForm("RobotomyRequestForm", "Brad Pitt");
		pardonForm = Intern01.makeForm("PresidentialPardonForm", "Valerie Damido");
		//testForm = aRandomIntern.makeForm("test", "a random guy");

        std::cout << "\n=== Attempting to execute forms without signing ===" << std::endl;
        try
		{
        	shrubForm->execute(boss);
        }
		catch (std::exception &e)
		{
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n=== Signing forms ===" << std::endl;
        boss.signForm(*shrubForm);
        boss.signForm(*robotForm);
        boss.signForm(*pardonForm);

        std::cout << "\n=== Trying to sign already signed form ===" << std::endl;
        boss.signForm(*shrubForm); // déjà signé

        std::cout << "\n=== Executing forms with sufficient grade ===" << std::endl;
        boss.executeForm(*shrubForm);
        boss.executeForm(*robotForm);
        boss.executeForm(*pardonForm);

        std::cout << "\n=== Trying to execute with insufficient grade ===" << std::endl;
        MyleneFarmer.executeForm(*robotForm); // pas assez de grade

        std::cout << "\n=== Trying to sign with insufficient grade ===" << std::endl;
        Jul.signForm(*shrubForm); // grade trop bas

    }
	catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
