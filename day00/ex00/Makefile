# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnkadime <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 10:05:44 by lnkadime          #+#    #+#              #
#    Updated: 2017/05/22 10:10:46 by lnkadime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC =  clang++

SRC = megaphone.cpp

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(CC) -Wall -Werror -Wextra -o $(NAME) $(SRC)
	@echo "done."

clean:
	@rm -rf $(NAME)

re: clean all

