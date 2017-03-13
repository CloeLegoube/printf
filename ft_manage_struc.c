/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:59:20 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/01 18:33:22 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialize_struct(t_print *new)
{
	new->conversion = 's';
	new->htag = 0;
	new->plus = 0;
	new->less = 0;
	new->percentage = 0;
	new->zero = 0;
	new->sign_less = 0;
	new->value_zero = 0;
	new->space = 0;
	new->precision = NULL;
	new->checkprecision = 0;
	new->size = NULL;
	new->flags = "no-flags";
	new->string = NULL;
	new->result = NULL;
	new->strlen = 0;
	new->wstring = NULL;
	new->wbit = 0;
	new->start = 0;
	new->end = 0;
	new->next = NULL;
}

int		ft_manage_conversion(va_list arg, char *conversion, int i, t_print	*new)
{

	while (!ft_strchr("sSpdDioOuUxXcC%", conversion[i]))
	{
		if (ft_strchr("#+-0 %.", conversion[i]))
			i = ft_stock_attributes(new,conversion, i);
		// printf("conversion1 :%c\n", conversion[i]);
		i = ft_stock_size(new,conversion, i);
		// printf("conversion2 :%c\n", conversion[i]);
		if (!new->precision)
			i = ft_stock_precision(new, conversion, i);
		// printf("conversion3 :%c\n", conversion[i]);
		i = ft_stock_flags(new, conversion, i);
		// i++;
	}
	if (ft_strchr("%", conversion[i]))
	{
			new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'c');
			new->percentage = 1;
	}
	if (ft_strchr("sSpdDioOuUxXcC", conversion[i]))
		new->conversion = ft_indexchr("sSpdDioOuUxXcC", conversion[i]);
	i++;
	// printf("\nconversion :%i\n", new->conversion);
	// printf("plus :%d\n", new->plus);
	// printf("less :%d\n", new->less);
	// printf("space :%d\n", new->space);
	// printf("precision :%s\n", new->precision);
	// printf("htag :%d\n", new->htag);
	// printf("size :%s\n", new->size);
	// printf("flags :%s\n\n", new->flags);
	ft_manage_struc(arg, new);
	// if (new->wstring)
	// 	ft_putwstr(new->wstring);
	// new->less = 0;
	return (i);
}


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

	ft_initialize_functions_tab();
	g_f[new->conversion](new, arg); // type == S_S => g_f[S_S](new, ap) => s_convertions(new, ap)


	// int i;
	// char *string;
	// wchar_t *wstring;
	// char *tmp;
	//
	// wstring = NULL;
	// string = NULL;
	// if (new->percentage)
	// 		string = ft_strdup("%");
	// else if ((new->conversion == 'C') || (new->conversion == 'S'))
	// 	wstring = wkind_of_conversion(arg, new);
	// else
	// 	string = kind_of_conversion(arg, new);
	// if (new->plus)
	// {
	// 	tmp = ft_strdup(add_sign(string, new));
	// 	free(string);
	// 	string =  ft_strdup(tmp);
	// 	free(tmp);
	// }
	// if (new->size)
	// {
	// 	if (new->less)
	// 		tmp = ft_strdup(size_of_string_less(string, new));
	// 	else
	// 		tmp = ft_strdup(size_of_string(string, new));
	// 	free(string);
	// 	string =  ft_strdup(tmp);
	// 	free(tmp);
	// }
	//
	// if (string)
	// 	new->string = ft_strdup(string);
	// else
	// 	new->string = ft_strdup((char *)wstring);



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

void				ft_initialize_functions_tab(void)
{
	g_f[s] = s_conversion;
	g_f[S] = S_conversion;
	g_f[p] = p_conversion;
	g_f[d] = d_conversion;
	g_f[D] = D_conversion;
	g_f[i] = i_conversion;
	g_f[o] = o_conversion;
	g_f[O] = O_conversion;
	g_f[u] = u_conversion;
	g_f[U] = U_conversion;
	g_f[x] = x_conversion;
	g_f[X] = X_conversion;
	g_f[c] = c_conversion;
	g_f[C] = C_conversion;

}
