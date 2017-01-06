/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:23:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/06 12:19:24 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{

	int i;
	int d;
	long D;
	int o;
	int O;
	unsigned int x;
	unsigned int X;
	unsigned int u;
	unsigned int U;
	int c;
	wchar_t C;
	void *p;
	const char *str;
	wchar_t *wstr;
	char *tab;
	unsigned char ctest;

	i = 3;
	d = 4556789;
	D = -5456677;
	o = 8;
	O = 65535;
	x = 13;
	X = 65535;
	u = -65534;
	U = 65534;
	c = 33;
	C = L'❤';
	str = "Bonjour Éloïse";
	p = "Hello Éloïse";
	wstr = L"Slt Éloïse !☂ ❤ ☯";
	tab = (char*)malloc(256 * sizeof(char));

	setlocale(LC_ALL, "");

	//Cheval :
	ctest = 0xe2;
	write(1, &ctest, 1);
	ctest = 0x99;
	write(1, &ctest, 1);
	ctest = 0x9E;
	write(1, &ctest, 1);
	// Saut de ligne
	ctest = 0x0a;
	write(1, &ctest, 1);
	//Parapluie :
	ctest = 0xe2;
	write(1, &ctest, 1);
	ctest = 0x98;
	write(1, &ctest, 1);
	ctest = 0x82;
	write(1, &ctest, 1);

	// printf("\nITOA: %s\n", ft_itoa_base(x, "0123456789", 0, tab));
	// printf("TAB: %s\n", tab);
	// printf("ATOI: %d\n\n", ft_atoi_base(tab, "0123456789abcdef"));

	printf("***Test avec i, d et s - d positif ou negatif\n");
	ft_printf("FT_printf :%i) d: %d - str: %s\n", i, d, str);
	printf("Prinft    :%i) d: %d - str: %s\n\n", i, d, str);

	printf("***Test avec p - pointeur void * en hexadecimal\n");
	ft_printf("FT_printf :p: %p\n", p);
	printf("Prinft    :p: %p\n\n", p);

	printf("***Test avec o et O - chiffre octal non signe\n");
	printf("ft_itobase de o:%d == %s\n", o, ft_itobase(o, "01234567"));
	printf("ft_itobase de O:%d == %s\n", O, ft_itobase(O, "01234567"));
	ft_printf("FT_printf :o: %o - O:%O\n", o, O);
	printf("Prinft    :o: %o - O:%O\n\n", o, O);

	printf("***Test avec x et X - chiffre hexadecimal non signe abcdef et ABCDEF\n");
	printf("ft_itobase de x:%d == %s\n", x, ft_itobase(x, "0123456789abcdef"));
	printf("ft_itobase de X:%d == %s\n", X, ft_itobase(X, "0123456789ABCDEF"));
	ft_printf("FT_printf :x: %x - X:%X\n", x, X);
	printf("Prinft    :x: %x - X:%X\n\n", x, X);

	printf("***Test avec c et C - int en unsigned char\n");
	ft_printf("FT_printf :c: %c - C:%C\n", c, C);
	printf("Prinft    :c: %c - C:%C\n", c, C);
	ft_binary(C);

	printf("***Test avec D \n");
	ft_printf("FT_printf :D: %D\n", D);
	printf("Prinft    :D: %ld \n\n", D);

	printf("***Test avec S\n");
	ft_printf("FT_printf :S: %S\n", wstr);
	printf("Prinft    :S: %ls\n", wstr);
	printf("Prinft    :S: %S\n\n", wstr);

	printf("***Test avec u et U - chiffre decimal non signe entree et sortie postif\n");
	printf("ft_itobase de u:%d == %s\n", u, ft_itobase(u, "0123456789"));
	printf("ft_itobase de U:%d == %s\n", U, ft_itobase(U, "0123456789"));
	ft_printf("FT_printf :u: %u - U:%U\n", u, U);
	printf("Prinft    :u: %u - U:%U\n\n", u, U);


	return (0);
}
