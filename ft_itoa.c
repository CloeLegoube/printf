/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:53:46 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 16:28:08 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_length_number(intmax_t nb)
{
	int			i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	char			*string;
	unsigned int	nb;
	size_t			i;

	i = ft_length_number(n);
	string = (char *)malloc((i + 1) * sizeof(*string));
	if (string == NULL)
		return (NULL);
	string[i] = '\0';
	i--;
	if (n < 0)
	{
		nb = -n;
		string[0] = '-';
	}
	else
		nb = n;
	if (nb == 0)
		string[i] = '0';
	while (nb != 0)
	{
		string[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (string);
}
