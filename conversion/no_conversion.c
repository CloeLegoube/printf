/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:45:47 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 18:35:50 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		no_conversion(t_print *new, va_list arg)
{
	char *string;

	new->space = (new->space) ? 0 : 0;
	if (new->string == NULL)
		new->string = ft_strdup("");
	arg = NULL;
	modify_string(&string, new, (new->checkprecision && !new->htag),
			ft_modify_precision);
	modify_string(&string, new, (new->size), ft_modify_width);
	modify_string(&string, new, (new->space), ft_modify_space);
	modify_string(&string, new, (new->plus), ft_modify_sign);
}
