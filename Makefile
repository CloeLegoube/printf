# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:22:13 by clegoube          #+#    #+#              #
#    Updated: 2017/01/12 18:07:07 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	printf
SRC =	main.c ft_printf.c ft_itobase.c ft_putwstr.c ft_convert_base.c \
		ft_putwchar.c ft_strdup.c ft_putnbr_positif.c ft_strchrstr.c \
		ft_strsub.c ft_strchr.c ft_strjoin.c \
		ft_stock.c

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
