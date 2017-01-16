/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:59:20 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 17:49:57 by clegoube         ###   ########.fr       */
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

char         *kind_of_conversion(va_list arg, t_print *new)
{
	char *string;
	char *tmp;

	string = NULL;
	tmp = NULL;
	if ((new->conversion == 'd') || (new->conversion == 'i'))
		string = ft_itoa(ft_modify_length_di(arg, new));
/***************************/
	else if (new->conversion == 'u')
		string = ft_itoa_positif(ft_modify_length_uoxX(arg, new));
	else if (new->conversion == 'o')
		string = ft_itobase(ft_modify_length_uoxX(arg, new), "01234567");
	else if (new->conversion == 'x')
		string = ft_itobase(ft_modify_length_uoxX(arg, new), "0123456789abcdef");
	else if (new->conversion == 'X')
		string = ft_itobase(ft_modify_length_uoxX(arg, new), "0123456789ABCDEF");
/***************************/
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
	// wchar_t wchar;
	//
	// i = va_arg(arg, int);
	wstring = NULL;
	string = NULL;
	if ((new->conversion == 'C') || (new->conversion == 'S'))
		wstring = wkind_of_conversion(arg, new);
	else
		string = kind_of_conversion(arg, new);
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
