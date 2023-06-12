NAME = ex00
CC = g++
CFLAGS = -Wall -Wextra -Werror

SOURCES = newZombie.cpp \
		  randomChump.cpp \ 
		  Zombie.cpp \

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all