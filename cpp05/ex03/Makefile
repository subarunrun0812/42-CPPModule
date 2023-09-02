NAME = ex03
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifdef DEBUG
	CFLAGS += -DDEBUG
endif

SOURCES = main.cpp\
			Bureaucrat.cpp\
			AForm.cpp\
			Intern.cpp\
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
