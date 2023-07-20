NAME = ex01
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = newZombie.cpp \
		  randomChump.cpp \
		  main.cpp \
		  zombieHorde.cpp \
		  Zombie.cpp \

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
