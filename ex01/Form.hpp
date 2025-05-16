
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		~Form();
		Form(const Form & toCopy);
		Form & operator=(const Form & other);

		Form(const std::string name, const int gradeToSign, const int gradeToExec);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

		void				beSigned(const Bureaucrat & Bur);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

};

std::ostream & operator<<(std::ostream & os, const Form & FormToPrint);

#endif