/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_htag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/23 13:11:29 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*htag_get_string(va_list arg, t_print *new, char *base, char *start)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	string = ft_itobase(ft_modify_length_uoxX(arg, new), base);
	if (new->precision)
		tmp = ft_strdup(kind_of_precision(string, new));
	else
		tmp =ft_strdup(string);
	free(string);
	string = ft_strdup(tmp);
	free(tmp);
	if (new->htag)
	{
		tmp = ft_strjoin(start, string);
		free(string);
		string = ft_strdup(tmp);
		free(tmp);
	}
	return (string);
}


char	*htag_conversion_oxX(va_list arg, t_print *new)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	if (new->conversion == 'o')
		string  = htag_get_string(arg, new, "01234567", "0");
	else if (new->conversion == 'x')
		string  = htag_get_string(arg, new, "0123456789abcdef", "0x");
	else if (new->conversion == 'X')
		string  = htag_get_string(arg, new, "0123456789ABCDEF", "0X");
	return (string);
}
