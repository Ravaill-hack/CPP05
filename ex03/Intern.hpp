
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <fstream>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern & toCopy);
		Intern & operator=(const Intern & other);

		AForm	*makeForm(const std::string form, const std::string target);

};

AForm *NewPresidential(const std::string &target);
AForm *NewRobotomy(const std::string &target);
AForm *NewShrubbery(const std::string &target);

#endif