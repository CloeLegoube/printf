/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:23:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/01 18:19:37 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	char c;
	int i;
	int *y;
	char *b;
	unsigned int *k;
	unsigned int r;

	setlocale(LC_ALL, "");
	r = 150;
	c = 'A';
	i = 20;
	y = &i;
	b = NULL;
	k = &r;
	(void)argc;
	(void)argv;

// exceptions constatées
ft_printf("%s\n", b);
printf("%s\n\n", b);
ft_printf("gg%s\n", b);
printf("gg%s\n\n", b);
ft_printf("gg%s\n", "hello");
printf("gg%s\n\n", "hello");
ft_printf("%10d\n", -123456);
printf("%10d\n\n", -123456);
ft_printf("%010d\n", -123456);
printf("%010d\n\n", -123456);
ft_printf("%+010d\n", -123456);
printf("%+010d\n\n", -123456);
ft_printf("%+010d\n", 123456);
printf("%+010d\n\n", 123456);
ft_printf("%4.2d\n", 12);
printf("%4.2d\n\n", 12);
ft_printf("% 04d\n", 12);
printf("% 04d\n\n", 12);
ft_printf("% d\n", 12);
printf("% d\n\n", 12);
ft_printf( "%.0d\n", 0 );
printf( "%.0d\n\n", 0 );
ft_printf( "%.5d\n", 12 );
printf( "%.5d\n\n", 12 );
ft_printf("Valeur FT%-.5d\n", 12 );
printf("Valeur FT%-.5d\n", 12 );
printf("%d", ft_printf("Valeur FT%-.5d\n", 12 ));
printf("%d", printf("Valeur PF%-.5d\n\n", 12 ));
ft_printf( "%.5i\n", 12345678 );
printf( "%.5i\n\n", 12345678 );
ft_printf("FT Par default %.s --\n", "Salut comment ca va?" );
printf( "PF Par default %.s --\n\n", "Salut comment ca va?" );

ft_printf( "FT Par default %s -> %s - %s + %d--\n", "Hello", "comment ca va?", "bien ou pas ?", 123456);
printf( "PF Par default %s -> %s - %s + %d--\n\n", "Hello", "comment ca va?", "bien ou pas ?", 123456);

ft_putnbr_positif(ft_printf( "FT Par default %s -> %s - %s + %d--\n\n", "Hello", "comment ca va?", "bien ou pas ?", 123456));
ft_putnbr_positif(printf( "PF Par default %s -> %s - %s + %d--\n\n", "Hello", "comment ca va?", "bien ou pas ?", 123456));

