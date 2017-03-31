/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_htag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 11:32:57 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		init_htag_prefixe(t_print *new, char *string)
{
	if (new->value_zero)
	{
		if (new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'o')
			&& !new->precision)
			new->htag_prefixe = ft_strdup("");
		else
			new->htag_prefixe = ft_strdup("0");
	}
	else if (new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'o') &&
			new->checkprecision && new->precision < ft_strlen(string))
		new->htag_prefixe = ft_strdup("0");
}

static void		add_zero_before_if_zero(t_print *new, char **string)
{
	char	*tmp;

	tmp = NULL;
	if (new->value_zero)
	{
		if ((!new->htag) || (new->htag &&
			new->conversion == ft_indexchr("sSpdDioOuUxXcCb", 'o')))
		{
			tmp = ft_strdup("0");
			free(*string);
			*string = ft_strdup(tmp);
			free(tmp);
		}
	}
}

static void		add_htag_prefixe(t_print *new, char **string)
{
	char *tmp;

	tmp = NULL;
	if ((!new->precision) || (new->precision && !new->value_zero
				&& new->conversion != ft_indexchr("sSpdDioOuUxXcCb", 'o')))
	{
		tmp = ft_strjoin(new->htag_prefixe, *string);
		free(*string);
		free(new->htag_prefixe);
		*string = ft_strdup(tmp);
		free(tmp);
		new->htag_prefixe = "no";
	}
}

char			*ft_modify_htag(va_list arg, t_print *new, char *base)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	string = ft_itobase(ft_modify_length_uoxx(arg, new), base);
	init_htag_prefixe(new, string);
	add_zero_before_if_zero(new, &string);
	tmp = (new->precision && new->precision != -1) ?
			ft_strdup(ft_modify_precision(string, new)) : ft_strdup(string);
	free(string);
	string = ft_strdup(tmp);
	free(tmp);
	if (new->htag && !new->zero)
		add_htag_prefixe(new, &string);
	new->safe = 1;
	return (string);
}
