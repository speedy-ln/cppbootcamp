NAME = convert

COMPILE = clang++ -Wall -Werror -Wextra

SRC =	main.cpp \
		Converter.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME):
	$(COMPILE) -o $(NAME) $(SRC)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all