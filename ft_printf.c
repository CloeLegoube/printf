/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 18:04:30 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_get_the_strings(char *conversion, t_print *new)
{
	if (g_start < g_end && g_start < (int)ft_strlen(conversion))
	{
		ft_putstr(ft_strsub(conversion, 0, g_start));
		g_strlen = ft_strlen(ft_strsub(conversion, 0, g_start));
	}
	else if (g_start > g_end && g_start < (int)ft_strlen(conversion))
	{
		ft_putstr(ft_strsub(conversion, g_end, g_start - g_end));
		g_strlen += ft_strlen(ft_strsub(conversion, g_end, g_start - g_end));
	}
	if (new->string)
		ft_display_string(new);
	if (new->wstring)
		ft_display_wstring(new);
}

static	int		ft_execute_printf(va_list arg, char *conversion, t_print *new)
{
	int		retour;

	retour = 0;
	ft_initialize_struct(new);
	ft_manage_conversion(conversion, new, arg);
	ft_manage_struc(arg, new);
	if (conversion[new->index] == '%' && conversion[new->index + 1] == 'k')
	{
		if (conversion[new->index + 2] == 'G' && new->index++)
			new->bold = 1;
		ft_modify_color(arg, new);
		new->index += 2;
	}
	if (new->len == -1)
		retour = 1;
	ft_get_the_strings(conversion, new);
	if (new->conversion == 42)
		new->index++;
	return (retour);
}

int				ft_printf(char *conversion, ...)
{
	va_list		arg;
	int			i;
	t_print		*new;

	g_strlen = 0;
	g_end = 0;
	new = (t_print*)malloc(sizeof(t_print));
	va_start(arg, conversion);
	i = 0;
	while (conversion[i])
	{
		if (conversion[i] == '%')
		{
			g_start = i;
			if (ft_execute_printf(arg, conversion, new))
				return (new->len);
			g_end = new->index;
			i = new->index;
		}
		if (conversion[i] != '%')
			i++;
	}
	va_end(arg);
	free(new);
	return (ft_display_last_string(conversion));
}
