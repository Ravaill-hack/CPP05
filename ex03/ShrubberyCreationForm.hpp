
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm & toCopy);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);

		ShrubberyCreationForm(const std::string name);
		
		void			execute(Bureaucrat const & bur) const;
		std::string		getTarget() const;
		
	private:
		std::string		_target;
	
};

#endif