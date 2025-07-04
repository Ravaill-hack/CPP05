/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:40:49 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 11:06:18 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{

	std::cout << "\n=== Bureaucrats creation ===" << std::endl;
    Bureaucrat boss("Boss", 1);      
    Bureaucrat MyleneFarmer("Mylene Farmer", 140);
    Bureaucrat Jul("Jul", 150);

	std::cout << "\n=== Forms creation ===" << std::endl;
    ShrubberyCreationForm shrubForm("Monica Bellucci");
    RobotomyRequestForm robotForm("Brad Pitt");
    PresidentialPardonForm pardonForm("Valerie Damido");
	PresidentialPardonForm testForm("une anguille");

    std::cout << "\n=== Attempting to execute forms without signing ===" << std::endl;
	boss.executeForm(shrubForm);

    std::cout << "\n=== Signing forms ===" << std::endl;
    boss.signForm(shrubForm);
    boss.signForm(robotForm);
    boss.signForm(pardonForm);

    std::cout << "\n=== Trying to sign already signed form ===" << std::endl;
    boss.signForm(shrubForm);

    std::cout << "\n=== Executing forms with sufficient grade ===" << std::endl;
    boss.executeForm(shrubForm);
    boss.executeForm(robotForm);
    boss.executeForm(pardonForm);

    std::cout << "\n=== Trying to execute with insufficient grade ===" << std::endl;
    MyleneFarmer.executeForm(robotForm);

    std::cout << "\n=== Trying to sign with insufficient grade ===" << std::endl;
    Jul.signForm(testForm);

    return (0);
}
