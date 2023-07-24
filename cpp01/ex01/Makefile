NAME = ex01
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = Zombie.cpp \
		  main.cpp \
		  zombieHorde.cpp

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
