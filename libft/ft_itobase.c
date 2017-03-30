/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:18:31 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 10:22:02 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_check_nbr_base(char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		count = 0;
		while (base[j] != '\0')
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			if (base[i] == base[j])
				count++;
			j++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_itobase(uintmax_t nbr, char *base)
{
	int		display;
	int		k;
	int		i;
	char	*temp;
	char	*tab;
	int		base_len;

	i = 0;
	tab = (char*)malloc(256 * sizeof(char));
	while (base[i])
		i++;
	base_len = i;
	while (base[base_len] || (k = 0))
		base_len++;
	if (*base && base_len != 1 && ft_check_nbr_base(base))
	{
		// if (nbr < 0)
		// 	if ((nbr = -nbr))
		// 		tab[k++] = '-';
		display = 0;
		i = 0;
		temp = (char*)malloc(256 * sizeof(char));

		while (nbr != 0)
		{
			temp[i++] = display * base_len + nbr % base_len;
			nbr = nbr / base_len;
		}
		while (i-- > 0)
			tab[k++] = base[0 + temp[i]];
		tab[k] = 0;
	}
	free(temp);
	return (tab);
}
