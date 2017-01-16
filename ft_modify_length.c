/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:48:12 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 14:59:55 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

intmax_t	ft_modify_length_di(va_list arg, t_print *new)
{
	intmax_t nb;

	if (ft_strcmp(new->flags,"l"))
		nb = (long)(va_arg(arg, int));
	if (ft_strcmp(new->flags,"ll"))
		nb = (long long)(va_arg(arg, int));
	if (ft_strcmp(new->flags,"h"))
		nb = (short)(va_arg(arg, int));
	if (ft_strcmp(new->flags,"hh"))
		nb = (signed char)(va_arg(arg, int));
	if (ft_strcmp(new->flags,"j"))
		nb = (intmax_t)(va_arg(arg, int));
	if (ft_strcmp(new->flags,"z"))
		nb = (size_t)(va_arg(arg, int));
	return (nb);
}
