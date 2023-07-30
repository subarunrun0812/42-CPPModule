NAME = ex01
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp \
		  ClapTrap.cpp \
		  ScavTrap.cpp \
	
all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
