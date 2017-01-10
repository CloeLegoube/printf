/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:11:45 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/08 17:57:17 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_putwchar2(wchar_t C)
{
	char bit;

	bit = (C >> 18)  + 0xF0;
	write(1, &bit, 1);
	bit = ((C >> 12) & 0x3F) + 0x80;
	write(1, &bit, 1);
	bit = ((C >> 6) & 0x3F) + 0x80;
	write(1, &bit, 1);
	bit = (C & 0x3F) + 0x80;
	write(1, &bit, 1);
}

void			ft_putwchar(wchar_t C)
{
	char bit;

	if (C <= 127)
		ft_putchar(C);
	else if (C <= 2047)
	{
		bit = (C >> 6) + 0xC0;
		write(1, &bit, 1);
		bit = (C & 0x3F) + 0x80;
		write(1, &bit, 1);
	}
	else if (C <= 65535)
	{
		bit = (C >> 12) + 0xE0;
		write(1, &bit, 1);
		bit = ((C >> 6) & 0x3F) + 0x80;
		write(1, &bit, 1);
		bit = (C & 0x3F) + 0x80;
		write(1, &bit, 1);
	}
	else if (C <= 2097151)
	{
		ft_putwchar2(C);
	}
}
