/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:41:27 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/23 11:45:50 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char         *kind_of_precision(char *string, t_print *new)
{
	int a;
	int b;
	int i;
	int j;
	char *result;
	if (!ft_strcmp(new->precision, "empty"))
	{
		if (!ft_strcmp(string, "0"))
			return (ft_strdup(""));
		else
			return (string);
	}
	a = ft_strlen(string);
	b = ft_atoi(new->precision);
	if (b <= a)
		return (string);
	result = ft_strnew(b);
	i = 0;
	j = 0;
	while (i < b - a)
		result[i++] = '0';
	while (i < b)
		result[i++] = string[j++];
	return (result);
}
