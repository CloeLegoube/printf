/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_b_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:46:18 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 18:36:18 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void				p_b_conversion(t_print *new, va_list arg)
{
	char *string;

	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	new->zero = (new->less && new->zero) ? 0 : new->zero;
	new->precision = (new->checkprecision && !new->precision) ? -1
					: new->precision;
	new->htag_prefixe = ft_strdup("0x");
	new->string = ft_modify_htag(arg, new, "01");
	modify_string(&string, new, (new->checkprecision && !new->htag),
		ft_modify_precision);
	modify_string(&string, new, (new->size), ft_modify_width);
}
