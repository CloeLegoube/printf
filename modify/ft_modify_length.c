/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:48:12 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/27 12:12:42 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

intmax_t	ft_modify_length_di(va_list arg, t_print *new)
{
	intmax_t nb;
	// int 	argument;

	nb = 0;
	if (ft_strcmp(new->flags,"no-flags"))
	{
		if (!ft_strcmp(new->flags,"l"))
			nb = va_arg(arg, long);
		else if (!ft_strcmp(new->flags,"ll"))
			nb = va_arg(arg, long long);
		else if (!ft_strcmp(new->flags,"h"))
			nb = (short)va_arg(arg, int);
		else if (!ft_strcmp(new->flags,"hh"))
			nb = (signed char)va_arg(arg, int);
		else if (!ft_strcmp(new->flags,"j"))
			nb = va_arg(arg, intmax_t);
		else if (!ft_strcmp(new->flags,"z"))
			nb = va_arg(arg, size_t);
		// else if (!ft_strcmp(new->flags,"big"))
		// 	nb = (uintmax_t)va_arg(arg, uintmax_t);
		// printf("nb  == %zd ", nb);
	}
	else
		nb = (int)va_arg(arg, int);

	// printf("nb  == %jd ", nb);
	return (nb);
}

uintmax_t	ft_modify_length_uoxX(va_list arg, t_print *new)
{
	uintmax_t nb;

	nb = 0;
	if (ft_strcmp(new->flags,"no-flags"))
	{
		if (!ft_strcmp(new->flags,"l"))
			nb = va_arg(arg,unsigned long int);
		else if (!ft_strcmp(new->flags,"ll"))
			nb = va_arg(arg,unsigned long long int);
		else if (!ft_strcmp(new->flags,"h"))
			nb = (unsigned short)va_arg(arg,unsigned int);
		else if (!ft_strcmp(new->flags,"hh"))
			nb = (unsigned char)va_arg(arg, unsigned int);
		else if (!ft_strcmp(new->flags,"j"))
			nb = va_arg(arg, uintmax_t);
		else if (!ft_strcmp(new->flags,"z"))
			nb = va_arg(arg, size_t);
	}
	else
	{
		// if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'u'))
		// 	nb = (unsigned int)va_arg(arg, intmax_t);
		// else
		// nb = va_arg(arg, uintmax_t);
			nb = (unsigned int)va_arg(arg, uintmax_t);

		// if (nb > 4294967295)
		// 	nb = 0;
		// else if (nb == -1)
		// 	nb = 4294967295;
	}
	if (nb == 0)
		new->value_zero = 1;

	// printf("nb: *%ju*", nb);
	return ((uintmax_t)nb);
}

char	ft_modify_length_c(va_list arg, t_print *new)
{
	char nb;

	nb = 0;
	if (ft_strcmp(new->flags,"no-flags") && !ft_strcmp(new->flags,"l"))
		nb = va_arg(arg, wint_t);
	else
		nb = va_arg(arg, uintmax_t);
	// if (nb == 0)
	// 	new->value_zero = 1;
	// printf("nb: *%jd*", nb);
	return (nb);
}
