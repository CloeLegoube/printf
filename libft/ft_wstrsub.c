/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:21:28 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/12 10:04:56 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

wchar_t		*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t		*troncon;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	troncon = (wchar_t *)malloc((len + 1) * sizeof(*troncon));
	if (troncon == NULL)
		return (NULL);
	while (*(wchar_t *)(s + i) && i < len)
	{
		troncon[i] = *(wchar_t *)(s + start + i);
		i++;
	}
	troncon[i] = '\0';
	return (troncon);
}
