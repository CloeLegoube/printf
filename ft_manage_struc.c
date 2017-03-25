/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 10:59:20 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/25 14:19:28 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_initialize_struct(t_print *new)
{
	new->conversion = 42;
	new->htag = 0;
	new->htag_prefixe = ft_strdup("no");
	new->plus = 0;
	new->less = 0;
	new->percentage = 0;
	new->zero = 0;
	new->sign_less = 0;
	new->value_zero = 0;
	new->space = 0;
	new->precision = 0;
	new->checkprecision = 0;
	new->size = 0;
	new->flags = ft_strdup("no-flags");
	new->string = NULL;
	new->result = NULL;
	new->strlen = 0;
	new->wstring = NULL;
	new->wbyte = 0;
	new->len = 0;
	new->index = g_start + 1;
	// new->start = 0;
	// new->end = 0;
	new->next = NULL;
}

void	ft_manage_struc(va_list arg, t_print *new)
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
	g_f[Q] = no_conversion;
	g_f[new->conversion](new, arg);
	// if (!new->size && new->string)
	// 	new->size = ft_strlen(new->string);
	// else if (!new->size && new->wstring)
	// 	new->size = ft_strcut_unicode(1, (char *)new->wstring, ft_strlen((char *)new->wstring));
}

void		ft_manage_conversion(char *conversion, t_print	*new)
{
	int len_conversion;

	len_conversion = ft_strlen(conversion);
	while (new->index < len_conversion && !ft_strchr("sSpdDioOuUxXcC%", conversion[new->index]))
	{
		// printf("conversion :%c\n", conversion[new->index]);
		if (!ft_strchr("#+-0123456789 .hljz%", conversion[new->index]))
		{
			new->string = ft_strsub(conversion, new->index, 1);
			return ;
		}
		if (ft_strchr("#+-0 .", conversion[new->index]))
			ft_stock_attributes(new,conversion);
		// printf("conversion1 :%c\n", conversion[new->index]);
		ft_stock_size(new,conversion);
		// printf("conversion2 :%c\n", conversion[new->index]);
		if (!new->checkprecision)
			ft_stock_precision(new, conversion);
		// printf("conversion3 :%c\n", conversion[new->index]);
		ft_stock_flags(new, conversion);
		// i++;

		// printf("ici, %d => %c\n", new->index, conversion[new->index] );
	}
	if (new->index < len_conversion && ft_strchr("%", conversion[new->index])
		&& new->index++)
	{
			new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'c');
			new->percentage = 1;
	}

	if (new->index < len_conversion && ft_strchr("sSpdDioOuUxXcC", conversion[new->index]))
	{
			// printf("sSpdDioOuUxXcC :%d\n\n", new->index);
			new->conversion = ft_indexchr("sSpdDioOuUxXcC", conversion[new->index++]);
	}

	//
	//
	// printf("\nconversion :%i\n", new->conversion);
	// printf("htag :%d\n", new->htag);
	// printf("plus :%d\n", new->plus);
	// printf("less :%d\n", new->less);
	// printf("space :%d\n", new->space);
	// printf("zero :%d\n", new->zero);
	// printf("size :%d\n", new->size);
	// printf("precision :%d\n", new->precision);
	// printf("checkprecision :%d\n", new->checkprecision);
	// printf("flags :%s\n", new->flags);
	// printf("percentage :%d\n", new->percentage);
	// printf("new->index :%d\n\n", new->index);


}
