/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:21:44 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/07 19:15:17 by clegoube         ###   ########.fr       */
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
# include <strings.h>

# include <limits.h>
# include <locale.h>


int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbr_positif(unsigned int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);


int				ft_printf(char *format, ...);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
// char			*ft_itoa_base(int nbr, char *base, int base_len, char *tab);
// int				ft_atoi_base(char *str, char *base);
void			ft_putwstr(wchar_t *s);
char			*ft_itobase(int nbr, char *base);
void			ft_putwchar(wchar_t C);
char			*ft_strdup(const char *s1);

#endif
