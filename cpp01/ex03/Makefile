NAME = ex03
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp \
		  HumanA.cpp \
		  HumanB.cpp \
		  Weapon.cpp \

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
