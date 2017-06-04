NAME = ft_gkrellm

COMPILE = clang++ -Wall -Werror -Wextra

SRC = IMonitorModule.cpp \
      IMonitorDisplay.cpp \
      test.cpp

INCLUDES = displays/*.cpp \
	   modules/*.cpp

FLAGS = -lncurses

FLGS = -I/usr/local/include -L/usr/local/lib -lallegro -lallegro_main -lallegro_font -lallegro_ttf -lncurses

OBJ = $(INCLUDES:.cpp=.o)

$(NAME):
	$(COMPILE) -o $(NAME) $(SRC) $(INCLUDES) $(FLGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
