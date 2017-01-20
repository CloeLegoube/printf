/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:23:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/20 15:22:45 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{

	int i;
	int d;
	int d2;
	long D;
	int o;
	int O;
	unsigned int x;
	unsigned int X;
	unsigned long Long;
	unsigned int u;
	unsigned int u2;
	unsigned int U;
	unsigned int U2;
	int c;
	wchar_t C;
	wchar_t C2;
	wchar_t C3;
	wchar_t C4;
	void *p;
	const char *str;
	wchar_t *wstr;
	char *tab;
	unsigned char ctest;

	i = 3;
	d = 45412;
	d2 = -2356;
	D = -5456677;
	o = 8;
	O = 65535;
	x = 13;
	X = 65535;
	u = -65534;
	u2 = 65534;
	U = -65534;
	U2 = 65534;
	c = 33;
	C = L'❤';
	C2 = L'壯';
	C2 = L'壯';
	C3 = 66363;
	C4 = 514;
	str = "Bonjour Éloïse❤";
	p = "Hello Éloïse";
	wstr = L"Slt Éloïse !☂ ❤ ☯";
	tab = (char*)malloc(256 * sizeof(char));
	Long = 1265;

	setlocale(LC_ALL, "");

	//Cheval :
	ctest = 0xe2;
	// write(1, &ctest, 1);
	// ctest = 0x99;
	// write(1, &ctest, 1);
	// ctest = 0x9E;
	// write(1, &ctest, 1);
	// // Saut de ligne
	// ctest = 0x0a;
	// write(1, &ctest, 1);
	// //Parapluie :
	// ctest = 0xe2;
	// write(1, &ctest, 1);
	// ctest = 0x98;
	// write(1, &ctest, 1);
	// ctest = 0x82;
	// write(1, &ctest, 1);

	// printf("\nITOA: %s\n", ft_itoa_base(x, "0123456789", 0, tab));
	// printf("TAB: %s\n", tab);
	// printf("ATOI: %d\n\n", ft_atoi_base(tab, "0123456789abcdef"));

	printf("\n***Test avec i, d et s - d positif ou negatif\n");
	ft_printf("Prinft    :%.3i) d: %.9d - str: %s\n", i, d, str);
	// ft_printf("FT_printf :%i)",  i );
	printf("Prinft    :%.3i) d: %.9d - str: %s\n\n", i, d, str);

	printf("***Test avec p - pointeur void * en hexadecimal\n");
	ft_printf("FT_printf :p: %p\n", p);
	printf("Prinft    :p: %p\n\n", p);
	// printf("Prinft    :Long: %#x\n\n", p);

	printf("***Test avec o et O - chiffre octal non signe\n");
	// printf("ft_itobase de o:%d == %s\n", o, ft_itobase(o, "01234567"));
	// printf("ft_itobase de O:%d == %s\n", O, ft_itobase(O, "01234567"));
	ft_printf("FT_printf :o: %o - O:%O\n", o, O);
	printf("Prinft    :o: %o - O:%O\n\n", o, O);
	//
	printf("***Test avec x et X - chiffre hexadecimal non signe abcdef et ABCDEF\n");
	// printf("ft_itobase de x:%d == %s\n", x, ft_itobase(x, "0123456789abcdef"));
	// printf("ft_itobase de X:%d == %s\n", X, ft_itobase(X, "0123456789ABCDEF"));
	ft_printf("FT_printf :x: %x - X:%X\n", x, X);
	printf("Prinft    :x: %x - X:%X\n\n", x, X);
	//
	printf("***Test avec c et C - int en unsigned char\n");
	ft_printf("FT_printf :c: %c - C:%C\n", c, C);
	printf("Prinft    :c: %c - C:%C\n\n", c, C);
	//
	// // printf("***Test avec c et C2 - int en unsigned char\n");
	// // ft_printf("FT_printf :c: %c - C2:%C\n", c, C2);
	// // printf("Prinft    :c: %c - C2:%C\n", c, C2);
	// //
	// // printf("***Test avec c et C3 - int en unsigned char\n");
	// // ft_printf("FT_printf :c: %c - C3:%C\n", c, C3);
	// // printf("Prinft    :c: %c - C3:%C\n", c, C3);
	// //
	// // printf("***Test avec c et C4 - int en unsigned char\n");
	// // ft_printf("FT_printf :c: %c - C4:%C\n", c, C4);
	// // printf("Prinft    :c: %c - C4:%C\n", c, C4);
	//
	printf("***Test avec D \n");
	ft_printf("FT_printf :D: %D\n", D);
	printf("Prinft    :D: %ld \n\n", D);
	//
	// // printf("recherche  : %s \n\n", ft_strchrstr("FT_printf :u: %u - U:%U\n", "sSpdDioOuUxXcC"));
	//
	printf("***Test avec S\n");
	ft_printf("FT_printf :S: %Slalalalalal\n", wstr);
	printf("Prinft    :S: %ls\n", wstr);
	printf("Prinft    :S: %S\n\n", wstr);
	//
	printf("***Test avec u et U - chiffre decimal non signe entree et sortie postif\n");
	ft_printf("FT_printf :u: %u - U:%U\n", u, U);
	printf("Prinft    :u: %u - U:%U\n", u, U);
	ft_printf("FT_printf :u2: %u - U2:%U\n", u2, U2);
	printf("Prinft    :u2: %u - U2:%U\n\n", u2, U2);
	//
	// printf("***Test avec #x et #X \n");
	// ft_printf("FT_printf #x: %#x - #X:%#X\n", x, X);
	// printf("Prinft    #x: %#x - #X:%#X\n\n", x, X);
	//
	printf("***Test avec # i et #-d \n");
	ft_printf("FT_printf -i :% i - d2:%-d\n", i, d2);
	printf("Prinft    -i :% -i - d2:%-d\n\n", i, d2);
	// printf("Prinft    -i :%-i - d2:%-f\n\n", i, d2);
	//
	//
	// ft_printf("FT_printf precision1 i :%#-00361080.10456752hhi \n\n", i);
	// ft_printf("FT_printf precision2 i :%- 0+14524.45lli \n\n", i);
	// printf("Printf precision i :%+010.2i \n", i);
	// printf("Int MAX : %d\n", INT_MAX);
	// printf("Int MIN : %d\n", INT_MIN);
	// printf("LONG MAX : %ld\n", LONG_MAX);
	// printf("LONG MIN : %ld\n\n", LONG_MIN);


	return (0);
}
