/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:41:27 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/27 10:51:06 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int			ft_strcut_wunicode(char *string, int size)
{
	int		count;
	int		bytes;

	count = 0;
	bytes = 0;
	while (bytes <= size && ((wchar_t *)string)[count])
	{
		// printf("string:hello" );
		if (((wchar_t *)string)[count] <= 127)
			bytes += 1;
		else if (((wchar_t *)string)[count] <= 2047)
			bytes += 2;
		else if (((wchar_t *)string)[count] <= 65535)
			bytes += 3;
		else if (((wchar_t *)string)[count] <= 2097151)
			bytes += 4;
		if (bytes <= size)
			count++;
	}
	((wchar_t *)string)[count] = 0;
	return (bytes);
	// printf("unicode string2: *%S* \n", (wchar_t *)string);
}

char		*ft_modify_precision(char *string, t_print *new)
{
	// printf("(char *)string: %s", (char *)string );
	// printf("(char *)string: %s", new->string );
	void	*result;
	void	*tmp;
	int		bytes;
	int		is_wstring;
	int		is_string;
	int		(*cmp)(void *, void *);
	// printf("wstring1:*%s*\n", new->wstring);
	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S'));
	is_string = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 's'));
	cmp = is_wstring ? (int (*)(void *, void *))ft_wstrcmp : (int (*)(void *, void *))ft_strcmp;
	if (!new->htag && new->checkprecision && (-1 == new->precision || 0 == new->precision))
	{
		// printf("string: %s", string );
		if (!cmp(string, "0") || !cmp(string, ""))
			return ((char *)ft_wstrnew(0));
		new->precision = (!is_wstring && !is_string);
	}
	if (is_wstring)
		ft_strcut_wunicode(string, new->precision);
	bytes = (!is_wstring && !is_string) ? (int)ft_strlen(string) : ft_strcut_unicode(is_wstring, string, new->precision);
	// printf("bytes: %d\n", bytes );
	// printf("precision: %d\n", new->precision );
	// printf("string: %s", string );
	// printf("string: %s\n", string );
	// printf("new->precision - bytes: %d\n", new->precision - bytes);
	if (!is_wstring && !is_string && (new->precision - bytes) > 0)
	{
		result = ft_strnew(new->precision);
		ft_memset(result, '0', new->precision - bytes);
		ft_memcpy(result + new->precision - bytes, string, bytes);
		string = result;
	}
	// if (new->htag && new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'o'))
	// {
	// 	result = ft_strjoin(new->htag_prefixe, string);
	// 	// free(string);
	// 	string = result;
	// }

	// printf("wstring2:*%s*\n", new->wstring);
	return ((char *)string);
}
