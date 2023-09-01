NAME = ex02
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp\
			Bureaucrat.cpp\
			Form.cpp\
			PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp\
			ShrubberyCreationForm.cpp\

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean: 
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
