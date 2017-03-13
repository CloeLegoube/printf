# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:22:13 by clegoube          #+#    #+#              #
#    Updated: 2017/02/01 17:19:40 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Werror -Wextra -g
NAME = libftprintf.a
SRCLIB = main.c ft_printf.c \
				ft_stock.c ft_manage_struc.c

LIBFT = libft/ft_atoi.c libft/ft_itobase.c libft/ft_putwstr.c \
				libft/ft_convert_base.c libft/ft_putwchar.c libft/ft_strdup.c \
				libft/ft_putnbr_positif.c libft/ft_strchrstr.c libft/ft_strsub.c \
				libft/ft_strchr.c libft/ft_strjoin.c libft/ft_strcmp.c libft/ft_itoa.c\
		 		libft/ft_itoa_positif.c libft/ft_putstr.c libft/ft_putchar.c \
		 		libft/ft_strnew.c libft/ft_strlen.c libft/ft_wstrdup.c \
				libft/ft_strrchr.c libft/ft_indexchr.c libft/ft_wstrlen.c \
				libft/ft_wstrnew.c libft/ft_wstrcmp.c libft/ft_wstrsub.c

CONVERSION 	= 	conversion/s_conversion.c conversion/S_conversion.c \
								conversion/p_conversion.c conversion/d_conversion.c \
								conversion/D_conversion.c conversion/i_conversion.c \
								conversion/o_conversion.c conversion/O_conversion.c \
								conversion/u_conversion.c conversion/U_conversion.c \
								conversion/x_conversion.c conversion/X_conversion.c \
								conversion/c_conversion.c conversion/C_conversion.c

MODIFICATION =	modify/ft_modify_length.c modify/ft_modify_htag.c \
								modify/ft_modify_precision.c modify/ft_modify_sign+.c \
								modify/ft_modify_conversion.c modify/ft_modify_width.c \
								modify/ft_modify_space.c modify/ft_modify_wwidth.c

OBJ =	$(SRCLIB:.c=.o)
OBJLIBFT= $(LIBFT:libft/%.c=%.o)
OBJCONV= $(CONVERSION:conversion/%.c=%.o)
OBJMODIF= $(MODIFICATION:modify/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) $(OBJLIBFT) $(OBJCONV) $(OBJMODIF) && ranlib $(NAME)

%.o: %.c
	@$(GCCF) -c $(SRCLIB) $(LIBFT) $(CONVERSION) $(MODIFICATION)

%.o: libft/%.c
	@$(GCCF) -c $(LIBFT)

%.o: conversion/%.c
	@$(GCCF) -c $(CONVERSION)

%.o: modify/%.c
	@$(GCCF) -c $(CONVERSION)

clean:
	@rm -f $(OBJ) $(OBJLIBFT) $(OBJCONV) $(OBJMODIF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean

exec: re
	@gcc -o printf main.c libftprintf.a && ./printf

run: exec fclean

val:
	valgrind --leak-check=full ./printf
