/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/30 17:50:53 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_stock_attributes(t_print *new, char *conversion, int i)
{
	if (conversion[i]== '#')
		new->htag = 1;
	if (conversion[i] == '+')
		new->plus = 1;
	if (conversion[i] == '-')
		new->less = 1;
	if (conversion[i] == '0')
		new->zero = 1;
	if (conversion[i] == ' ')
		new->space = 1;
	if (conversion[i] == '%')
		new->percentage = 1;
	if (conversion[i] == '.')
		i = ft_stock_precision(new, conversion, i);
	i++;
	return (i);
}

int		ft_stock_size(t_print *new, char *conversion, int i)
{
	int		tmp;
	// printf("conversion[i]:%c", conversion[i]);
	if(conversion[i] > '0' && conversion[i] <= '9')
	{
		tmp = i;

		while(conversion[i] >= '0' && conversion[i] <= '9')
			i++;
		new->size = ft_strsub(conversion, tmp, i - tmp);
		// printf("TAILLE:%s", new->size);
	}
	return (i);
}

int		ft_stock_precision(t_print *new, char *conversion, int i)
{
	int tmp;

	if (conversion[i] == '.')
	{
		i++;
		tmp = i;
		if (conversion[i]  < '0' || conversion[i] > '9')
			new->precision = ft_strdup("empty");
		else
		{
			while(conversion[i] >= '0' && conversion[i] <= '9')
				i++;
			new->precision = ft_strsub(conversion, tmp, i - tmp);
		}
		// printf("PRECISION :%s\n", new->precision);
		// printf("conversion[i] :%c\n", conversion[i]);
		if (new->size)
			i++;
		i--;

	}
	return (i);
}

int		ft_stock_flags(t_print *new, char *conversion, int i)
{
	if (conversion[i] == 'l')
	{
		i++;
		if (conversion[i] == 'l')
			new->flags = "ll";
		else
		{
			conversion--;
			new->flags = "l";
		}
	}
	if (conversion[i] == 'h')
	{
		i++;
		if (conversion[i] == 'h')
			new->flags = "hh";
		else
		{
			conversion--;
			new->flags = "h";
		}
	}
	if (conversion[i] == 'j')
		new->flags = "j";
	if (conversion[i] == 'z')
		new->flags = "z";

	return (i);
}
