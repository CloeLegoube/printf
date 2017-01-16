/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:42:11 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 14:58:35 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (*(unsigned char*)(s1 + i) &&
				*(unsigned char*)(s2 + i) &&
				*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
		i++;
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}
