/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:21:44 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/01 18:28:49 by clegoube         ###   ########.fr       */
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
};

typedef	struct	s_var
{
	int 			i;
	int 			j;
	int				a;
	int				b;
}				t_var;

typedef	struct	s_print
{
	int 			conversion;
	int				htag;
	int				plus;
	int				less;
	int				percentage;
	int				zero;
	int				sign_less;
	int				value_zero;
	int				space;
	char			*precision;
	int				checkprecision;
	char			*size;
	char			*flags;
	char			*string;
	char			*result;
	int				strlen;
	wchar_t		*wstring;
	int				wbit;
	int				start;
	int				end;
	struct		s_print *next;
}				t_print;

int				g_strlen;
int				g_start;
int				g_end;
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
char			*ft_itoa(intmax_t n);
char			*ft_itoa_positif(uintmax_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbr_positif(unsigned int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *s);
size_t		ft_wstrlen(const wchar_t *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_wstrcmp(wchar_t *s1, wchar_t *s2);
char			*ft_strnew(size_t size);
wchar_t		*ft_wstrnew(size_t size);


int				ft_printf(char *format, ...);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
// char			*ft_itoa_base(int nbr, char *base, int base_len, char *tab);
// int				ft_atoi_base(char *str, char *base);
void			ft_putwstr(wchar_t *s);
wchar_t			*ft_wstrdup(wchar_t *s1);
char			*ft_itobase(uintmax_t nbr, char *base);
void			ft_putwchar(wchar_t C);
char			*ft_strdup(const char *s1);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
wchar_t		*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchrstr(const char *s, char *c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_indexchr(const char *s, int c);

int				ft_manage_conversion(va_list arg, char *conversion, int i, t_print *new);
int				ft_stock_attributes(t_print *new, char *conversion, int i);
int				ft_stock_size(t_print *new, char *conversion, int i);
int				ft_stock_precision(t_print *new, char *conversion, int i);
int				ft_stock_flags(t_print *new, char *conversion, int i);

void			ft_manage_struc(va_list arg, t_print *new);
char			*kind_of_conversion(va_list arg, t_print *new);

intmax_t		ft_modify_length_di(va_list arg, t_print *new);
uintmax_t		ft_modify_length_uoxX(va_list arg, t_print *new);
char				ft_modify_length_c(va_list arg, t_print *new);

char			*htag_conversion_oxX(va_list arg, t_print *new);
char			*kind_of_precision(char *string, t_print *new);
wchar_t		*wkind_of_precision(wchar_t *string, t_print *new);

char			*add_sign(char *string, t_print *new);

char			*ft_modify_width(char *string, t_print *new);
wchar_t		*ft_modify_wwidth(wchar_t *string, t_print *new);


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

char				*htag_get_string(va_list arg, t_print *new, char *base, char *start);
char        *add_space(char *string, t_print *new);
void				ft_initialize_struct(t_print *new);
void				ft_count_bit(wchar_t C, t_print *new);
int					ft_count_bits(wchar_t *S, int size);
void				ft_add_bits(wchar_t C, t_print *new);

#endif
