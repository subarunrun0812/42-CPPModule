NAME = ex01
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = set.cpp \
		  get.cpp \
		  main.cpp \
		  add.cpp \
		  search.cpp \

all: $(NAME) 

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all