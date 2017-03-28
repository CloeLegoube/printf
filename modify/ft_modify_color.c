/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:48:42 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/28 21:11:35 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"


void	ft_modify_color(va_list arg, t_print *new)
{
	char *tmp;
	char *code;
	char *color;

	color = ft_itoa((intmax_t)va_arg(arg, char *));
	code = ft_strdup("\033[");
	tmp = ft_strdup(ft_strcat(ft_strcat(ft_strcat(ft_strcat(code, color), "m"), new->string), "\033[0m"));
	free(new->string);
	new->string = ft_strdup(tmp);
}
