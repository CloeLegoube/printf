/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/01 18:35:26 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_string(t_print *new, size_t i)
{
	// ft_putstr("string :: ");
	// ft_putnbr_positif(ft_strlen(new->string));
	// printf("string: %s", new->string);
	// printf("ft_strlen(new->string): %li", ft_strlen(new->string));
	// printf("i ==: %li", i);
	// printf("new->string[i] ==: %c",new->string[i]);
	// 		printf("new->string ==: %s",new->string);
			// new->value_zero = 0;
	while (i < ft_strlen(new->string))
	{
		if ((new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'c')) &&
				new->value_zero && new->string[i] == '0')
		{
			// if (ft_strlen(new->string) == 1)
			// 	ft_putchar('0');
			// else
				ft_putchar('\0');
		}
		else
			ft_putchar(new->string[i]);
		i++;
	}
	// ft_putstr("<");
	// ft_putstr(new->string);
	// ft_putstr(">");

	g_strlen += ft_strlen(new->string);
	new->string =  NULL;
	free(new->string);
}

void		ft_display_wstring(t_print *new, size_t i)
{
	// ft_putstr("wstring :: ");
	while (i < ft_wstrlen(new->wstring))
	{
		if (new->value_zero && new->wstring[i] == '0')
			ft_putwchar('\0');
		else
			ft_putwchar(new->wstring[i]);
		i++;
	}
	g_strlen += ft_wstrlen(new->wstring);
	new->wstring =  NULL;
	free(new->wstring);
}

int		ft_display_last_string(char *conversion)
{
	ft_putstr(ft_strsub(conversion, g_end,ft_strlen(conversion)));
	g_strlen += ft_strlen(ft_strsub(conversion, g_end,ft_strlen(conversion)));
	return (g_strlen);
}


void		ft_get_the_strings(char *conversion, t_print *new)
{
	size_t i;

	if (g_start < g_end)
	{
		ft_putstr(ft_strsub(conversion, 0, g_start));
		g_strlen = ft_strlen(ft_strsub(conversion, 0, g_start));
	}
	else
	{
		ft_putstr(ft_strsub(conversion, g_end, g_start - g_end));
		g_strlen += ft_strlen(ft_strsub(conversion, g_end, g_start - g_end));
	}
	i = 0;
	if (new->string)
		ft_display_string(new, i);
	if (new->wstring)
		ft_display_wstring(new, i);
}



// void		ft_display_string(char *conversion, t_print *new)
// {
// 	char *tmp;
// 	int i;
//
// 	tmp = ft_strdup(g_result);
// 	free(g_result);
// 	g_result = ft_strjoin(tmp, ft_strsub(conversion, g_end, ft_strlen(conversion)));
// 	g_strlen = ft_strlen(g_result);
//  	i = 0;
// 	while (i < g_strlen)
// 	{
// 		if (new->value_zero && g_result[i] == '0')
// 			ft_putchar('\0');
// 		else
// 			ft_putchar(g_result[i]);
// 		i++;
// 	}
// }

int		ft_printf(char *conversion, ...)
{
	va_list  arg;
	int i;
	t_print	*new;

	g_strlen = 0;
	new = (t_print*)malloc(sizeof(t_print));
	va_start(arg, conversion);
	i = 0;
	while (conversion[i])
	{
		if (conversion[i] == '%')
		{
			g_start = i;
			ft_initialize_struct(new);
			i++;
			if (conversion[i] == '\0')
				return (0);
			i = ft_manage_conversion(arg, conversion, i, new);
			ft_get_the_strings(conversion, new);
			g_end = i;
		}
		i++;
	}
	va_end(arg);
	free(new);
	return (ft_display_last_string(conversion));
}


// void				(*g_f[101])(t_print*, va_list);
// void				ft_initialize_functions_tab(void);
// void				s_convertion(t_print *new, va_list arg);
// void				bs_convertion(t_print *new, va_list arg);
// void				p_convertion(t_print *new, va_list arg);
//
// g_f[new->type](new, ap); // type == S_S => g_f[S_S](new, ap) => s_convertions(new, ap)
