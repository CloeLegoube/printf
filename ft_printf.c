/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/10 18:20:45 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

va_list        *no_conversion(va_list arg, char conversion)
{
	va_arg(arg, void*);
	ft_putchar(conversion);
	return (0);
}

va_list         *kind_of_conversion(va_list arg, char conversion)
{
	if ((conversion == 'd') || (conversion == 'i'))
		ft_putnbr(va_arg(arg, int));
	else if (conversion == 's')
		ft_putstr(va_arg(arg, char*));
	else if (conversion == 'D')
		ft_putnbr((long int)(va_arg(arg, int)));
	else if (conversion == 'S')
		ft_putwstr(va_arg(arg, wchar_t *));
	else if (conversion == 'u')
		ft_putnbr_positif(va_arg(arg, unsigned int));
	else if (conversion == 'U')
		ft_putnbr_positif(va_arg(arg, unsigned int));
	else if (conversion == 'c')
		ft_putchar(va_arg(arg, int));
	else if (conversion == 'C')
		ft_putwchar(va_arg(arg, int));
	else if (conversion == 'o' || (conversion == 'O'))
		ft_putstr(ft_itobase(va_arg(arg, int), "01234567"));
	else if (conversion == 'x')
		ft_putstr(ft_itobase(va_arg(arg, int), "0123456789abcdef"));
	else if (conversion == 'X')
		ft_putstr(ft_itobase(va_arg(arg, int), "0123456789ABCDEF"));
	else if (conversion == 'p')
	{
		ft_putstr("0x10");
		ft_putstr(ft_itobase(va_arg(arg, int), "0123456789abcdef"));
	}
	else
		 no_conversion(arg, conversion);
	return (0);
}

va_list         *flags(va_list arg, char *conversion)
{
	if (*conversion == '-' && arg < 0)
		ft_putchar('-');
	else if (*conversion == '+' && arg >= 0)
		ft_putchar('+');
	else if (*conversion == '#')
	{
		conversion++;
		if (*conversion == 'o')
			ft_putchar('0');
		if (*conversion == 'x')
			ft_putstr("0x");
		if (*conversion == 'X')
			ft_putstr("0X");
		conversion--;
	}
	else if (*conversion == ' ' && arg >= 0)
		ft_putchar(' ');
	return (0);
}

int		ft_printf(char *conversion, ...)
{
	va_list  arg;

	va_start(arg, conversion);
	while (*conversion)
	{
		if (*conversion == '%')
		{
			conversion++;
			if (*conversion == '+' || *conversion == '-' || *conversion == ' ' || *conversion == '#')
			{
				flags(arg, &*conversion);
				conversion++;
			}
			// if (*conversion >= '0' && *conversion <= '9')
			// 	conversion++;
			kind_of_conversion(arg, *conversion);
			conversion++;
			if (*conversion == '\0')
				return (0);
		}
	ft_putchar(*conversion);
	conversion++;
	}
	va_end(arg);
	return (0);
}
