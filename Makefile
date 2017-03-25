# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:22:13 by clegoube          #+#    #+#              #
#    Updated: 2017/03/25 14:01:45 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc
FLAGS = -g
# FLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a
SRCLIB = main4.c ft_printf.c \
				ft_stock.c ft_manage_struc.c

LIBFT = libft/ft_atoi.c libft/ft_itobase.c libft/ft_putwstr.c \
		libft/ft_convert_base.c libft/ft_putwchar.c libft/ft_strdup.c \
		libft/ft_putnbr_positif.c libft/ft_strchrstr.c libft/ft_strsub.c \
		libft/ft_strchr.c libft/ft_strjoin.c libft/ft_strcmp.c libft/ft_itoa.c\
 		libft/ft_itoa_positif.c libft/ft_putstr.c libft/ft_putchar.c \
 		libft/ft_strnew.c libft/ft_strlen.c libft/ft_wstrdup.c \
		libft/ft_strrchr.c libft/ft_indexchr.c libft/ft_wstrlen.c \
		libft/ft_wstrnew.c libft/ft_wstrcmp.c libft/ft_wstrsub.c \
		libft/ft_strcut_unicode.c libft/ft_memset.c libft/ft_memcpy.c \
		libft/ft_wmemset.c

CONVERSION 	= 	conversion/S_s_conversion.c conversion/G_S_conversion.c \
				conversion/p_conversion.c conversion/S_d_conversion.c \
				conversion/G_D_conversion.c conversion/S_i_conversion.c \
				conversion/S_o_conversion.c conversion/G_O_conversion.c \
				conversion/S_u_conversion.c conversion/G_U_conversion.c \
				conversion/S_x_conversion.c conversion/G_X_conversion.c \
				conversion/S_c_conversion.c conversion/G_C_conversion.c \
				conversion/no_conversion.c

MODIFICATION =	modify/ft_modify_length.c modify/ft_modify_htag.c \
				modify/ft_modify_precision.c modify/ft_modify_sign_plus.c \
				modify/ft_modify_width.c modify/ft_modify_space.c \
				modify/ft_modify_string.c

OBJ =	$(SRCLIB:.c=.o)
OBJLIBFT= $(LIBFT:libft/%.c=%.o)
OBJCONV= $(CONVERSION:conversion/%.c=%.o)
OBJMODIF= $(MODIFICATION:modify/%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) $(OBJLIBFT) $(OBJCONV) $(OBJMODIF) && ranlib $(NAME)

%.o: %.c
	@$(GCCF) $(FLAGS) -c $(SRCLIB) $(LIBFT) $(CONVERSION) $(MODIFICATION)

%.o: libft/%.c
	@$(GCCF) $(FLAGS) -c $(LIBFT)

%.o: conversion/%.c
	@$(GCCF) $(FLAGS) -c $(CONVERSION)

%.o: modify/%.c
	@$(GCCF) $(FLAGS) -c $(CONVERSION)

clean:
	@rm -f $(OBJ) $(OBJLIBFT) $(OBJCONV) $(OBJMODIF)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean

exec: re
	@gcc -o printf main4.c libftprintf.a && ./printf

run: exec fclean

val:
	valgrind --leak-check=full ./printf
