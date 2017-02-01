/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:48:42 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/01 15:03:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char         *conversion_duioxX(va_list arg, t_print *new)
{
	char *string;
	char *string_precision;

	string = NULL;
	string_precision = NULL;
	if(ft_strchr("oxX", new->conversion))
		string = htag_conversion_oxX(arg, new);
	else if ((new->conversion == 'd') || (new->conversion == 'i'))
		string = ft_itoa(ft_modify_length_di(arg, new));
	else if (new->conversion == 'u')
		string = ft_itoa_positif(ft_modify_length_uoxX(arg, new));
	if (new->precision && !new->htag)
		string_precision = ft_strdup(kind_of_precision(string, new));
	else
		string_precision = ft_strdup(string);
	free(string);
	// printf("string_precision: %s- ", string_precision);
	return (string_precision);
}

char         *kind_of_conversion(va_list arg, t_print *new)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	if(ft_strchr("duioxX", new->conversion))
		string = conversion_duioxX(arg, new);
	else if (new->conversion == 'c')
	{
		string = (char *)malloc(2 * sizeof(*string));
		string[0] = va_arg(arg, int);
		string[1] = '\0';
	}
	else if (new->conversion == 's')
		string = ft_strdup(va_arg(arg, char*));
	else if (new->conversion == 'p')
	{
		tmp = ft_strdup("0x");
		string = ft_strjoin(tmp, ft_itobase(va_arg(arg, uintmax_t), "0123456789abcdef"));
		free(tmp);
	}
// /***************************/
// 	else if (new->conversion == 'U')
// 		string = ft_itoa_positif((long int)(va_arg(arg,unsigned int)));
// 	else if (new->conversion == 'O')
// 		string = ft_itobase(va_arg(arg, int), "01234567");
// 	else if (new->conversion == 'D')
// 		string = ft_itoa((long int)(va_arg(arg, int)));
// /***************************/
	return (string);
}

wchar_t         *wkind_of_conversion(va_list arg, t_print *new)
{
	wchar_t *wstring;

	wstring = NULL;
	if (new->conversion == 'S')
		wstring = va_arg(arg, wchar_t *);
	else if (new->conversion == 'C')
	{
		wstring = (wchar_t *)malloc(2 * sizeof(*wstring));
		wstring[0] = va_arg(arg, int);
		wstring[1] = '\0';
	}
	return (wstring);
}
