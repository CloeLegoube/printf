/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:11:45 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/06 20:55:13 by clegoube         ###   ########.fr       */
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
	printf("ft_itobase de C:%lc == %s\n", C, ft_itobase(C, "01"));
	printf("\nConvert binaire en hexa = %s\n\n", ft_convert_base("111000101001110110100100", "01", "0123456789abcdef"));
	// 0xxxxxxx 7
	// 110xxxxx 10xxxxxx 11
	// 1110xxxx 10xxxxxx 10xxxxxx 17
	// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx 23


	// int i;
	// char *bit16;
	// char *bit8;
	//
	// i = ft_strlen(bit16);
	//
	// bit16 = ft_strdup(ft_itobase(C, "01"));
	// printf("ft_itobase de C:%lc == %s\n", C, ft_strdup(ft_itobase(C, "01"));
	// if (ft_strlen(bit16) <= 7)
	// {
	// 	printf("0");
	// 	while (i)
	// 	{
	// 		printf("%c",bit16[i]);
	// 		bit8 = ft_strsub(ft_itobase(0b000010 | 0b11100000, "01"));
	//
	// 		i--;
	// 	}
	// }
	// else if (ft_strlen(bit16) <= 11)
	// {
	// 	printf("110");
	// 	while (bit16[i])
	// 	{
	// 		printf("%c",bit16[i]);
	// 		i++;
	// 	}
	// }
	// else if (ft_strlen(bit16) <= 17)
	// {
	// 	printf("1110");
	// 	while (bit16[i])
	// 	{
	// 		printf("%c",bit16[i]);
	// 		i++;
	// 	}
	// }
	// else if (ft_strlen(bit16) <= 23)
	// {
	// 	printf("** %s-",ft_itobase(0b000010 | 0b11100000, "01"));
	// 	printf("%s-",ft_itobase(0b011101 | 0b10000000, "01"));
	// 	printf("%s-\n",ft_itobase(0b100100 | 0b10000000, "01"));
	// 	printf("==>%s\n","11100010-10011101-10100100");
	//
	// 	// while (bit16[i])
	// 	// {
	// 	// 	printf("%c",bit16[i]);
	// 	// 	i++;
	// 	// }
	// }

	// 10 011101 100100
// 0b0010
// | 0b11110000
//
// 0b0111
// | 0b10000000
//
// 0b0110
// | 0b10000000
//
// 0b0100
// | 0b10000000

// 	0b1001 1101 100100
// | 0b11110000 10000000 10000000 10000000
//
// 	9
// &	12
// =>	8
//
// 	0x9
// &	0xB
// =>	0x8
//
// 	0b1001
// & 	0b1100
// => 	0b1000
//
// 	0b1001
// | 	0b1100
// => 	0b1101
//
// 	0b0110
// << 	1
// => 	0b1100
//
// 	0b0110
// >>	1
// => 	0b0011
//
// 	0b0011
// << 	2
// => 	0b1100


//
// 11110010-10000111-10000110-10000100
// 11100010-10011101-10100100
	// while (s[i])
	// 	write(1, &(s[i++]), 1);



}
