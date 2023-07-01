NAME = ex02
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = Account.cpp \
		  tests.cpp


all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)