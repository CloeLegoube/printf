/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:41:27 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/23 17:10:30 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_modify_precision(char *string, t_print *new)
{
	// printf("(char *)string: %s", (char *)string );
	// printf("(char *)string: %s", new->string );
	void	*result;
	int		bytes;
	int		is_wstring;
	int		is_string;
	int		(*cmp)(void *, void *);

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
	bytes = (!is_wstring && !is_string) ? (int)ft_strlen(string) : ft_strcut_unicode(is_wstring, string, new->precision);
	// printf("bytes: %d", bytes );
	// printf("string: %s", string );
	// printf("new->precision - bytes: %d", new->precision - bytes);
	if (!is_wstring && !is_string && (new->precision - bytes) > 0)
	{
		result = ft_strnew(new->precision);
		ft_memset(result, '0', new->precision - bytes);
		ft_memcpy(result + new->precision - bytes, string, bytes);
		string = result;
	}
	return ((char *)string);
}
