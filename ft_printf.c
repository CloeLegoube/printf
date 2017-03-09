/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/09 17:59:14 by clegoube         ###   ########.fr       */
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
	new->value_zero = 0;
	new->space = 0;
	new->precision = NULL;
	new->size = NULL;
	new->flags = "no-flags";
	new->string = NULL;
	new->result = NULL;
	new->strlen = 0;
	new->wstring = NULL;
	new->start = 0;
	new->end = 0;
	new->next = NULL;
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

	while (!ft_strchr("sSpdDioOuUxXcC%", conversion[i]))
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
	if (ft_strchr("%", conversion[i]))
	{
			new->conversion = 'c';
			new->percentage = 1;
	}
	if (ft_strchr("sSpdDioOuUxXcC", conversion[i]))
		new->conversion = conversion[i];
	i++;
	// printf("\nconversion :%c\n", new->conversion);
	// printf("plus :%d\n", new->plus);
	// printf("less :%d\n", new->less);
	// printf("precision :%s\n", new->precision);
	// printf("htag :%d\n", new->htag);
	// printf("size :%s\n\n", new->size);
	// arg = NULL;
	// printf("\nconversion :%c\n", new->conversion);
	// printf("\nflags :%s\n", new->flags);
	ft_move_conversion(new);
	ft_manage_struc(arg, new);
	// if (new->wstring)
	// 	ft_putwstr(new->wstring);
	// new->less = 0;
	return (i);
}

void		ft_get_the_string(char *conversion, t_print *new)
{
	char *tmp;
	char *tmp2;

	if (g_result == NULL)
		g_result = ft_strjoin(ft_strsub(conversion, 0, new->start), new->string);
	else
	{
		tmp = ft_strdup(g_result);
		tmp2 = ft_strjoin(ft_strsub(conversion, new->end, new->start - new->end), new->string);
		g_result = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
}

void		ft_display_string(char *conversion, t_print *new)
{
	char *tmp;

	tmp = ft_strdup(g_result);
	free(g_result);
	g_result = ft_strjoin(tmp, ft_strsub(conversion, new->end, ft_strlen(conversion)));
	g_strlen = ft_strlen(g_result);
	ft_putstr(g_result);
}

int		ft_printf(char *conversion, ...)
{
	va_list  arg;
	int i;
	t_print	*new;

	new = NULL;
	g_result =  NULL;
	g_strlen = 0;
	new = (t_print*)malloc(sizeof(t_print));
	ft_initialize_struct(new);
	va_start(arg, conversion);
	i = 0;
	while (conversion[i])
	{
		if (conversion[i] == '%')
		{
			new->start = i;
			i++;
			if (conversion[i] == '\0')
				return (0);
			i = ft_manage_conversion(arg, conversion, i, new);
			ft_get_the_string(conversion, new);
			new->end = i;
		}
		i++;
	}
	va_end(arg);
	ft_display_string(conversion, new);
	return (g_strlen);
}


// void				(*g_f[101])(t_args*, va_list);
// void				ft_array_fun(void);
// void				s_convertion(t_args *new, va_list ap);
// void				bs_convertion(t_args *new, va_list ap);
// void				p_convertion(t_args *new, va_list ap);
//
// g_f[new->type](new, ap); // type == S_S => g_f[S_S](new, ap) => s_convertions(new, ap)
