
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm & toCopy);
		AForm & operator=(const AForm & other);

		AForm(const std::string name, const int gradeToSign, const int gradeToExec);

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
		class FormNotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};

		virtual void		executeForm(Bureaucrat const & bur) const = 0;
	
	protected:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

};

std::ostream & operator<<(std::ostream & os, const AForm & FormToPrint);

#endif