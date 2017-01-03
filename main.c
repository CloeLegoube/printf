/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:03:18 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/30 13:38:06 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{

	int i;
	int d;
	int D;
	int o;
	int O;
	unsigned int x;
	unsigned int X;
	unsigned int u;
	unsigned int U;
	int c;
	int C;
	void *p;
	const char *str;
	wchar_t *wstr;
	char *tab;

	i = 3;
	d = 4556789;
	D = -5456677;
	o = 8;
	O = 65535;
	x = 13;
	X = 65535;
	u = -5456677;
	U = -177777;
	c = 8;
	C = 65535;
	str = "Bonjour Éloïse";
	p = "Hello Éloïse";
	wstr = L"Slt Éloïse !";
	tab = (char*)malloc(256 * sizeof(char));


	printf("ITOA: %s\n", ft_itoa_base(x, "0123456789", 0, tab));
	printf("TAB: %s\n", tab);
	printf("ATOI: %d\n", ft_atoi_base(tab, "0123456789abcdef"));

	printf("Test avec i, d et s - d positif ou negatif\n");
	ft_printf("FT_printf :%i) d: %d - str: %s\n", i, d, str);
	printf("Prinft    :%i) d: %d - str: %s\n", i, d, str);

	printf("Test avec D et S\n");
	ft_printf("FT_printf :D: %d - %S\n", D, wstr);
	printf("Prinft    :D: %D - %ls\n", D, wstr);

	printf("Test avec p - pointeur void * en hexadecimal\n");
	ft_printf("FT_printf :p: %p\n", p);
	printf("Prinft    :p: %p\n", p);

	printf("Test avec o et O - chiffre octal non signe\n");
	ft_printf("FT_printf :o: %o - O:%O\n", o, O);
	printf("Prinft    :o: %o - O:%O\n", o, O);

	printf("Test avec u et U - chiffre decimal non signe entree et sortie postif\n");
	ft_printf("FT_printf :u: %u - U:%U\n", u, U);
	printf("Prinft    :u: %u - U:%U\n", u, U);

	printf("Test avec x et X - chiffre hexadecimal non signe abcdef et ABCDEF\n");
	ft_printf("FT_printf :x: %x - X:%X\n", x, X);
	printf("Prinft    :x: %x - X:%X\n", x, X);

	printf("Test avec c et C - int en unsigned char\n");
	ft_printf("FT_printf :c: %c - C:%C\n", c, C);
	printf("Prinft    :c: %c - C:%C\n", c, C);

	return (0);
}
