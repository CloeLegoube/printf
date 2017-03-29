/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_htag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/29 13:44:45 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_modify_htag(va_list arg, t_print *new, char *base)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	string = ft_itobase(ft_modify_length_uoxX(arg, new), base);
	// printf("stringhtag1:%s\n", string);
	if (new->value_zero)
	{
		if (new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'o') && !new->precision)
			new->htag_prefixe = ft_strdup("");
		else
			new->htag_prefixe = ft_strdup("0");
		// if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'o'))
		// 	new->value_zero = 0;
	}

	if (new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'o') &&
		new->checkprecision && new->precision < ft_strlen(string))
			new->htag_prefixe = ft_strdup("0");
	if ((!new->htag && new->value_zero) ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'o') &&
		new->htag && new->value_zero))
	{
		tmp = ft_strdup("0");
		free(string);
		string = ft_strdup(tmp);
		free(tmp);
	}
	// printf("new->precision:%d\n", new->precision);
	if (new->precision && new->precision != -1)
		tmp = ft_strdup(ft_modify_precision(string, new));
	else
		tmp =ft_strdup(string);
	free(string);
	string = ft_strdup(tmp);
	free(tmp);
	// printf("stringhtag2:%s\n", string);
	if ((new->htag && !new->precision && !new->zero ) ||
		(new->htag && new->precision && !new->zero && !new->value_zero
		&& new->conversion != ft_indexchr("sSpdDioOuUxXcCb", 'o')))
	{
		tmp = ft_strjoin(new->htag_prefixe, string);
		free(string);
		free(new->htag_prefixe);
		string = ft_strdup(tmp);
		free(tmp);
		new->htag_prefixe = ft_strdup("no");
	}
	// printf("stringhtag3: %s", string );
	//   printf("value_zero: %d", new->value_zero );
	return (string);
}
