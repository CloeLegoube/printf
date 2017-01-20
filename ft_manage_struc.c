/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:59:20 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/20 19:40:14 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


// char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
// {
// 	unsigned	int	i;
// 	char			*fresh_string;
//
// 	i = 0;
// 	if (!s || !f)
// 		return (NULL);
// 	fresh_string = (char *)malloc((ft_strlen(s) + 1) * sizeof(*fresh_string));
// 	if (fresh_string == NULL)
// 		return (NULL);
// 	while (*(char *)(s + i))
// 	{
// 		fresh_string[i] = f(i, *(char *)(s + i));
// 		i++;
// 	}
// 	fresh_string[i] = '\0';
// 	return (fresh_string);
// }

// wchar_t         wconversion_char(va_list arg, char conversion)
// {
// 	wchar_t wchar;
//
// 	wstring = NULL;
// 	if (conversion == 'S')
// 		wstring = va_arg(arg, wchar_t *);
// 	else if (conversion == 'C')
// 		wchar = (wchar_t *)(ft_itoa(va_arg(arg, int)));
// 	return (wchar);
// }
//


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

void	size_of_string(char *string, t_print *new)
{
	int a;
	int b;
	int i;
	int j;
	char *result;
	a = ft_strlen(string);
	b = ft_atoi(new->size);
	if (b > a)
	{
		result = ft_strnew(b);
		i = 0;
		j = 0;
		while (i < b - a)
			result[i++] = ' ';
		while (i < b)
			result[i++] = string[j++];
		free(string);
		string = ft_strdup(result);
	}
}

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

char         *conversion_duioxX(va_list arg, t_print *new)
{
	char *string;
	char *string_precision;

	string = NULL;
	string_precision = NULL;
	if ((new->conversion == 'd') || (new->conversion == 'i'))
		string = ft_itoa(ft_modify_length_di(arg, new));
	else if (new->conversion == 'u')
		string = ft_itoa_positif(ft_modify_length_uoxX(arg, new));
	else if (new->conversion == 'o')
		string = ft_itobase(ft_modify_length_uoxX(arg, new), "01234567");
	else if (new->conversion == 'x')
		string = ft_itobase(ft_modify_length_uoxX(arg, new), "0123456789abcdef");
	else if (new->conversion == 'X')
		string = ft_itobase(ft_modify_length_uoxX(arg, new), "0123456789ABCDEF");
	if (new->precision)
		string_precision = ft_strdup(kind_of_precision(string, new));
	else
		string_precision = ft_strdup(string);
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
		tmp = ft_strdup("0x10");
		string = ft_strjoin(tmp, ft_itobase(va_arg(arg, int), "0123456789abcdef"));
		free(tmp);
	}
/***************************/
	else if (new->conversion == 'U')
		string = ft_itoa_positif((long int)(va_arg(arg,unsigned int)));
	else if (new->conversion == 'O')
		string = ft_itobase(va_arg(arg, int), "01234567");
	else if (new->conversion == 'D')
		string = ft_itoa((long int)(va_arg(arg, int)));
/***************************/
	return (string);
}


void	ft_manage_struc(va_list arg, t_print *new)
{
	// int i;
	char *string;
	wchar_t *wstring;

	wstring = NULL;
	string = NULL;
	if ((new->conversion == 'C') || (new->conversion == 'S'))
		wstring = wkind_of_conversion(arg, new);
	else
	{
		string = kind_of_conversion(arg, new);
		if (new->size)
			size_of_string(string, new);
	}

	if (string)
		ft_putstr(string);
	else
		ft_putwstr(wstring);


	// if ((new->conversion == 'd') || (new->conversion == 'i'))
	// 	ft_putnbr(i);
	// printf("\nva_arg  : %i\n", i);
	// printf("new->htag  : %d \n", new->htag);
	// printf("new->plus  : %d \n", new->plus);
	// printf("new->less  : %d \n", new->less);
	// printf("new->space  : %d \n", new->space);
	// printf("new->zero  : %d \n", new->zero);
	// printf("new->precision  : %s \n", new->precision);
	// printf("\nnew->conversion  : %c \n", new->conversion);
	// printf("new->size  : %s \n", new->size);
	// printf("new->flags  : %s \n", new->flags);
}
