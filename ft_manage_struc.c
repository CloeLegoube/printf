/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:59:20 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/06 11:49:36 by clegoube         ###   ########.fr       */
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


char	*size_of_string(char *string, t_print *new)
{
	int a;
	int b;
	int i;
	int j;
	char *result;
	result = NULL;
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
	}
	// ft_putstr("**");
	// ft_putstr(result);
	// ft_putstr("**");
	return (result);
}

char	*size_of_string_less(char *string, t_print *new)
{
	int a;
	int b;
	int i;
	int j;
	char *result;
	result = NULL;

	a = ft_strlen(string);
	b = ft_atoi(new->size);
	// ft_putnbr(a);
	// ft_putnbr(b);
	if (b > a)
	{
		result = ft_strnew(b);
		i = 0;
		j = 0;
		while (i < a)
			result[i++] = string[j++];
		j = 0;
		while (i < b)
			result[i++] = ' ';
	}
	return (result);
}


void	ft_manage_struc(va_list arg, t_print *new)
{
	// int i;
	char *string;
	wchar_t *wstring;
	char *tmp;

	wstring = NULL;
	string = NULL;
	// if (!new->conversion && new->percentage)
	// 		string = ft_strdup("%");
	if ((new->conversion == 'C') || (new->conversion == 'S'))
		wstring = wkind_of_conversion(arg, new);
	else
		string = kind_of_conversion(arg, new);
	if (new->plus)
	{
		tmp = ft_strdup(add_sign(string, new));
		free(string);
		string =  ft_strdup(tmp);
		free(tmp);
	}
	if (new->size)
	{
		if (new->less)
			tmp = ft_strdup(size_of_string_less(string, new));
		else
			tmp = ft_strdup(size_of_string(string, new));
		free(string);
		string =  ft_strdup(tmp);
		free(tmp);
	}

	if (string)
		new->string = ft_strdup(string);
	else
		new->string = ft_strdup((char *)wstring);

		// if (new->string)
		// 	ft_putstr(new->string);
	// if ((new->conversion == 'd') || (new->conversion == 'i'))
	// 	ft_putnbr(i);
	// printf("\nva_arg  : %i\n", i);
	// printf("new->htag  : %d \n", new->htag);
	// printf("new->plus  : %d \n", new->plus);
	// printf("new->less  : ``%d ***\n", new->less);
	// printf("new->space  : %d \n", new->space);
	// printf("new->zero  : %d \n", new->zero);
	// printf("new->precision  : %s \n", new->precision);
	// printf("\nnew->conversion  : %c \n", new->conversion);
	// printf("new->size  : %s \n", new->size);
	// printf("new->flags  : %s \n", new->flags);
}
