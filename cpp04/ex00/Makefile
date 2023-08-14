NAME = ex00
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp\
			animal.cpp\
			cat.cpp\
			dog.cpp\
			WrongAnimal.cpp\
			WrongCat.cpp\

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean: 
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
