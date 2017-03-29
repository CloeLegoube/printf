/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/29 20:18:55 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void		ft_display_string(t_print *new)
{
	size_t i;

	i = 0;
	// printf("new->value_zero: %d\n",new->value_zero);
	// printf("new->conversion: %d\n",new->conversion);
	while (i < ft_strlen(new->string))
	{
		// printf("new->string[i]: %c\n",new->string[i]);
		if ((new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'c')) &&
			new->value_zero && new->string[i] == '0')
			{
				if ((new->zero && i == ft_strlen(new->string) - 1) ||
					!new->zero)
					ft_putchar('\0');
				else
					ft_putchar(new->string[i]);
			}


		// if ((new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'c')) &&
		// 	new->value_zero && new->string[i] == '0')
		// 	{
		// 		ft_putchar('\0');
		// 	}
		else
			ft_putchar(new->string[i]);
		i++;
	}
	g_strlen += ft_strlen(new->string);
	free(new->string);
	// new->string =  NULL;

}

static	void		ft_display_wstring(t_print *new)
{
	size_t i;

	i = 0;
	while (i < ft_wstrlen(new->wstring))
	{
		if (new->value_zero && new->wstring[i] == '0')
			ft_putwchar('\0');
		else
			ft_putwchar(new->wstring[i]);
		i++;
	}
	g_strlen += new->len;
	free(new->wstring);
	// new->wstring =  NULL;
}

static	int		ft_display_last_string(char *conversion)
{
	if (g_end < (int)ft_strlen(conversion))
	{
		ft_putstr(ft_strsub(conversion, g_end,ft_strlen(conversion)));
		g_strlen += ft_strlen(ft_strsub(conversion, g_end,ft_strlen(conversion)));
	}
	return (g_strlen);
}


static	void		ft_get_the_strings(char *conversion, t_print *new)
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
		// write(1, new->string, ft_strlen(new->string));

	if (new->wstring)
	// 	write(1, new->wstring, new->size);
		ft_display_wstring(new);
}
//
// static void	ft_free_struct(t_print *new)
// {
// 	if (new->htag_prefixe)
// 	{
// 		// printf("new->htag_prefixe : %s\n", new->htag_prefixe);
// 		free(new->htag_prefixe);
// 		new->htag_prefixe = NULL;
// 	}
// 	if (new->flags)
// 	{
// 		// printf("new->flags : %s\n", new->flags);
// 		free(new->flags);
// 		new->flags = NULL;
// 	}
// 	// free(new);
// 	// new = NULL;
//
// }


int		ft_printf(char *conversion, ...)
{
	va_list  arg;
	int i;
	// int check;
	t_print	*new;

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
			// printf("g_start: %d\n",g_start);
			ft_initialize_struct(new);
			// if (conversion[i] == '\0')
			// 	return (0);

			// check = ft_manage_conversion(conversion, new);
			// printf("check: %d\n",check);

			ft_manage_conversion(conversion, new, arg);
			// if (new->conversion == 42)
			// 	new->string = ft_strdup(conversion + new->index);
				//
				// printf("\nconversion :%i\n", new->conversion);
				// printf("htag :%d\n", new->htag);
				// printf("plus :%d\n", new->plus);
				// printf("less :%d\n", new->less);
				// printf("space :%d\n", new->space);
				// printf("zero :%d\n", new->zero);
				// printf("size :%d\n", new->size);
				// printf("precision :%d\n", new->precision);
				// printf("checkprecision :%d\n", new->checkprecision);
				// printf("flags :%s\n", new->flags);
				// printf("percentage :%d\n", new->percentage);
				// printf("new->index :%d\n\n", new->index);

			ft_manage_struc(arg, new);

			// printf("new->string: *%s*\n",new->string);

			if (conversion[new->index] == '%' && conversion[new->index + 1] == 'k')
			{
				// printf("conversion[new->index]: %c\n",conversion[new->index]);
				if (conversion[new->index + 2] == 'G' && new->index++)
					new->bold = 1;
				ft_modify_color(arg, new);
				new->index += 2;
				// printf("conversion[new->index]: %c\n",conversion[new->index]);
			}

			if (new->len == -1)
				return (new->len);
			ft_get_the_strings(conversion, new);
			// printf("\nconversion :%i\n", new->conversion);
			// printf("\nconversion :%i\n", new->conversion);
			if (new->conversion == 42)
				new->index++;
			g_end = new->index;

			// printf("g_end: %d\n",g_end);
			i = new->index;
			// ft_free_struct(new);

		}
		// printf("conversion[new->index]: %c\n",conversion[new->index]);

			// printf("new->conversion: %d\n",new->conversion);

		if (conversion[i] != '%')
			i++;
	}
	va_end(arg);
	free(new);
	return (ft_display_last_string(conversion));
}
