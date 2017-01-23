/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/23 14:24:00 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// va_list        *no_conversion(va_list arg, char conversion)
// {
// 	va_arg(arg, void*);
// 	ft_putchar(conversion);
// 	return (0);
// }
//
// va_list         *kind_of_conversion(va_list arg, char conversion)
// {
// 	if ((conversion == 'd') || (conversion == 'i'))
// 		ft_putnbr(va_arg(arg, int));
// 	else if (conversion == 's')
// 		ft_putstr(va_arg(arg, char*));
// 	else if (conversion == 'D')
// 		ft_putnbr((long int)(va_arg(arg, int)));
// 	else if (conversion == 'S')
// 		ft_putwstr(va_arg(arg, wchar_t *));
// 	else if (conversion == 'u')
// 		ft_putnbr_positif(va_arg(arg, unsigned int));
// 	else if (conversion == 'U')
// 		ft_putnbr_positif(va_arg(arg, unsigned int));
// 	else if (conversion == 'c')
// 		ft_putchar(va_arg(arg, int));
// 	else if (conversion == 'C')
// 		ft_putwchar(va_arg(arg, int));
// 	else if (conversion == 'o' || (conversion == 'O'))
// 		ft_putstr(ft_itobase(va_arg(arg, int), "01234567"));
// 	else if (conversion == 'x')
// 		ft_putstr(ft_itobase(va_arg(arg, int), "0123456789abcdef"));
// 	else if (conversion == 'X')
// 		ft_putstr(ft_itobase(va_arg(arg, int), "0123456789ABCDEF"));
// 	else if (conversion == 'p')
// 	{
// 		ft_putstr("0x10");
// 		ft_putstr(ft_itobase(va_arg(arg, int), "0123456789abcdef"));
// 	}
// 	else
// 		 no_conversion(arg, conversion);
// 	return (0);
// }
//
// va_list         *flags(va_list arg, char *conversion)
// {
// 	if (*conversion == '-' && arg < 0)
// 		ft_putchar('-');
// 	else if (*conversion == '+' && arg >= 0)
// 		ft_putchar('+');
// 	else if (*conversion == '#')
// 	{
// 		conversion++;
// 		if (*conversion == 'o')
// 			ft_putchar('0');
// 		if (*conversion == 'x')
// 			ft_putstr("0x");
// 		if (*conversion == 'X')
// 			ft_putstr("0X");
// 		conversion--;
// 	}
// 	else if (*conversion == ' ' && arg >= 0)
// 		ft_putchar(' ');
// 	return (0);
// }

void	ft_initialize_struct(t_print *new)
{
	new->conversion = '\0';
	new->htag = 0;
	new->plus = 0;
	new->less = 0;
	new->percentage = 0;
	new->zero = 0;
	new->space = 0;
	new->precision = NULL;
	new->size = NULL;
	new->flags = NULL;
}

int		ft_manage_conversion(va_list arg, char *conversion, int i)
{
	t_print	*new;

	new = (t_print*)malloc(sizeof(t_print));
	ft_initialize_struct(new);
	while (!ft_strchr("sSpdDioOuUxXcC", conversion[i]))
	{
		i = ft_stock_attributes(new,conversion, i);
		// printf("conversion1 :%c\n", conversion[i]);
		i = ft_stock_size(new,conversion, i);
		// printf("conversion2 :%c\n", conversion[i]);
		if (!new->precision)
			i = ft_stock_precision(new, conversion, i);
		// printf("conversion3 :%c\n", conversion[i]);
		i = ft_stock_flags(new, conversion, i);
		// i++;
	}
	// printf("conversion :%c\n", conversion [i]);
	if(ft_strchr("sSpdDioOuUxXcC", conversion[i]))
		new->conversion = conversion[i];
	i++;
	// printf("\nconversion :%c\n", new->conversion);
	// printf("plus :%d\n", new->plus);
	// printf("less :%d\n", new->less);
	// printf("precision :%s\n", new->precision);
	// printf("htag :%d\n", new->htag);
	// printf("size :%s\n\n", new->size);
	// arg = NULL;
	ft_manage_struc(arg, new);
	// new->less = 0;
	return (i);
}

int		ft_printf(char *conversion, ...)
{
	va_list  arg;
	int i;

	va_start(arg, conversion);
	i = 0;
	while (conversion[i])
	{
		if (conversion[i] == '%')
		{
			i++;
			if (conversion[i] == '\0')
				return (0);
			i = ft_manage_conversion(arg, conversion, i);
		}
		ft_putchar(conversion[i]);
		i++;
	}
	va_end(arg);
	return (0);
}
