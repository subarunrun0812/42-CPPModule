NAME = ex01
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = main.cpp \
		  phonebook.cpp \
		  contact.cpp \

all: $(NAME) 

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all