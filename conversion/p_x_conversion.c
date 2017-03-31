/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_x_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:47:36 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/31 17:55:28 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		p_x_conversion(t_print *new, va_list arg)
{
	char *string;

	new->plus = (new->plus) ? 0 : 0;
	new->space = (new->space) ? 0 : 0;
	new->zero = (new->less && new->zero) ? 0 : new->zero;
	new->precision = (new->checkprecision && !new->precision) ? -1
					: new->precision;
	free(new->htag_prefixe);
	new->htag_prefixe = ft_strdup("0x");
	new->string = ft_modify_htag(arg, new, "0123456789abcdef");
	modify_string(new, (new->checkprecision && !new->htag),
			ft_modify_precision);
	modify_string(new, (new->size), ft_modify_width);
	// if (ft_strcmp(new->htag_prefixe, "no"))
	// {
	// 	free(new->htag_prefixe);
	// 	new->htag_prefixe = ft_strdup("no");
	// }
	free(new->htag_prefixe);
}
