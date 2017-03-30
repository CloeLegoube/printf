/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_o_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:47:04 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 18:37:40 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		p_o_conversion(t_print *new, va_list arg)
{
	char *string;

	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	new->zero = (new->precision && new->zero) ? 0 : new->zero;
	new->zero = (new->less && new->zero) ? 0 : new->zero;
	if (new->zero && new->checkprecision && new->precision == 0)
		new->zero = 0;
	if (new->checkprecision && new->precision == 0)
		new->precision = -1;
	if (new->htag && new->checkprecision && new->precision == -1)
		new->precision = 0;
	if (new->precision < 1)
		new->htag_prefixe = ft_strdup("0");
	new->string = ft_modify_htag(arg, new, "01234567");
	new->value_zero = (new->string[0] == '0') ? 1 : new->value_zero;
	modify_string(&string, new, (new->checkprecision), ft_modify_precision);
	modify_string(&string, new, (new->size), ft_modify_width);
}
