/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:19:13 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/28 18:48:49 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_stock_attributes(t_print *new, char *conversion, va_list arg)
{
	if (conversion[new->index]== '#' && new->index++)
		new->htag = 1;
	if (conversion[new->index] == '+' && new->index++)
		new->plus = 1;
	if (conversion[new->index] == '-' && new->index++)
		new->less = 1;
	if (conversion[new->index] == '0' && new->index++)
		new->zero = 1;
	if (conversion[new->index] == ' ' && new->index++)
		new->space = 1;
	// if (conversion[new->index] == '%' && new->index++)
	// 	new->percentage = 1;
	if (conversion[new->index] == '.')
		ft_stock_precision(new, conversion, arg);
}

void		ft_stock_size(t_print *new, char *conversion, va_list arg)
{
	int		tmp;
	// printf("conversion[new->index]:%c", conversion[i + 1]);
	if (conversion[new->index] == '*' && new->index++)
	{
		new->size = va_arg(arg, uintmax_t);
		if (new->size < 0)
		{
			new->size = new->size * -1;
			new->less = 1;
		}
	}

	else if(conversion[new->index] > '0' && conversion[new->index] <= '9')
	{
		tmp = new->index;
		while(conversion[new->index] >= '0' && conversion[new->index] <= '9')
			new->index++;
		new->size = ft_atoi(conversion + tmp);//ft_strsub(conversion, tmp, i - tmp);
		// printf("TAILLE:%s", new->size);
	}

}

void		ft_stock_precision(t_print *new, char *conversion, va_list arg)
{
	int tmp;


	if (conversion[new->index] == '.' && new->index++)
	{
		new->checkprecision = 1;
		tmp = new->index;
		if (conversion[new->index] == '*'  && new->index++)
		{
			new->precision = va_arg(arg, uintmax_t);
			if (new->precision < 0)
			{
				new->precision = 0;
				new->checkprecision = 0;
			}
		}

		else if (conversion[new->index]  < '0' || conversion[new->index] > '9')
			new->precision = -1;
		else
		{
			while(conversion[new->index] >= '0' && conversion[new->index] <= '9')
				new->index++;
			new->precision = ft_atoi(conversion + tmp);
		}
	}

	// printf("PRECISION :%s\n", new->precision);
	// printf("conversion[new->index] :%c\n", conversion[new->index]);
	// if (new->size)
	// 	new->index++;
	// new->index--;
}

void		ft_stock_flags(t_print *new, char *conversion)
{

	if (ft_strchr("hljz", conversion[new->index]))
	{
		if (!ft_strcmp(new->flags, "no-flags") || !ft_strcmp(new->flags, "h")
			|| !ft_strcmp(new->flags, "hh"))
		{
			if (conversion[new->index] == 'l' && new->index++)
			{
				if (conversion[new->index] == 'l' && new->index++)
					new->flags = "ll";
				else
					new->flags = "l";
			}
			else if (conversion[new->index] == 'h' && new->index++)
			{
				if (conversion[new->index] == 'h' && new->index++)
					new->flags = "hh";
				else
					new->flags = "h";
			}
			else if (conversion[new->index] == 'j' && new->index++)
				new->flags = "j";
			else if (conversion[new->index] == 'z' && new->index++)
				new->flags = "z";
		}
		else
			new->index++;
	}



}
