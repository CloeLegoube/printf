/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/06 11:47:07 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialize_struct(t_print *new)
{
	new->conversion = '\0';
	new->htag = 0;
	new->plus = 0;
	new->less = 0;
	new->percentage = 0;
	new->zero = 0;
	new->value_zero = 0;
	new->space = 0;
	new->precision = NULL;
	new->size = NULL;
	new->flags = "no-flags";
	new->string = NULL;
	new->wstring = NULL;
	new->start = 0;
	new->end = 0;
}

void	ft_move_conversion(t_print *new)
{
	if (new->conversion == 'D')
	{
		new->conversion = 'd';
		new->flags = "l";
	}
	if (new->conversion == 'O')
	{
		new->conversion = 'o';
		new->flags = "l";
	}
	if (new->conversion == 'U')
	{
		new->conversion = 'u';
		new->flags = "l";
	}
}


int		ft_manage_conversion(va_list arg, char *conversion, int i, t_print	*new)
{
	// int i;

	// while ( !ft_strchrstr("sSpdDioOuUxXcC%-", conversion))
	while ( !ft_strchr("sSpdDioOuUxXcC%", conversion[i]))
		// || !ft_strchr("#+-0 %.", conversion[i])
		// || !ft_strchr("lhjz", conversion[i])
		// || (conversion[i] > '0' && conversion[i] <= '9'))
	{
		// printf("conversion0 :%c\n", conversion[i]);
		i = ft_stock_attributes(new,conversion, i);
		// ft_putchar(conversion[i]);
		// printf("conversion1 :%c\n", conversion[i]);
		if (!new->size)
			i = ft_stock_size(new, conversion, i);
		// i = ft_stock_size(new,conversion, i);
		// printf("conversion2 :%c\n", conversion[i]);
		if (!new->precision)
			i = ft_stock_precision(new, conversion, i);
		// printf("conversion3 :%c\n", conversion[i]);
		i = ft_stock_flags(new, conversion, i);
		// i++;
	}

	ft_putchar(conversion[i]);

	// printf("conversion :%c\n", conversion [i]);
	if (ft_strchr("sSpdDioOuUxXcC%", conversion[i]))
		new->conversion = conversion[i];
	ft_putstr("test");
	i++;
	ft_putchar(new->conversion);
	printf("\nconversion :%c\n", new->conversion);
	// printf("plus :%d\n", new->plus);
	// printf("less :%d\n", new->less);
	// printf("percentage :%d\n", new->percentage);
	// printf("precision :%s\n", new->precision);
	// printf("htag :%d\n", new->htag);
	printf("size :%s\n\n", new->size);
	// arg = NULL;
	// printf("\nconversion :%c\n", new->conversion);
	// printf("\nflags :%s\n", new->flags);
	ft_move_conversion(new);
	// arg = NULL;
	ft_manage_struc(arg, new);
	// if (new->wstring)
	// 	ft_putwstr(new->wstring);
	// new->less = 0;
	return (i);
}

int		ft_get_the_string(char *conversion, t_print *new)
{
	char *string;
	char *tmp;

	string = NULL;
	printf("%d", new->start);
	printf("%d", new->end);
	if ((new->start == 0 && new->end == 0) || (!new->string))
		string = ft_strdup(conversion);
	else if (new->percentage)
		string = ft_strjoin(ft_strsub(conversion, 1, new->start), new->string);
	else
	{
		string = ft_strjoin(ft_strsub(conversion, 0, new->start), new->string);
		tmp = ft_strdup(string);
		free(string);
		string = ft_strjoin(tmp, ft_strsub(conversion, new->end, ft_strlen(conversion)));
		// ft_putstr("*");
		// ft_putstr(string);
		// ft_putstr("*");
	}
	ft_putstr(string);
	return (ft_strlen(string));
}

int		ft_printf(char *conversion, ...)
{
	va_list  arg;
	int i;
	t_print	*new;

	new = (t_print*)malloc(sizeof(t_print));
	ft_initialize_struct(new);
	va_start(arg, conversion);
	i = 0;
	while (conversion[i])
	{

		if (conversion[i] == '%')
		{
			ft_putstr("hello\n");
			// if (conversion[i + 1] == '%')
			// {
			// 	ft_putchar('%');
			// 	return (1);
			// }
			// else
			// {
				new->start = i;
				i++;
				if (conversion[i] == '\0')
					return (0);

				i = ft_manage_conversion(arg, conversion, i, new);

				new->end = i;
			// }
		}
		i++;
	}
	va_end(arg);
	return (ft_get_the_string(conversion, new));
}
