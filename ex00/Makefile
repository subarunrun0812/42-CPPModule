NAME = megaphone
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SOURCES = megaphone.cpp

all: $(NAME) 

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all