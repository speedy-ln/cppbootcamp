NAME = serialize

COMPILE = clang++ -Wall -Werror -Wextra

SRC =	main.cpp \
		Serialization.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME):
	$(COMPILE) -o $(NAME) $(SRC)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all