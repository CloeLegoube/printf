# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:22:13 by clegoube          #+#    #+#              #
#    Updated: 2017/02/06 11:13:05 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Werror -Wextra -g
NAME = libftprintf.a
SRCLIB = main2.c ft_printf.c ft_itobase.c ft_putwstr.c ft_convert_base.c \
		ft_putwchar.c ft_strdup.c ft_putnbr_positif.c ft_strchrstr.c \
		ft_strsub.c ft_strchr.c ft_strjoin.c ft_strcmp.c ft_atoi.c ft_itoa.c\
		ft_stock.c ft_manage_struc.c ft_itoa_positif.c ft_modify_length.c \
		ft_modify_htag.c ft_modify_precision.c ft_modify_conversion.c \
		ft_modify_sign.c ft_putstr.c ft_putchar.c ft_strnew.c ft_strlen.c \
		ft_wstrdup.c

OBJ =	$(SRCLIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) && ranlib $(NAME)

%.o: %.c
	@$(GCCF) -c $(SRCLIB)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean

exec: re
	@gcc -o printf main2.c libftprintf.a && ./printf | cat -e

run: exec fclean

val:
	valgrind --leak-check=full ./printf
