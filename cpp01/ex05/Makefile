NAME = ex05
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp \
		  Harl.cpp \

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
