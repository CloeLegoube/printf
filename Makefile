# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:22:13 by clegoube          #+#    #+#              #
#    Updated: 2017/01/04 17:19:30 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	printf
SRC =	main.c ft_printf.c ft_itoa_base.c ft_atoi_base.c ft_itobase.c ft_putwstr.c
HEADER = libftprintf.h


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
