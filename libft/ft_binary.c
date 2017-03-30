/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:11:45 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/30 17:51:55 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_binary(wchar_t C)
{
	char ctest;

	if (C <= 127)
	{
		ft_putchar(C);
	}
	else if (C <= 2047)
	{
		ctest = (C >> 6) + 0x80;
		write(1, &ctest, 1);
		ctest = 0x82;
		write(1, &ctest, 1);
	}
	else if (C <= 65535)
	{
		ctest = (C >> 6) + 0x80;
		write(1, &ctest, 1);
		ctest = 0x98;
		write(1, &ctest, 1);
		ctest = 0x82;
		write(1, &ctest, 1);
	}
	else if (C <= 2097151)
	{
		ctest = 0xe2;
		write(1, &ctest, 1);
		ctest = 0x98;
		write(1, &ctest, 1);
		ctest = 0x82;
		write(1, &ctest, 1);
		ctest = 0x82;
		write(1, &ctest, 1);
	}
}
