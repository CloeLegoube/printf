/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_positif.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:08:30 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/07 19:35:39 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_positif(unsigned int nb)
{
	unsigned int i;

	i = nb;
	// if (nb < 0)
	// {
	// 	i = -i;
	// 	ft_putchar('-');
	// }
	if (i >= 10)
	{
		ft_putnbr_positif(i / 10);
		ft_putnbr_positif(i % 10);
	}
	else
		ft_putchar(i + 48);
}
