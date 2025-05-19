
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm & toCopy);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);

		RobotomyRequestForm(const std::string name);

		void			execute(Bureaucrat const & bur) const;
		std::string		getTarget() const;
		
	private:
		std::string		_target;
	
};

#endif