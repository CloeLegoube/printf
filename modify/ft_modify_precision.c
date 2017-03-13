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

#include "../libftprintf.h"


char         *cut_string(int b, char *string, t_print *new)
{
		if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 's'))
			return (ft_strsub(string, 0, b));
		return (string);
}

char         *kind_of_precision(char *string, t_print *new)
{
	int a;
	int b;
	int i;
	int j;
	char *result;

	if (!ft_strcmp(new->precision, "empty") || !ft_strcmp(new->precision, "0"))
	{
		if (!ft_strcmp(string, "0") || !ft_strcmp(string, ""))
			return (ft_strdup(""));
		else if (new->conversion != ft_indexchr("sSpdDioOuUxXcC", 's'))
			new->precision = ft_strdup("1");
	}
	a = ft_strlen(string);
	b = ft_atoi(new->precision);
	if (b <= a)
		return (cut_string(b, string, new));
	result = ft_strnew(b);
	i = 0;
	j = 0;
	while (i < b - a)
		result[i++] = '0';
	while (i < b)
		result[i++] = string[j++];
	return (result);
}

wchar_t         *cut_bits(int b, wchar_t *string, t_print *new)
{
	int count;

	count = 0;
	while(new->wbit < b)
	{
		ft_add_bits(string[count], new);
		if (new->wbit <= b)
			count++;
	}
	if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S'))
		return (ft_wstrsub(string, 0, count));
	return (string);
}

wchar_t         *wkind_of_precision(wchar_t *string, t_print *new)
{
	int a;
	int b;
	int count;

	if (!ft_strcmp(new->precision, "empty") || !ft_strcmp(new->precision, "0"))
	{
		if (!ft_wstrcmp(string, L"0") || !ft_wstrcmp(string, L""))
			return (ft_wstrdup(L""));
		else if (new->conversion != ft_indexchr("sSpdDioOuUxXcC", 'S'))
			new->precision = ft_strdup("1");
	}
	b = ft_atoi(new->precision);
	count = 0;
	while(new->wbit < b)
		ft_add_bits(string[count], new);
	a = new->wbit;
	new->wbit = 0;
	if (b <= a)
		return (cut_bits(b, string, new));
	return (string);
}
