
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat & toCopy);
		Bureaucrat & operator=(const Bureaucrat & other);
	
		Bureaucrat(std::string name, int grade);

		std::string			getName() const;
		int					getGrade() const;

		void				setName(std::string name);
		void				setGrade(int grade);
		void				increaseGrade(int increment);

	private:
		std::string			_name;
		int					_grade;

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur);

#endif