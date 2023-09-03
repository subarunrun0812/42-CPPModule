NAME = ex02
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ifdef DEBUG
	CFLAGS += -DDEBUG
endif

SOURCES = main.cpp\
			Base.cpp\
			A.cpp\
			B.cpp\
			C.cpp\

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean: 
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: clean all
