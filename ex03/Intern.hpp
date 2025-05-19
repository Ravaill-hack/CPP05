
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
		
		class FormDoesNotExist : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	private:
		AForm	*_adrForms[100];

};

#endif