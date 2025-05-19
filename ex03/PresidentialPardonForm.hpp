
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm & toCopy);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);

		PresidentialPardonForm(const std::string target);

		void			execute(Bureaucrat const & bur) const;
		std::string		getTarget() const;

	private:
		std::string		_target;
};

#endif