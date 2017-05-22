# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnkadime <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 10:31:24 by lnkadime          #+#    #+#              #
#    Updated: 2017/05/22 10:31:26 by lnkadime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC =  clang++

SRC =   Contact.cpp \
        main.cpp

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(CC) -Wall -Werror -Wextra -o $(NAME) $(SRC)
	@echo "done."

clean:
	@rm -rf $(NAME)

re: clean all

