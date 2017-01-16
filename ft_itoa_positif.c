/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_positif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:53:46 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 12:22:59 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_length_number(int nb)
{
	int			i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa_positif(unsigned int n)
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
