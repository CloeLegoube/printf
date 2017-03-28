/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:21:44 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/28 20:48:17 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <string.h>
# include <stdlib.h>

#include <stdarg.h>

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <wctype.h>
# include <strings.h>

# include <limits.h>
# include <locale.h>
# include <stdint.h>
# include "libft/libft.h"

enum conversion
{
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
	C,
	Q = 42,
};

enum couleur
{
	eoc,
	noir = 30,
	rouge,
	vert,
	jaune,
	bleu,
	magenta,
	cyan,
	blanc,
};

typedef	struct	s_print
{
	int 			conversion;
	int				htag;
	int				wildcard;
	char			*htag_prefixe;
	int				plus;
	int				less;
	int				percentage;
	int				zero;
	int				sign_less;
	int				value_zero;
	int				space;
	int				precision;
	int				checkprecision;
	int				size;
	char			*flags;
	char			*string;
	char			*result;
	int				strlen;
	wchar_t			*wstring;
	int				wbyte;
	int				len;
	int				index;
	// int				start;
	// int				end;
	struct		s_print *next;
}				t_print;

int				g_strlen;
int				g_start;
int				g_end;


int				ft_printf(char *format, ...);
void			ft_initialize_struct(t_print *new);
void			ft_manage_conversion(char *conversion, t_print *new, va_list arg);
void			ft_manage_struc(va_list arg, t_print *new);

void			ft_stock_attributes(t_print *new, char *conversion, va_list arg);
void			ft_stock_size(t_print *new, char *conversion, va_list arg);
void			ft_stock_precision(t_print *new, char *conversion, va_list arg);
void			ft_stock_flags(t_print *new, char *conversion);

char			*ft_modify_htag(va_list arg, t_print *new, char *base);
intmax_t		ft_modify_length_di(va_list arg, t_print *new);
uintmax_t		ft_modify_length_uoxX(va_list arg, t_print *new);
char			ft_modify_length_c(va_list arg, t_print *new);
char			*ft_modify_precision(char *string, t_print *new);
char			*ft_modify_sign(char *string, t_print *new);
char			*ft_modify_space(char *string, t_print *new);
char			*ft_modify_width(char *string, t_print *new);
void			ft_modify_color(va_list arg, t_print *new);

void			modify_string(char **string, t_print *new, int yes, char *(*f)(char *, t_print *));
void			modify_wstring(wchar_t **string, t_print *new, int yes, char *(*f)(char *, t_print *));


void				(*g_f[101])(t_print*, va_list);
void				c_conversion(t_print*, va_list);
void				C_conversion(t_print*, va_list);
void				d_conversion(t_print*, va_list);
void				D_conversion(t_print*, va_list);
void				i_conversion(t_print*, va_list);
void				o_conversion(t_print*, va_list);
void				O_conversion(t_print*, va_list);
void				p_conversion(t_print*, va_list);
void				s_conversion(t_print*, va_list);
void				S_conversion(t_print*, va_list);
void				u_conversion(t_print*, va_list);
void				U_conversion(t_print*, va_list);
void				x_conversion(t_print*, va_list);
void				X_conversion(t_print*, va_list);
void				no_conversion(t_print*, va_list);

#endif


//
// typedef	struct	s_var
// {
// 	int 			i;
// 	int 			j;
// 	int				a;
// 	int				b;
// }				t_var;

// int				ft_atoi(const char *str);
// int				ft_isalpha(int c);
// int				ft_isdigit(int c);
// int				ft_isalnum(int c);
// int				ft_isascii(int c);
// void			ft_putchar(char c);
// void			ft_putstr(char const *s);
// void			ft_putendl(char const *s);
// void			ft_putnbr(int n);
// void			ft_putchar_fd(char c, int fd);
// void			ft_putstr_fd(char const *s, int fd);
// void			ft_putendl_fd(char const *s, int fd);
// void			ft_putnbr_fd(int n, int fd);
// size_t		ft_strlen(const char *s);
// int				ft_strcmp(const char *s1, const char *s2);
// char			*ft_strnew(size_t size);
// char			*ft_strdup(const char *s1);
// char			*ft_strsub(char const *s, unsigned int start, size_t len);
// char			*ft_strjoin(char const *s1, char const *s2);
// char			*ft_strchr(const char *s, int c);
// char			*ft_strrchr(const char *s, int c);
// char			*ft_itoa(intmax_t n);