//
// printf("%04.i\n\n", 0);
// printf("%04.u\n\n", 0);
// printf("%04.o\n\n", 0);
// printf("%04.x\n\n", 0);
// printf("%04.X\n\n", 0);
// printf("%+i\n\n", 123);


	ft_printf("%s\n", "This is a String");
	printf("%s\n\n", "This is a String");
	ft_printf("%S\n", L"صباح الخير");
	printf("%S\n\n", L"صباح الخير");
	ft_printf("%c\n", c);
	printf("%c\n\n", c);

	ft_printf("%%\n");
	printf("%%\n\n");
	ft_printf("%C\n", 256);
	printf("%C\n\n", 256);
	ft_printf("%d\n", 42);
	printf("%d\n\n", 42);
	ft_printf("ld ou D :%D\n", 123456789123);
	printf("ld ou D :%ld\n\n", 123456789123);
	ft_printf("p : %p\n", &c);
	printf("p : %p\n\n", &c);
	ft_printf("cela : %5.2s hello\n", "cela");
	printf("cela : %5.2s hello\n", "cela");

	ft_printf("#x : *%#5.3x*\n", 0);
	printf("#x : *%#5.3x*\n\n", 0);
	ft_printf("#x : *%#-5.3x*\n", 0);
	printf("#x : *%#-5.3x*\n\n", 0);
	ft_printf("#X : *%#-10.8X*\n", 0);
	printf("#X : *%#-10.8X*\n\n\n", 0);

	ft_printf("#o : *%#-10.8o*\n", 0);
	printf("#o : *%#-10.8o*\n\n", 0);
	ft_printf("#o : *%#-10o*\n", 0);
	printf("#o : *%#-10o*\n\n", 0);
	ft_printf("#o : *%-10o*\n", 0);
	printf("#o : *%-10o*\n\n", 0);
	ft_printf("#x : *%-10x*\n", 0);
	printf("#x : *%-10x*\n\n", 0);
	ft_printf("#X : *%-10X*\n", 0);
	printf("#X : *%-10X*\n\n", 0);


	ft_printf("#x : *%5.3x*\n", 0);
	printf("#x : *%5.3x*\n\n", 0);
	ft_printf("#x : *%-5.3x*\n", 0);
	printf("#x : *%-5.3x*\n\n", 0);
	ft_printf("#X : *%-10.8X*\n", 0);
	printf("#X : *%-10.8X*\n\n", 0);
	ft_printf("#o : *%-10.8o*\n", 0);
	printf("#o : *%-10.8o*\n\n", 0);

	ft_printf("#5.3x : *%#5.3x*\n", 123456);
	printf("#5.3x : *%#5.3x*\n\n", 123456);
	ft_printf("#x : *%#-5.3x*\n", 123456);
	printf("#x : *%#-5.3x*\n\n", 123456);
	ft_printf("#X : *%#-10.8X*\n",123456);
	printf("#X : *%#-10.8X*\n\n", 123456);
	ft_printf("#o : *%#-10.8o*\n", 123456);
	printf("#o : *%#-10.8o*\n\n", 123456);

	ft_printf("#x : *%5.3x*\n", 123456);
	printf("#x : *%5.3x*\n\n", 123456);
	ft_printf("#x : *%-5.3x*\n", 123456);
	printf("#x : *%-5.3x*\n\n", 123456);
	ft_printf("#X : *%-10.8X*\n", 123456);
	printf("#X : *%-10.8X*\n\n", 123456);
	ft_printf("#o : *%-10.8o*\n", 123456);
	printf("#o : *%-10.8o*\n\n", 123456);

	ft_printf("%x\n", 123456789);
	printf("%x\n\n", 123456789);
	ft_printf("%X\n", 123456789);
	printf("%X\n\n", 123456789);
	ft_printf(".x : %.x\n", 0);
	printf(".x : %.x\n\n", 0);
	ft_printf("#x : *%#x*\n", 0);
	printf("#x : *%#x*\n\n", 0);
	ft_printf("#X : *%#X*\n", 0);
	printf("#X : *%#X*\n\n", 0);
	ft_printf("#o : *%#o*\n", 0);
	printf("#o : *%#o*\n\n", 0);
	ft_printf("#x : *%.3x*\n", 0);
	printf("#x : *%.3x*\n\n", 0);
	ft_printf("#X : *%10.5X*\n", 0);
	printf("#X : *%10.5X*\n\n", 0);
	ft_printf("#o : *%2.12o*\n", 0);
	printf("#o : *%2.12o*\n\n", 0);

	ft_printf("lx : %lx\n", 1234567891234);
	printf("lx : %lx\n\n", 1234567891234);
	ft_printf("lX : %lX\n", 1234567891234);
	printf("lX : %lX\n\n", 1234567891234);
	ft_printf("u negatif : %u ; %u\n", 42, -42);
	printf("u negatif : %u ; %u\n\n", 42, -42);
	ft_printf("U negatif : %U\n", -123456789123);
	printf("U negatif : %lu\n\n", -123456789123);
	ft_printf("o : %o\n", 4242);
	printf("o : %o\n\n", 4242);
	ft_printf("O : %O\n", 123456789123);
	printf("O : %lo\n\n", 123456789123);
	ft_printf("abc %%\n");
	printf("abc %%\n\n");
	ft_printf("abc %% et cd = %s\n", "cd");
	printf("abc %% et cd = %s\nn", "cd");
	ft_printf("P : int = %p;char = %p;unsigned int = %p;\n", y, b, k);
	printf("P : int = %p;char = %p;unsigned int = %p;\n\n", y, b, k);
	ft_printf("Avec '+' = %+d ;Sans '+' = %d;\n", i, i);
	printf("Avec '+' = %+d ;Sans '+' = %d;\n\n", i, i);
	ft_printf("precision pour 'd': %.5d;\n", 123);
	printf("precision pour 'd': %.5d;\n\n", 123);
	//
	// ft_printf("precision pour 'hd': %.5hd;\n", 123);
	// // printf("precision pour 'hd': %.5hd;\n\n", 123);
	// ft_printf("precision pour 'lld': %.5lld;\n", 123);
	// // printf("precision pour 'lld': %.5lld;\n\n", 123);
	// ft_printf("precision pour 'ld': %.5ld;\n", 123);
	// printf("precision pour 'ld': %.5ld;\n\n", 123);
	// ft_printf("precision pour 'zd': %.5zd;\n", 123);
	// printf("precision pour 'zd': %.5zd;\n\n", 123);
	// ft_printf("precision pour 'jd': %.5jd;\n\n", 123);
	// // printf("precision pour 'jd': %.5jd;\n\n\n", 123);
	// ft_printf("precision pour 'u': %.5u;\n", 123);
	// printf("precision pour 'u': %.5u;\n\n", 123);
	// ft_printf("precision pour 'hu': %.5hu;\n", 123);
	// // printf("precision pour 'hu': %.5hu;\n\n", 123);
	// ft_printf("precision pour 'llu': %.5llu;\n", 123);
	// // printf("precision pour 'llu': %.5llu;\n\n", 123);
	// ft_printf("precision pour 'lu': %.5lu;\n", 123);
	// // printf("precision pour 'lu': %.5lu;\n\n", 123);
	// ft_printf("precision pour 'zu': %.5zu;\n", 123);
	// // printf("precision pour 'zu': %.5zu;\n\n", 123);
	// ft_printf("precision pour 'ju': %.5ju;\n\n", 123);
	// // printf("precision pour 'ju': %.5ju;\n\n\n", 123);
	// ft_printf("precision pour 'o': %.5o;\n", 123);
	// printf("precision pour 'o': %.5o;\n\n", 123);
	// ft_printf("precision pour 'ho': %.5ho;\n", 123);
	// // printf("precision pour 'ho': %.5ho;\n\n", 123);
	// ft_printf("precision pour 'hho': %.5hho;\n", 123);
	// // printf("precision pour 'hho': %.5hho;\n\n", 123);
	// ft_printf("precision pour 'llo': %.5llo;\n", 123);
	// // printf("precision pour 'llo': %.5llo;\n\n", 123);
	// ft_printf("precision pour 'lo': %.5lo;\n", 123);
	// // printf("precision pour 'lo': %.5lo;\n\n", 123);
	// ft_printf("precision pour 'zo': %.5zo;\n", 123);
	// // printf("precision pour 'zo': %.5zo;\n\n", 123);
	// ft_printf("precision pour 'jo': %.5jo;\n", 123);
	// // printf("precision pour 'jo': %.5jo;\n\n", 123);
	// ft_printf("Largeur de champs '5d,10' : %5d;\n", 10);
	// printf("Largeur de champs '5d,10' : %5d;\n\n", 10);
	return (0);
}
