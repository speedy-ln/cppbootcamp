NAME = ft_gkrellm

COMPILE = clang++ -Wall -Werror -Wextra

SRC = IMonitorModule.cpp \
      IMonitorDisplay.cpp \
      test.cpp

INCLUDES = displays/*.cpp \
	   modules/*.cpp

FLAGS = -lncurses

OBJ = $(INCLUDES:.cpp=.o)

$(NAME):
	$(COMPILE) -o $(NAME) $(SRC) $(INCLUDES) $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
