NAME = ex01
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp\
			animal.cpp\
			cat.cpp\
			dog.cpp\
			Brain.cpp\

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean: 
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all