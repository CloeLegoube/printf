/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_htag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/30 17:47:32 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*htag_get_string(va_list arg, t_print *new, char *base, char *start)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	string = ft_itobase(ft_modify_length_uoxX(arg, new), base);
	if (new->value_zero)
		start = ft_strdup("0");
	if (!new->htag && new->value_zero)
	{
		tmp = ft_strdup("0");
		free(string);
		string = ft_strdup(tmp);
		free(tmp);
	}
	if (new->precision)
		tmp = ft_strdup(kind_of_precision(string, new));
	else
		tmp =ft_strdup(string);
	free(string);
	string = ft_strdup(tmp);
	free(tmp);
	if ((new->htag && !new->precision ) ||
			(new->htag && new->precision && !new->value_zero
			&& new->conversion != ft_indexchr("sSpdDioOuUxXcC", 'o')))
	{
		tmp = ft_strjoin(start, string);
		free(string);
		string = ft_strdup(tmp);
		free(tmp);
	}
	// printf("string: %s", new->string );
	//   printf("value_zero: %d", new->value_zero );
	return (string);
}


// char	*htag_conversion_oxX(va_list arg, t_print *new)
// {
// 	char *string;
// 	// char *tmp;
//
// 	string = NULL;
// 	// tmp = NULL;
// 	if (new->conversion == 'o')
// 		string  = htag_get_string(arg, new, "01234567", "0");
// 	else if (new->conversion == 'x')
// 			string  = htag_get_string(arg, new, "0123456789abcdef", "0x");
// 	else if (new->conversion == 'X')
// 		string  = htag_get_string(arg, new, "0123456789ABCDEF", "0X");
// 	return (string);
// }
