# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:15:02 by clegoube          #+#    #+#              #
#    Updated: 2016/12/02 19:58:19 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	printf
SRC =	main.c ft_printf.c libft.a ft_itoa_base.c ft_atoi_base.c
HEADER = printf.h


SRCO	= $(SRC:%.c=%.o)

FLAGS =	-Wall -Werror -Wextra
CC =	@gcc -g3

all: $(NAME)

$(NAME) :
		$(CC) -o $(NAME) $(FLAGS) $(SRC) -include $(HEADER) libft.a

clean :
		@rm -f $(SRCO)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: clean

#Pensez a retirer cette commande
run: re
	@echo "COMPILED"
	@./printf
