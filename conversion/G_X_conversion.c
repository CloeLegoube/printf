/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_x_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:35 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 12:11:52 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		g_x_conversion(t_print *new, va_list arg)
{
	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	new->zero = (new->zero && new->checkprecision && new->precision == 0) ? 0
				: new->zero;
	new->zero = (new->zero && new->less) ? 0 : new->zero;
	new->htag_prefixe = ft_strdup("0X");
	new->string = ft_modify_htag(arg, new, "0123456789ABCDEF");
	if (new->value_zero && new->checkprecision && new->precision == 0)
		new->precision = -1;
	modify_string(new, (new->checkprecision && !new->htag),
		ft_modify_precision);
	modify_string(new, (new->size), ft_modify_width);
}
