
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

		const std::string	getName() const;
		int					getGrade() const;

		void				increaseGrade(int increment);
		void				decreaseGrade(int decrement);

		class GradTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;

};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & bur);

#endif