/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/19 14:23:17 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "\n=== Declaration ===" << std::endl;
	
	AForm	*shrubForm = NULL;
	AForm	*robotForm = NULL;
	AForm	*pardonForm = NULL;
	AForm	*testForm = NULL;
	Intern	intern01;
	Intern	intern02;
	Intern	intern03;
	Intern	intern04;

	try
	{

		std::cout << "\n=== Bureaucrats creation ===" << std::endl;
        Bureaucrat boss("Boss", 1);      
        Bureaucrat MyleneFarmer("Mylene Farmer", 140);
        Bureaucrat Jul("Jul", 150);

		std::cout << "\n=== Forms creation ===" << std::endl;
        
		shrubForm = intern01.makeForm("ShrubberyCreationForm", "Monica Bellucci");
		robotForm = intern02.makeForm("RobotomyRequestForm", "Brad Pitt");
		pardonForm = intern03.makeForm("PresidentialPardonForm", "Valerie Damidot");
		testForm = intern04.makeForm("test", "A random star");

        std::cout << "\n=== Attempting to execute forms without signing ===" << std::endl;
        try
		{
            shrubForm->execute(boss);
        }
		catch (AForm::FormNotSigned &e)
		{
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n=== Signing forms ===" << std::endl;
		try
		{
			boss.signForm(*shrubForm);
        	boss.signForm(*robotForm);
        	boss.signForm(*pardonForm);
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		
        std::cout << "\n=== Trying to sign already signed form ===" << std::endl;
        boss.signForm(*shrubForm);
	
        std::cout << "\n=== Executing forms with sufficient grade ===" << std::endl;
		try
		{
        	boss.executeForm(*shrubForm);
        	boss.executeForm(*robotForm);
        	boss.executeForm(*pardonForm);

        	std::cout << "\n=== Trying to execute with insufficient grade ===" << std::endl;
     		MyleneFarmer.executeForm(*robotForm);
		}
		catch (AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n=== Trying to sign with insufficient grade ===" << std::endl;
        Jul.signForm(*shrubForm);

    }
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << e.what() << std::endl;
    }
	if (shrubForm)
		delete shrubForm;
	if (robotForm)
		delete robotForm;
	if (pardonForm)
		delete pardonForm;
	if (testForm)
		delete testForm;
    return 0;
}
