/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:23:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/25 19:31:17 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{

	char *str;
	// char charac;
	// wchar_t wcharac;
	// wchar_t C;
	// wchar_t C1;
	// wchar_t C2;
	// wchar_t C3;
	// wchar_t C4;
	// wchar_t C5;
	// wchar_t C6;

	// unsigned int u;
	int o;
	long unsigned int O;
	unsigned int x;
	unsigned int X;
	//
	o = 8;
	O = 65535;
	x = 13;
	X = 65535;
	// u = -65534;
	str = "Bonjour Eloise";
	// charac = 'a';
	// wcharac = L'❤';
	// C = L'❤';
	// C1 = L'ï';
	// C2 = L'壯';
	// C3 = 66363;
	// C4 = 514;
	// C5 = L'É';
	// C6 = L'☂';
	setlocale(LC_ALL, "");

	// ft_printf("FT - Test  d: %d et %c \n", 123456, '\0');
	///*************** TEST d ****************///
	// ft_printf("FT - Test  d: %d  \n", 123456);
	// printf("PF - Test  d: %d  \n", 123456);
	// ft_printf("FT - Test  d: %ld  \n", 123456789123);
	// printf("PF - Test  d: %ld  \n", 123456789123);
	// ft_printf("FT - Test  d: %d  \n", -1234);
	// printf("PF - Test  d: %d  \n", -1234);
	//
	// ft_printf("FT - Test  d: %.0d  \n", 1234);
	// printf("PF - Test  d: %.0d  \n", 1234);
	// ft_printf("FT - Test  d: %.d  \n", 1234);
	// printf("PF - Test  d: %.d  \n", 1234);
	// ft_printf("FT - Test  d: %.0d  \n", 0);
	// printf("PF - Test  d: %.0d  \n", 0);
	// ft_printf("FT - Test  d: %.d  \n", 0);
	// printf("PF - Test  d: %.d  \n", 0);
	// ft_printf("FT - Test  d: %.25ld  \n", 1124512345660);
	// printf("PF - Test  d: %.25ld  \n", 1124512345660);
	//
	// ft_printf("FT - Test  d: %05d  \n", 1234);
	// printf("PF - Test  d: %05d  \n", 1234);
	// ft_printf("FT - Test  d: %8d  \n", 1234);
	// printf("PF - Test  d: %8d  \n", 1234);
	// ft_printf("FT - Test  d: *%-05d* \n", 1234);
	// printf("PF - Test  d: *%-5d* \n\n", 1234);
	//
	// ft_printf("FT - Test -+8d: *%-+8d* \n", 1234);
	// printf("PF - Test -+8d: *%-+8d* \n\n", 1234);
	//
	// ft_printf("FT - Test  +5d: *%+5d* \n", 1234);
	// printf("PF - Test  +5d: *%+5d* \n\n", 1234);
	// ft_printf("FT - Test  +9d: *%+9d* \n", 1234);
	// printf("PF - Test  +9d: *%+9d* \n\n", 1234);
	//
	// ft_printf("FT - Test  d: *%+5d* \n", -1234);
	// printf("PF - Test  d: *%+5d* \n", -1234);
	// ft_printf("FT - Test  d: *%5d* \n", -1234);
	// printf("PF - Test  d: *%5d* \n", -1234);
	//
	// ft_printf("FT - Test  d: *%.5d* \n", 0);
	// printf("PF - Test  d: *%.5d* \n\n", 0);
	//
	// ft_printf("FT - Test   0 8d: *%0 8d* \n", 123456);
	// printf("PF - Test   0 8d: *%0 8d* \n\n", 123456);
	// ft_printf("FT - Test  less 0 8d: *%0 8d* \n", -123456);
	// printf("PF - Test  less 0 8d: *%0 8d* \n\n", -123456);
	// ft_printf("FT - Test  +08d : *%+08d* \n", 123456);
	// printf("PF - Test  +08d : *%+08d* \n\n", 123456);
	// ft_printf("FT - Test  less 0 10d: *%0 10d* \n", -123456);
	// printf("PF - Test  less 0 10d: *%0 10d* \n\n", -123456);
	// ft_printf("FT - Test  less 011d: *%011d* \n", -123456);
	// printf("PF - Test  less 011d: *%011d* \n\n", -123456);
	// ft_printf("FT - Test  less 0 8d: *%010d* \n", -123456);
	// printf("PF - Test  less  08d: *%010d* \n\n", -123456);
	// ft_printf("FT - Test  less  08d: *% 10d* \n", -123456);
	// printf("PF - Test  less  08d: *% 10d* \n\n", -123456);
	// ft_printf("FT - Test less +0 8d: *%+0 8d* \n", -123456);
	// printf("PF - Test less +08d : *%+08d* \n\n", -123456);
	//
	// ft_printf("FT - Test   + 8d: *%+ 8d* \n", 123456);
	// ft_printf("FT - Test    +8d: *%+8d* \n", 123456);
	// printf("PF - Test   +8d : *%+8d* \n\n", 123456);
	// ft_printf("FT - Test   -+8d : *%-+8d* \n", 123456);
	// printf("PF - Test   -+8d : *%-+8d* \n\n", 123456);
	// ft_printf("FT - Test   -+ 8d : *%-+ 8d* \n", 123456);
	// printf("PF - Test   -+8d  : *%-+8d* \n\n", 123456);
	//
	// ft_printf("FT - Test   +d : *%+d* \n", 123456);
	// printf("PF - Test   +d : *%+d* \n\n", 123456);
	// ft_printf("FT - Test   +-d : *%-d* \n", 123456);
	// printf("PF - Test   +-d : *%-d* \n\n", 123456);
	// ft_printf("FT - Test   0d : *%0d* \n", 123456);
	// printf("PF - Test   0d : *%0d* \n\n", 123456);
	// ft_printf("FT - Test   d : *% d* \n", 123456);
	// printf("PF - Test   d : *% d* \n\n", 123456);
	// ft_printf("FT - Test   d : *% 10d* \n", 123456);
	// printf("PF - Test   d : *% 10d* \n\n", 123456);

	///*************** TEST i ****************///
	// ft_printf("FT - Test  i: %i  \n", 123456);
	// printf("PF - Test  i: %i  \n", 123456);
	// ft_printf("FT - Test  i: %li  \n", 123456789123);
	// printf("PF - Test  i: %li  \n", 123456789123);
	// ft_printf("FT - Test  i: %i  \n", -1234);
	// printf("PF - Test  i: %i  \n", -1234);
	//
	// ft_printf("FT - Test  i: %.0i  \n", 1234);
	// printf("PF - Test  i: %.0i  \n", 1234);
	// ft_printf("FT - Test  i: %.i  \n", 1234);
	// printf("PF - Test  i: %.i  \n", 1234);
	// ft_printf("FT - Test  i: %.0i  \n", 0);
	// printf("PF - Test  i: %.0i  \n", 0);
	// ft_printf("FT - Test  i: %.i  \n", 0);
	// printf("PF - Test  i: %.i  \n", 0);
	// ft_printf("FT - Test  i: %.25li  \n", 1124512345660);
	// printf("PF - Test  i: %.25li  \n", 1124512345660);
	//
	// ft_printf("FT - Test  i: %05i  \n", 1234);
	// printf("PF - Test  i: %05i  \n", 1234);
	// ft_printf("FT - Test  i: %8i  \n", 1234);
	// printf("PF - Test  i: %8i  \n", 1234);
	// ft_printf("FT - Test  i: *%-05i* \n", 1234);
	// printf("PF - Test  i: *%-5i* \n\n", 1234);
	//
	// ft_printf("FT - Test -+8i: *%-+8i* \n", 1234);
	// printf("PF - Test -+8i: *%-+8i* \n\n", 1234);
	//
	// ft_printf("FT - Test  +5i: *%+5i* \n", 1234);
	// printf("PF - Test  +5i: *%+5i* \n\n", 1234);
	// ft_printf("FT - Test  +9i: *%+9i* \n", 1234);
	// printf("PF - Test  +9i: *%+9i* \n\n", 1234);
	// ft_printf("FT - Test  i: *%+5i* \n", -1234);
	// printf("PF - Test  i: *%+5i* \n", -1234);
	//
	// ft_printf("FT - Test  i: *%.5i* \n", 0);
	// printf("PF - Test  i: *%.5i* \n", 0);
	//
	// ft_printf("FT - Test   0 8i: *%0 8i* \n", 123456);
	// printf("PF - Test   0 8i: *%0 8i* \n\n", 123456);
	// ft_printf("FT - Test  +0 8i: *%+0 8i* \n", 123456);
	// printf("PF - Test  +08i : *%+08i* \n\n", 123456);
	// ft_printf("FT - Test   + 8i: *%+ 8i* \n", 123456);
	// ft_printf("FT - Test    +8i: *%+8i* \n", 123456);
	// printf("PF - Test   +8i : *%+8i* \n\n", 123456);
	// ft_printf("FT - Test   -+8i : *%-+8i* \n", 123456);
	// printf("PF - Test   -+8i : *%-+8i* \n\n", 123456);
	// ft_printf("FT - Test   -+ 8i : *%-+ 8i* \n", 123456);
	// printf("PF - Test   -+8i  : *%-+8i* \n\n", 123456);
	//
	// ft_printf("FT - Test   +i : *%+i* \n", 123456);
	// printf("PF - Test   +i : *%+i* \n\n", 123456);
	// ft_printf("FT - Test   +-i : *%-i* \n", 123456);
	// printf("PF - Test   +-i : *%-i* \n\n", 123456);
	// ft_printf("FT - Test   0i : *%0i* \n", 123456);
	// printf("PF - Test   0i : *%0i* \n\n", 123456);
	// ft_printf("FT - Test   i : *% i* \n", 123456);
	// printf("PF - Test   i : *% i* \n\n", 123456);
	// ft_printf("FT - Test   i : *% 10i* \n", 123456);
	// printf("PF - Test   i : *% 10i* \n\n", 123456);

	/*************** TEST o ****************///
	// ft_printf("FT - Test  o: %o  \n", 123456);
	// printf("PF - Test  o: %o  \n", 123456);
	// ft_printf("FT - Test  o: %lo  \n", 123456789123);
	// printf("PF - Test  o: %lo  \n", 123456789123);
	// ft_printf("FT - Test  o: %o  \n", -1234);
	// printf("PF - Test  o: %o  \n", -1234);
	//
	// ft_printf("FT - Test  o: %.0o  \n", 1234);
	// printf("PF - Test  o: %.0o  \n", 1234);
	// ft_printf("FT - Test  o: %.o  \n", 1234);
	// printf("PF - Test  o: %.o  \n\n", 1234);
	//
	// ft_printf("FT - Test  o: %.0o  \n", 0);
	// printf("PF - Test  o: %.0o  \n", 0);
	// ft_printf("FT - Test  o: %.o  \n", 0);
	// printf("PF - Test  o: %.o  \n\n", 0);
	// ft_printf("FT - Test  o: *%.5o* \n", 0);
	// printf("PF - Test  o: *%.5o* \n", 0);
	// printf("%i\n", ft_printf("FT - Test  o: %.0o  \n", 0));
	// printf("%i\n", printf("PF - Test  o: %.0o  \n", 0));
	// printf("%i\n", ft_printf("FT - Test  o: %.o  \n", 0));
	// printf("%i\n", printf("PF - Test  o: %.o  \n\n", 0));
	// printf("%i\n", ft_printf("FT - Test  o: *%.5o* \n", 0));
	// printf("%i\n", printf("PF - Test  o: *%.5o* \n", 0));
	//
	// ft_printf("FT - Test  o: %.25lo  \n", 1124512345660);
	// printf("PF - Test  o: %.25lo  \n", 1124512345660);
	// ft_printf("FT - Test  o: %32.25lo  \n", 1124512345660);
	// printf("PF - Test  o: %32.25lo  \n", 1124512345660);
	//
	// ft_printf("FT - Test  o: %05o  \n", 1234);
	// printf("PF - Test  o: %05o  \n", 1234);
	// ft_printf("FT - Test  o: %8o  \n", 1234);
	// printf("PF - Test  o: %8o  \n", 1234);
	// ft_printf("FT - Test  o: *%-05o* \n", 1234);
	// printf("PF - Test  o: *%-5o* \n\n", 1234);
	//
	// ft_printf("FT - Test -+8o: *%-+8o* \n", 1234);
	// printf("PF - Test  -8o: *%-8o* \n\n", 1234);
	//
	// ft_printf("FT - Test  +5o: *%+5o* \n", 1234);
	// printf("PF - Test   5o: *%5o* \n\n", 1234);
	// ft_printf("FT - Test  +9o: *%+9o* \n", 1234);
	// printf("PF - Test   9o: *%9o* \n\n", 1234);
	// ft_printf("FT - Test  o: *%+5o* \n", -1234);
	// printf("PF - Test  o: *%5o* \n", -1234);
	//
	// ft_printf("FT - Test   0 8o: *%0 8o* \n", 123456);
	// printf("PF - Test   0 8o: *%08o* \n\n", 123456);
	// ft_printf("FT - Test  +0 8o: *%+0 8o* \n", 123456);
	// printf("PF - Test   08o : *%08o* \n\n", 123456);
	// ft_printf("FT - Test   + 8o: *%+ 8o* \n", 123456);
	// ft_printf("FT - Test    +8o: *%+8o* \n", 123456);
	// printf("PF - Test    8o : *%8o* \n\n", 123456);
	// ft_printf("FT - Test   -+8o : *%-+8o* \n", 123456);
	// printf("PF - Test    -8o : *%-8o* \n\n", 123456);
	// ft_printf("FT - Test   -+ 8o : *%-+ 8o* \n", 123456);
	// printf("PF - Test    -8o  : *%-8o* \n\n", 123456);
	//
	// ft_printf("FT - Test   +o : *%+o* \n", 123456);
	// printf("PF - Test    o : *%o* \n\n", 123456);
	// ft_printf("FT - Test   +-o : *%-o* \n", 123456);
	// printf("PF - Test   +-o : *%-o* \n\n", 123456);
	// ft_printf("FT - Test   0o : *%0o* \n", 123456);
	// printf("PF - Test   0o : *%0o* \n\n", 123456);
	// ft_printf("FT - Test   o : *% o* \n", 123456);
	// printf("PF - Test   o : *%o* \n\n", 123456);
	// ft_printf("FT - Test   o : *% 10o* \n", 123456);
	// printf("PF - Test   o : *%10o* \n\n", 123456);
	//
	// ft_printf("FT - Test    10o : *%10o* \n", 123456);
	// printf("PF - Test    10o : *%10o* \n\n", 123456);
	// ft_printf("FT - Test   #10o : *%#10o* \n", 123456);
	// printf("PF - Test   #10o : *%#10o* \n\n", 123456);
	// ft_printf("FT - Test   #10.8o : *%#10.8o* \n", 123456);
	// printf("PF - Test   #10.8o : *%#10.8o* \n\n", 123456);
	// ft_printf("FT - Test   10.8o : *%10.8o* \n", 123456);
	// printf("PF - Test   10.8o : *%10.8o* \n\n", 123456);
	//
	// ft_printf("FT - Test   #010.8o : *%#010.8o* \n", 123456);
	// ft_printf("FT - Test    #10.8o : *%#10.8o* \n", 123456);
	// printf("PF - Test    #10.8o : *%#10.8o* \n\n", 123456);
	//
	// ft_printf("FT - Test   0#10.8o : *%0#10.8o* \n", 123456);
	// printf("PF - Test    #10.8o : *%#10.8o* \n\n", 123456);
	// ft_printf("FT - Test    #10.8o : *%#10.8o* \n", 123456);
	// printf("PF - Test    #10.8o : *%#10.8o* \n\n", 123456);
	//
	// ft_printf("FT - Test   #.8o : *%#.8o* \n", 123456);
	// printf("PF - Test   #.8o : *%#.8o* \n\n", 123456);
	// ft_printf("FT - Test   10.8o : *%10.8o* \n", 123456);
	// printf("PF - Test   10.8o : *%10.8o* \n\n", 123456);

	///*************** TEST u ****************///
	// ft_printf("FT - Test  u: %u  \n", 123456);
	// printf("PF - Test  u: %u  \n", 123456);
	// ft_printf("FT - Test  u: %lu  \n", 123456789123);
	// printf("PF - Test  u: %lu  \n", 123456789123);
	// ft_printf("FT - Test  u: %u  \n", -1234);
	// printf("PF - Test  u: %u  \n", -1234);
	//
	// ft_printf("FT - Test  u: %.0u  \n", 1234);
	// printf("PF - Test  u: %.0u  \n", 1234);
	// ft_printf("FT - Test  u: %.u  \n", 1234);
	// printf("PF - Test  u: %.u  \n", 1234);
	// ft_printf("FT - Test  u: %.0u  \n", 0);
	// printf("PF - Test  u: %.0u  \n", 0);
	// ft_printf("FT - Test  u: %.u  \n", 0);
	// printf("PF - Test  u: %.u  \n", 0);
	// ft_printf("FT - Test  u: %.25lu  \n", 1124512345660);
	// printf("PF - Test  u: %.25lu  \n", 1124512345660);
	//
	// ft_printf("FT - Test  u: %05u  \n", 1234);
	// printf("PF - Test  u: %05u  \n", 1234);
	// ft_printf("FT - Test  u: %8u  \n", 1234);
	// printf("PF - Test  u: %8u  \n", 1234);
	// ft_printf("FT - Test  u: *%-05u* \n", 1234);
	// printf("PF - Test  u: *%-5u* \n\n", 1234);
	//
	// ft_printf("FT - Test -+8u: *%-+8u* \n", 1234);
	// printf("PF - Test  -8u: *%-8u* \n\n", 1234);
	//
	// ft_printf("FT - Test  +5u: *%+5u* \n", 1234);
	// printf("PF - Test   5u: *%5u* \n\n", 1234);
	// ft_printf("FT - Test  +9u: *%+9u* \n", 1234);
	// printf("PF - Test   9u: *%9u* \n\n", 1234);
	// ft_printf("FT - Test  u: *%+5u* \n", -1234);
	// printf("PF - Test  u: *%5u* \n", -1234);
	//
	// ft_printf("FT - Test  u: *%.5u* \n", 0);
	// printf("PF - Test  u: *%.5u* \n", 0);
	//
	// ft_printf("FT - Test   0 8u: *%0 8u* \n", 123456);
	// printf("PF - Test    08u: *%08u* \n\n", 123456);
	// ft_printf("FT - Test  +0 8u: *%+0 8u* \n", 123456);
	// printf("PF - Test   08u : *%08u* \n\n", 123456);
	// ft_printf("FT - Test   + 8u: *%+ 8u* \n", 123456);
	// ft_printf("FT - Test    +8u: *%+8u* \n", 123456);
	// printf("PF - Test    8u : *%8u* \n\n", 123456);
	// ft_printf("FT - Test   -+8u : *%-+8u* \n", 123456);
	// printf("PF - Test    -8u : *%-8u* \n\n", 123456);
	// ft_printf("FT - Test   -+ 8u : *%-+ 8u* \n", 123456);
	// printf("PF - Test    -8u  : *%-8u* \n\n", 123456);
	//
	// ft_printf("FT - Test   +u : *%+u* \n", 123456);
	// printf("PF - Test    u : *%u* \n\n", 123456);
	// ft_printf("FT - Test    -u : *%-u* \n", 123456);
	// printf("PF - Test    -u : *%-u* \n\n", 123456);
	// ft_printf("FT - Test   0u : *%0u* \n", 123456);
	// printf("PF - Test   0u : *%0u* \n\n", 123456);
	// ft_printf("FT - Test   u : *% u* \n", 123456);
	// printf("PF - Test   u : *%u* \n\n", 123456);
	// ft_printf("FT - Test   u : *% 10u* \n", 123456);
	// printf("PF - Test   u : *%10u* \n\n", 123456);

	///*************** TEST x ****************///
	// ft_printf("FT - Test  x: %x  \n", 123456);
	// printf("PF - Test  x: %x  \n", 123456);
	// ft_printf("FT - Test  x: %lx  \n", 123456789123);
	// printf("PF - Test  x: %lx  \n", 123456789123);
	// ft_printf("FT - Test  x: %x  \n", -1234);
	// printf("PF - Test  x: %x  \n", -1234);
	//
	// ft_printf("FT - Test  x: %.0x  \n", 1234);
	// printf("PF - Test  x: %.0x  \n", 1234);
	// ft_printf("FT - Test  x: %.x  \n", 1234);
	// printf("PF - Test  x: %.x  \n", 1234);
	// ft_printf("FT - Test  x: %.0x  \n", 0);
	// printf("PF - Test  x: %.0x  \n", 0);
	// ft_printf("FT - Test  x: %.x  \n", 0);
	// printf("PF - Test  x: %.x  \n", 0);
	// printf("%i\n",ft_printf("FT - Test  x: %.0x  \n", 0));
	// printf("%i\n",printf("PF - Test  x: %.0x  \n", 0));
	// printf("%i\n",ft_printf("FT - Test  x: %.x  \n", 0));
	// printf("%i\n",printf("PF - Test  x: %.x  \n", 0));
	// ft_printf("FT - Test  x: %.25lx  \n", 1124512345660);
	// printf("PF - Test  x: %.25lx  \n", 1124512345660);
	//
	// ft_printf("FT - Test  x: %05x  \n", 1234);
	// printf("PF - Test  x: %05x  \n", 1234);
	// ft_printf("FT - Test  x: %8x  \n", 1234);
	// printf("PF - Test  x: %8x  \n", 1234);
	// ft_printf("FT - Test  x: *%-05x* \n", 1234);
	// printf("PF - Test  x: *%-5x* \n\n", 1234);
	//
	// ft_printf("FT - Test -+8x: *%-+8x* \n", 1234);
	// ft_printf("FT - Test  -8x: *%-8x* \n", 1234);
	// printf("PF - Test  -8x: *%-8x* \n\n", 1234);
	//
	// ft_printf("FT - Test  +5x: *%+5x* \n", 1234);
	// ft_printf("FT - Test   5x: *%5x* \n", 1234);
	// printf("PF - Test   5x: *%5x* \n\n", 1234);
	// ft_printf("FT - Test  +9x: *%+9x* \n", 1234);
	// printf("PF - Test   9x: *%9x* \n\n", 1234);
	// ft_printf("FT - Test  x: *%+5x* \n", -1234);
	// printf("PF - Test  x: *%5x* \n", -1234);
	//
	// ft_printf("FT - Test  x: *%.5x* \n", 0);
	// printf("PF - Test  x: *%.5x* \n", 0);
	//
	// ft_printf("FT - Test   0 8x: *%0 8x* \n", 123456);
	// ft_printf("FT - Test    08x: *%08x* \n", 123456);
	// printf("PF - Test    08x: *%08x* \n\n", 123456);
	// ft_printf("FT - Test  +0 8x: *%+0 8x* \n", 123456);
	// printf("PF - Test   08x : *%08x* \n\n", 123456);
	// ft_printf("FT - Test   + 8x: *%+ 8x* \n", 123456);
	// ft_printf("FT - Test    +8x: *%+8x* \n", 123456);
	// printf("PF - Test    8x : *%8x* \n\n", 123456);
	// ft_printf("FT - Test   -+8x : *%-+8x* \n", 123456);
	// ft_printf("FT - Test    -8x : *%-8x* \n", 123456);
	// ft_printf("FT - Test  -+ 8x : *%-+ 8x* \n", 123456);
	// printf("PF - Test   -8x  : *%-8x* \n\n", 123456);
	//
	// ft_printf("FT - Test   +x : *%+x* \n", 123456);
	// printf("PF - Test    x : *%x* \n\n", 123456);
	// ft_printf("FT - Test   +-x : *%-x* \n", 123456);
	// printf("PF - Test   +-x : *%-x* \n\n", 123456);
	// ft_printf("FT - Test   0x : *%0x* \n", 123456);
	// printf("PF - Test   0x : *%0x* \n\n", 123456);
	// ft_printf("FT - Test   x : *% x* \n", 123456);
	// ft_printf("FT - Test   x : *%x* \n", 123456);
	// printf("PF - Test   x : *%x* \n\n", 123456);
	// ft_printf("FT - Test   x : *% 10x* \n", 123456);
	// printf("PF - Test   x : *%10x* \n\n", 123456);
	//
	// printf("\n\n****** Test x ********\n\n");
	// ft_printf("FT - Test    10x : *%10x* \n", 123456);
	// printf("PF - Test    10x : *%10x* \n\n", 123456);
	// ft_printf("FT - Test   #10x : *%#10x* \n", 123456);
	// printf("PF - Test   #10x : *%#10x* \n\n", 123456);
	// ft_printf("FT - Test   #10.8x : *%#10.8x* \n", 123456);
	// printf("PF - Test   #10.8x : *%#10.8x* \n\n", 123456);
	// ft_printf("FT - Test   10.8x : *%10.8x* \n", 123456);
	// printf("PF - Test   10.8x : *%10.8x* \n\n", 123456);
	// ft_printf("FT - Test   #010.8x : *%#010.8x* \n", 123456);
	// ft_printf("FT - Test    #10.8x : *%#10.8x* \n", 123456);
	// printf("PF - Test    #10.8x : *%#10.8x* \n\n", 123456);
	// ft_printf("FT - Test   0#10.8x : *%0#10.8x* \n", 123456);
	// ft_printf("FT - Test    #10.8x : *%#10.8x* \n", 123456);
	// printf("PF - Test    #10.8x : *%#10.8x* \n\n", 123456);
	// ft_printf("FT - Test   #.8x : *%#.8x* \n", 123456);
	// printf("PF - Test   #.8x : *%#.8x* \n\n", 123456);
	// ft_printf("FT - Test   10.8x : *%10.8x* \n", 123456);
	// printf("PF - Test   10.8x : *%10.8x* \n\n", 123456);

	///*************** TEST X ****************///
	// ft_printf("FT - Test  X: %X  \n", 123456);
	// printf("PF - Test  X: %X  \n", 123456);
	// ft_printf("FT - Test  X: %lX  \n", 123456789123);
	// printf("PF - Test  X: %lX  \n", 123456789123);
	// ft_printf("FT - Test  X: %X  \n", -1234);
	// printf("PF - Test  X: %X  \n", -1234);
	//
	// ft_printf("FT - Test  X: %.0X  \n", 1234);
	// printf("PF - Test  X: %.0X  \n", 1234);
	// ft_printf("FT - Test  X: %.X  \n", 1234);
	// printf("PF - Test  X: %.X  \n", 1234);
	// ft_printf("FT - Test  X: %.0X  \n", 0);
	// printf("PF - Test  X: %.0X  \n", 0);
	// ft_printf("FT - Test  X: %.X  \n", 0);
	// printf("PF - Test  X: %.X  \n", 0);
	// printf("%i\n",ft_printf("FT - Test  X: %.0X  \n", 0));
	// printf("%i\n",printf("PF - Test  X: %.0X  \n", 0));
	// printf("%i\n",ft_printf("FT - Test  X: %.X  \n", 0));
	// printf("%i\n",printf("PF - Test  X: %.X  \n", 0));
	// ft_printf("FT - Test  X: %.25lX  \n", 1124512345660);
	// printf("PF - Test  X: %.25lX  \n", 1124512345660);
	//
	// ft_printf("FT - Test  X: %05X  \n", 1234);
	// printf("PF - Test  X: %05X  \n", 1234);
	// ft_printf("FT - Test  X: %8X  \n", 1234);
	// printf("PF - Test  X: %8X  \n", 1234);
	// ft_printf("FT - Test  X: *%-05X* \n", 1234);
	// printf("PF - Test  X: *%-5X* \n\n", 1234);
	//
	// ft_printf("FT - Test -+8X: *%-+8X* \n", 1234);
	// printf("PF - Test  -8X: *%-8X* \n\n", 1234);
	//
	// ft_printf("FT - Test  +5X: *%+5X* \n", 1234);
	// printf("PF - Test   5X: *%5X* \n\n", 1234);
	// ft_printf("FT - Test  +9X: *%+9X* \n", 1234);
	// printf("PF - Test   9X: *%9X* \n\n", 1234);
	// ft_printf("FT - Test  X: *%+5X* \n", -1234);
	// printf("PF - Test  X: *%5X* \n", -1234);
	//
	// ft_printf("FT - Test  X: *%.5X* \n", 0);
	// printf("PF - Test  X: *%.5X* \n", 0);
	//
	// ft_printf("FT - Test   0 8X: *%0 8X* \n", 123456);
	// ft_printf("FT - Test    08X: *%08X* \n", 123456);
	// printf("PF - Test    08X: *%08X* \n\n", 123456);
	// ft_printf("FT - Test  +0 8X: *%+0 8X* \n", 123456);
	// printf("PF - Test   08X : *%08X* \n\n", 123456);
	// ft_printf("FT - Test   + 8X: *%+ 8X* \n", 123456);
	// ft_printf("FT - Test    +8X: *%+8X* \n", 123456);
	// printf("PF - Test    8X : *%8X* \n\n", 123456);
	// ft_printf("FT - Test   -+8X : *%-+8X* \n", 123456);
	// printf("PF - Test    -8X : *%-8X* \n\n", 123456);
	// ft_printf("FT - Test   -+ 8X : *%-+ 8X* \n", 123456);
	// printf("PF - Test    -8X  : *%-8X* \n\n", 123456);
	//
	// ft_printf("FT - Test   +X : *%+X* \n", 123456);
	// printf("PF - Test    X : *%X* \n\n", 123456);
	// ft_printf("FT - Test   +-X : *%-X* \n", 123456);
	// printf("PF - Test   +-X : *%-X* \n\n", 123456);
	// ft_printf("FT - Test   0X : *%0X* \n", 123456);
	// printf("PF - Test   0X : *%0X* \n\n", 123456);
	// ft_printf("FT - Test   X : *% X* \n", 123456);
	// printf("PF - Test   X : *%X* \n\n", 123456);
	// ft_printf("FT - Test   X : *% 10X* \n", 123456);
	// printf("PF - Test   X : *%10X* \n\n", 123456);
	//
	// printf("\n\n****** Test X ********\n\n");
	// ft_printf("FT - Test    10X : *%10X* \n", 123456);
	// printf("PF - Test    10X : *%10X* \n\n", 123456);
	// ft_printf("FT - Test   #10X : *%#10X* \n", 123456);
	// printf("PF - Test   #10X : *%#10X* \n\n", 123456);
	// ft_printf("FT - Test   #10.8X : *%#10.8X* \n", 123456);
	// printf("PF - Test   #10.8X : *%#10.8X* \n\n", 123456);
	// ft_printf("FT - Test   10.8X : *%10.8X* \n", 123456);
	// printf("PF - Test   10.8X : *%10.8X* \n\n", 123456);
	// ft_printf("FT - Test   #010.8X : *%#010.8X* \n", 123456);
	// ft_printf("FT - Test    #10.8X : *%#10.8X* \n", 123456);
	// printf("PF - Test    #10.8X : *%#10.8X* \n\n", 123456);
	// ft_printf("FT - Test   0#10.8X : *%0#10.8X* \n", 123456);
	// ft_printf("FT - Test    #10.8X : *%#10.8X* \n", 123456);
	// printf("PF - Test    #10.8X : *%#10.8X* \n\n", 123456);
	// ft_printf("FT - Test   #.8X : *%#.8X* \n", 123456);
	// printf("PF - Test   #.8X : *%#.8X* \n\n", 123456);
	// ft_printf("FT - Test   10.8X : *%10.8X* \n", 123456);
	// printf("PF - Test   10.8X : *%10.8X* \n\n", 123456);

	///*************** TEST P ****************///
	// printf("***Test avec p - pointeur void * en hexadecimal\n");
	// ft_putnbr_positif(ft_printf("FT_printf :p: %p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: %16p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %16p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: %20p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %20p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: *%-20p*\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: *%-20p*\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: %+20p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %20p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: %0+20p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %20p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: % 20p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %20p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: %.20p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %p\n\n", str));
	// ft_putnbr_positif(ft_printf("FT_printf :p: %5.20p\n", str));
	// ft_putnbr_positif(printf("Prinft    :p: %5p\n\n", str));
	// ft_putnbr_positif(ft_printf("Prinft    :p: %p\n", NULL));
	// ft_putnbr_positif(printf("Prinft    :p: %p\n", NULL));
	// ft_putnbr_positif(ft_printf("Prinft    :p: %p\n", (void*)0));
	// ft_putnbr_positif(printf("Prinft    :p: %p\n", (void*)0));

	///*************** TEST c ****************///
	// ft_printf("FT - Test  c: %c  \n", charac);
	// printf("PF - Test  c: %c  \n", charac);
	// ft_printf("FT - Test  c: %lc  \n", charac);
	// printf("PF - Test  c: %lc  \n", charac);
	// ft_printf("FT - Test  c: %c  \n", charac);
	// printf("PF - Test  c: %c  \n", charac);
	//
	// ft_printf("FT - Test  c: %.0c  \n", charac);
	// printf("PF - Test  c: %c  \n", charac);
	// ft_printf("FT - Test  c: %.c  \n", charac);
	// printf("PF - Test  c: %c  \n", charac);
	// ft_printf("FT - Test  c: %5.0c  \n", '\0');
	// ft_printf("FT - Test  c: %.c  \n", '\0');
	// ft_printf("FT - Test  c: %-5c  \n", '\0');
	// ft_printf("FT - Test  c: %8lc  \n", '\0');
	// printf("PF - Test  c: %5c  \n", '\0');
	// printf("PF - Test  c: %c  \n", '\0');
	// printf("PF - Test  c: %-5c  \n", '\0');
	// printf("PF - Test  c: %8lc  \n\n", '\0');
	//
	// ft_putnbr_positif(ft_printf("FT - Test  c: %5.0c  \n", '\0'));
	// ft_putnbr_positif(ft_printf("FT - Test  c: %.c  \n", '\0'));
	// ft_putnbr_positif(ft_printf("FT - Test  c: %-5c  \n", '\0'));
	// ft_putnbr_positif(ft_printf("FT - Test  c: %8lc  \n", '\0'));
	// ft_putnbr_positif(printf("PF - Test  c: %5c  \n", '\0'));
	// ft_putnbr_positif(printf("PF - Test  c: %c  \n", '\0'));
	// ft_putnbr_positif(printf("PF - Test  c: %-5c  \n", '\0'));
	// ft_putnbr_positif(printf("PF - Test  c: %8lc  \n\n", '\0'));
	//
	// ft_printf("FT - Test  c: %.c  \n", 'b');
	// ft_printf("FT - Test  c: %-5c  \n", 'b');
	// ft_printf("FT - Test  c: %8lc  \n", 'b');
	// printf("PF - Test  c: %c  \n", 'b');
	// printf("PF - Test  c: %-5c  \n", 'b');
	// printf("PF - Test  c: %8lc  \n", 'b');
	//
	// ft_printf("FT - Test  c: %.25lc  \n", charac);
	// printf("PF - Test  c: %lc  \n", charac);
	//
	// ft_printf("FT - Test  c: %05c  \n", charac);
	// printf("PF - Test  c: %5c  \n", charac);
	// ft_printf("FT - Test  c: %8c  \n", charac);
	// printf("PF - Test  c: %8c  \n", charac);
	// ft_printf("FT - Test  c: *%-05c* \n", charac);
	// printf("PF - Test  c: *%-5c* \n\n", charac);
	//
	// ft_printf("FT - Test -+8c: *%-+8c* \n", charac);
	// printf("PF - Test  -8c: *%-8c* \n\n", charac);
	//
	// ft_printf("FT - Test  +5c: *%+5c* \n", charac);
	// printf("PF - Test   5c: *%5c* \n\n", charac);
	// ft_printf("FT - Test  +9c: *%+9c* \n", charac);
	// printf("PF - Test   9c: *%9c* \n\n", charac);
	// ft_printf("FT - Test  c: *%+5c* \n", charac);
	// printf("PF - Test  c: *%5c* \n", charac);
	//
	// ft_printf("FT - Test  c: *%.5c* \n", 0);
	// printf("PF - Test  c: *%c* \n", 0);
	//
	// ft_printf("FT - Test   0 8c: *%0 8c* \n", charac);
	// printf("PF - Test     8c: *%8c* \n\n", charac);
	// ft_printf("FT - Test  +0 8c: *%+0 8c* \n", charac);
	// printf("PF - Test    8c : *%8c* \n\n", charac);
	// ft_printf("FT - Test   + 8c: *%+ 8c* \n", charac);
	// ft_printf("FT - Test    +8c: *%+8c* \n", charac);
	// printf("PF - Test    8c : *%8c* \n\n", charac);
	// ft_printf("FT - Test   -+8c : *%-+8c* \n", charac);
	// printf("PF - Test    -8c : *%-8c* \n\n", charac);
	// ft_printf("FT - Test   -+ 8c : *%-+ 8c* \n", charac);
	// printf("PF - Test     -8c : *%-8c* \n\n", charac);
	//
	// ft_printf("FT - Test   +c : *%+c* \n", charac);
	// printf("PF - Test    c : *%c* \n\n", charac);
	// ft_printf("FT - Test   +-c : *%-c* \n", charac);
	// printf("PF - Test   +-c : *%-c* \n\n", charac);
	// ft_printf("FT - Test   0c : *%0c* \n", charac);
	// printf("PF - Test    c : *%c* \n\n", charac);
	// ft_printf("FT - Test   c : *% c* \n", charac);
	// printf("PF - Test   c : *%c* \n\n", charac);
	// ft_printf("FT - Test   c : *% 10c* \n", charac);
	// printf("PF - Test   c : *%10c* \n\n", charac);
	// ft_putnbr_positif(printf("%c\n", 0));
	// ft_putnbr_positif(ft_printf("%c\n", 0));

	///*************** TEST C ****************///
	// ft_printf("FT - Test  C: %C  \n", wcharac);
	// printf("PF - Test  C: %C  \n", wcharac);
	// ft_printf("FT - Test  C: %C  \n", C);
	// printf("PF - Test  C: %C  \n", C);
	// ft_printf("FT - Test  C: %C  \n", C2);
	// printf("PF - Test  C: %C  \n", C2);
	// ft_printf("FT - Test  C: %C  \n", C3);
	// printf("PF - Test  C: %C  \n", C3);
	// ft_printf("FT - Test  C: %C  \n", C4);
	// printf("PF - Test  C: %C  \n\n", C4);

	// ft_printf("FT - Test  C: *%8C*  \n", C);
	// printf("PF - Test  C: *%8C*  \n", C);
	// ft_printf("FT - Test  C: *%8C*  \n", C1);
	// printf("PF - Test  C: *%8C*  \n", C1);
	// ft_printf("FT - Test  C: *%8C*  \n", C2);
	// printf("PF - Test  C: *%8C*  \n", C2);
	// ft_printf("FT - Test  C: *%8C*  \n", C3);
	// printf("PF - Test  C: *%8C*  \n", C3);
	// ft_printf("FT - Test  C: *%8C*  \n", C4);
	// printf("PF - Test  C: *%8C*  \n\n", C4);
	// printf("***********/////////************\n");
	// ft_printf("FT - Test  C: *%8C*  \n", C5);
	// printf("PF - Test  C: *%8C*  \n", C5);
	// ft_printf("FT - Test  C: *%8C*  \n", C6);
	// printf("PF - Test  C: *%8C*  \n", C6);
	// ft_printf("FT - Test  C: *%-8C*  \n", C);
	// printf("PF - Test  C: *%-8C*  \n", C);
	// ft_printf("FT - Test  C: *%-8C*  \n", C2);
	// printf("PF - Test  C: *%-8C*  \n", C2);
	// ft_printf("FT - Test  C: *%-8C*  \n", C3);
	// printf("PF - Test  C: *%-8C*  \n", C3);
	// ft_printf("FT - Test  C: *%-8C*  \n", C4);
	// printf("PF - Test  C: *%-8C*  \n\n", C4);

	// ft_printf("FT - Test  C: %.0C  \n", wcharac);
	// printf("PF - Test  C: %C  \n", wcharac);
	// ft_printf("FT - Test  C: %.C  \n", wcharac);
	// printf("PF - Test  C: %C  \n", wcharac);
	// printf("***********/////////************\n");
	// ft_printf("FT - Test  C: %5.0C et %c  \n", '\0', 'b');
	// printf("PF - Test  C: %5C et %c  \n", '\0', 'b');
	// ft_printf("FT - Test  C: %.C et %c  \n", '\0', 'b');
	// printf("PF - Test  C: %C et %c  \n", '\0', 'b');
	// ft_printf("FT - Test  C: %-5C et %c  \n", '\0', 'b');
	// printf("PF - Test  C: %-5C et %c  \n", '\0', 'b');
	// ft_printf("FT - Test  C: %8C et %c  \n", '\0', 'b');
	// printf("PF - Test  C: %8C et %c  \n", '\0', 'b');
	//
	// printf("***********/////////************\n");
	// ft_printf("FT - Test  C: %5C et %c  \n", '\0', 'b');
	// printf("PF - Test  C: %5C et %c  \n", '\0', 'b');
	// ft_printf("FT - Test  C: %c  \n", 'b');
	// printf("FT - Test  C: %c  \n", 'b');
	// printf("***********/////////************\n");
	// ft_putnbr_positif(ft_printf("FT - Test1  C: %5.0C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(ft_printf("FT - Test2  C: %.C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(ft_printf("FT - Test3  C: %-5C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(ft_printf("FT - Test4  C: %8C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(printf("PF - Test1  C: %5C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(printf("PF - Test2  C: %C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(printf("PF - Test3  C: %-5C et %c  \n", '\0', 'b'));
	// ft_putnbr_positif(printf("PF - Test4  C: %8C et %c  \n\n", '\0', 'b'));
// printf("***********/////////************\n");
// 	ft_printf("FT - Test5  C: %.C  \n", C2);
// 	ft_printf("FT - Test6  C: %-5C  \n", C2);
// 	ft_printf("FT - Test7  C: %8C  \n", C2);
// 	printf("PF - Test5  C: %C  \n", C2);
// 	printf("PF - Test6  C: %-5C  \n", C2);
// 	printf("PF - Test7  C: %8C  \n", C2);
// printf("***********/////////************\n");
	// ft_printf("FT - Test  C: %.25lC  \n", wcharac);
	// printf("PF - Test  C: %C  \n", wcharac);
	// ft_printf("FT - Test  C: %05C  \n", wcharac);
	// printf("PF - Test  C: %5C  \n", wcharac);
	// ft_printf("FT - Test  C: %8C  \n", wcharac);
	// printf("PF - Test  C: %8C  \n", wcharac);
	// ft_printf("FT - Test  C: *%-05C* \n", wcharac);
	// printf("PF - Test  C: *%-5C* \n\n", wcharac);
	//
	// ft_printf("FT - Test -+8C: *%-+8C* \n", wcharac);
	// printf("PF - Test  -8C: *%-8C* \n\n", wcharac);
	//
	// ft_printf("FT - Test  +5C: *%+5C* \n", wcharac);
	// printf("PF - Test   5C: *%5C* \n\n", wcharac);
	// ft_printf("FT - Test  +9C: *%+9C* \n", wcharac);
	// printf("PF - Test   9C: *%9C* \n\n", wcharac);
	// ft_printf("FT - Test  C: *%+5C* \n", wcharac);
	// printf("PF - Test  C: *%5C* \n", wcharac);
	//
	// ft_printf("FT - Test  C: *%.5C* \n", 0);
	// printf("PF - Test  C: *%C* \n", 0);
	//
	// ft_printf("FT - Test   0 8C: *%0 8C* \n", wcharac);
	// printf("PF - Test     8C: *%8C* \n\n", wcharac);
	// ft_printf("FT - Test  +0 8C: *%+0 8C* \n", wcharac);
	// printf("PF - Test    8c : *%8C* \n\n", wcharac);
	// ft_printf("FT - Test   + 8C: *%+ 8C* \n", wcharac);
	// ft_printf("FT - Test    +8C: *%+8C* \n", wcharac);
	// printf("PF - Test    8C : *%8C* \n\n", wcharac);
	// ft_printf("FT - Test   -+8C : *%-+8C* \n", wcharac);
	// printf("PF - Test    -8C : *%-8C* \n\n", wcharac);
	// ft_printf("FT - Test   -+ 8C : *%-+ 8C* \n", wcharac);
	// printf("PF - Test     -8C : *%-8C* \n\n", wcharac);
// printf("***********/////////************\n");
// 	ft_printf("FT - Test   +C : *%+C* \n", wcharac);
// 	printf("PF - Test    C : *%C* \n\n", wcharac);
// 	ft_printf("FT - Test   +-C : *%-C* \n", wcharac);
// 	printf("PF - Test   +-C : *%-C* \n\n", wcharac);
// 	ft_printf("FT - Test   0C : *%0C* \n", wcharac);
// 	printf("PF - Test    C : *%C* \n\n", wcharac);
// 	ft_printf("FT - Test   C : *% C* \n", wcharac);
// 	printf("PF - Test   C : *%C* \n\n", wcharac);
	// printf("***********/////////************\n");
	// ft_printf("FT - Test   C : *% 10C* \n", wcharac);
	// printf("PF - Test   C : *%10C* \n\n", wcharac);

	///*************** TEST s ****************///

	// ft_printf("FT - Test  s: %s  \n", "salut ca va?");
	// printf("PF - Test  s: %s  \n", "salut ca va?");
	// ft_printf("FT - Test  s: %5s  \n", "salut ca va?");
	// printf("PF - Test  s: %5s  \n", "salut ca va?");
	// ft_printf("FT - Test  s: %.6s  \n", "salut ca va?");
	// printf("PF - Test  s: %.6s  \n", "salut ca va?");
	// ft_printf("FT - Test  s: %-30s  \n", "salut ca va?");
	// printf("PF - Test  s: %-30s  \n", "salut ca va?");
	//
	//
	// ft_printf("FT - Test  s: %.s  \n", "salut ca va?");
	// printf("PF - Test  s: %.s  \n", "salut ca va?");
	// ft_printf("FT - Test  s: %.0s  \n", "salut ca va?");
	// printf("PF - Test  s: %.0s  \n", "salut ca va?");
	// ft_printf("FT - Test  s: %.1s  \n", "salut ca va?");
	// printf("PF - Test  s: %.1s  \n", "salut ca va?");
	// ft_printf("FT - Test  s: %.0s  \n", "");
	// printf("PF - Test  s: %.0s  \n", "");
	// ft_printf("FT - Test  s: %s  \n", NULL);
	// ft_printf("FT - Test  s: %s  \n", (void*)0);

	///*************** TEST S ****************///

	// wchar_t *wstr;
	// wchar_t *wnull;
	// wstr = L"Slt Éloïse !☂ ❤ ☯";
	// wnull = L"";
	// ft_printf("FT - Test  S: %S  \n", wstr);
	// printf("PF - TeSt  S: %S  \n\n", wstr);
	// ft_printf("FT - Test  S: *%.10S*  \n", wstr);
	// printf("PF - TeSt  S: *%.10S* \n\n", wstr);
	// ft_printf("FT - Test  S: *%.11S*  \n", wstr);
	// printf("PF - TeSt  S: *%.11S* \n\n", wstr);
	// ft_printf("FT - Test  S: *%.12S*  \n", wstr);
	// printf("PF - TeSt  S: *%.12S* \n\n", wstr);
	// ft_printf("FT - Test 13 S: *%.13S*  \n", wstr);
	// printf("PF - TeSt  13S: *%.13S* \n\n", wstr);
	// ft_printf("FT - Test  S: *%.14S*  \n", wstr);
	// printf("PF - TeSt  S: *%.14S* \n\n", wstr);
	// ft_printf("FT - Test  15S: *%.15S*  \n", wstr);
	// printf("PF - TeSt  15S: *%.15S*  \n\n", wstr);
	// ft_printf("FT - Test  16S: *%.16S*  \n", wstr);
	// printf("PF - TeSt  16S: *%.16S*  \n\n", wstr);
	// ft_printf("FT - Test  17S: *%.17S*  \n", wstr);
	// printf("PF - TeSt  17S: *%.17S*  \n\n", wstr);
	// ft_printf("FT - Test  18S: *%.18S*  \n", wstr);
	// printf("PF - TeSt  18S: *%.18S*  \n\n", wstr);
	// ft_printf("FT - Test  19S: *%.19S*  \n", wstr);
	// printf("PF - TeSt  19S: *%.19S*  \n\n", wstr);
	// ft_printf("FT - Test  20S: *%.20S*  \n", wstr);
	// printf("PF - TeSt  20S: *%.20S*  \n\n", wstr);
	// ft_printf("FT - Test  25S: *%.25S*  \n", wstr);
	// printf("PF - TeSt  25S: *%.25S*  \n\n", wstr);
	// ft_printf("FT - Test  25S: *%.5S*  \n", wstr);
	// printf("PF - TeSt  5S: *%.5S*  \n\n", wstr);
	// ft_printf("FT - Test  0S: *%.0S*  \n", wstr);
	// printf("PF - TeSt  0S: *%.0S*  \n\n", wstr);
	// ft_printf("FT - Test  S: %.S  \n", wstr);
	// printf("PF - TeSt  S: %.S  \n\n", wstr);
	// ft_printf("FT - Test  S: %.0S  \n", wnull);
	// printf("PF - TeSt  S: %.0S  \n\n", wnull);
	// ft_printf("FT - Test  S: %.5S  \n", wnull);
	// printf("PF - TeSt  S: %.5S  \n\n", wnull);
	// ft_printf("FT - Test  S: %.S  \n", wnull);
	// printf("PF - TeSt  S: %.S  \n\n", wnull);
	// ft_printf("FT - Test  S: %S  \n", wnull);
	// printf("PF - TeSt  S: %S  \n\n", wnull);
	// printf("***********/////////************\n");
	// ft_printf("FT - TeSt  S: %5S  \n", wstr);
	// printf("PF - TeSt  S: %5S  \n", wstr);
	// ft_printf("FT - TeSt  S: %.6S  \n", wstr);
	// printf("PF - TeSt  S: %.6S  \n", wstr);
	// ft_printf("FT - TeSt  S: %-30S  \n", wstr);
	// printf("PF - TeSt  S: %-30S  \n", wstr);
	//
	//
	// ft_printf("FT - TeSt  S: %.S  \n", wstr);
	// printf("PF - TeSt  S: %.S  \n", wstr);
	// ft_printf("FT - TeSt  S: %.0S  \n", wstr);
	// printf("PF - TeSt  S: %.0S  \n", wstr);
	// ft_printf("FT - TeSt  S: %.1S  \n", wstr);
	// printf("PF - TeSt  S: %.1S  \n", wstr);
	//
	// ft_printf("FT - TeSt  S: %.0S  \n", wnull);
	// printf("PF - TeSt  S: %.0S  \n", wnull);
	// ft_printf("FT - TeSt  S: %.S  \n", wnull);
	// printf("PF - TeSt  S: %.S  \n", wnull);
	// printf("***********/////////************\n");
	// ft_printf("FT - TeSt  S: *%20S*  \n", wstr);
	// printf("PF - TeSt  S: *%20S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%21S*  \n", wstr);
	// printf("PF - TeSt  S: *%21S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%22S*  \n", wstr);
	// printf("PF - TeSt  S: *%22S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%23S*  \n", wstr);
	// printf("PF - TeSt  S: *%23S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%24S*  \n", wstr);
	// printf("PF - TeSt  S: *%24S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%25lS*  \n", wstr);
	// printf("PF - TeSt  S: *%25s*  \n", "Slt Éloïse !☂ ❤ ☯");
	// ft_printf("FT - TeSt  S: *%26lS*  \n", wstr);
	// printf("PF - TeSt  S: *%26s*  \n", "Slt Éloïse !☂ ❤ ☯");
	// ft_printf("FT - TeSt  S: *%27lS*  \n", wstr);
	// printf("PF - TeSt  S: *%27s*  \n", "Slt Éloïse !☂ ❤ ☯");
	// ft_printf("FT - TeSt  S: *%28lS*  \n", wstr);
	// printf("PF - TeSt  S: *%28s*  \n", "Slt Éloïse !☂ ❤ ☯");
	// ft_printf("FT - TeSt  S: *%29lS*  \n", wstr);
	// printf("PF - TeSt  S: *%29s*  \n", "Slt Éloïse !☂ ❤ ☯");
	// ft_printf("FT - TeSt  S: *%30lS*  \n", wstr);
	// printf("PF - TeSt  S: *%30s*  \n", "Slt Éloïse !☂ ❤ ☯");
	// ft_printf("FT - TeSt  S: *%30S*  \n", wstr);
	// printf("PF - TeSt  S: *%30S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%31S*  \n", wstr);
	// printf("PF - TeSt  S: *%31S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%32S*  \n", wstr);
	// printf("PF - TeSt  S: *%32S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%33S*  \n", wstr);
	// printf("PF - TeSt  S: *%33S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%34S*  \n", wstr);
	// printf("PF - TeSt  S: *%34S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%35S*  \n", wstr);
	// printf("PF - TeSt  S: *%35S*  \n", wstr);
	// ft_printf("FT - TeSt  S: *%40S*  \n", wstr);
	// printf("PF - TeSt  S: *%40S*  \n", wstr);
	//
	//
	// ft_putnbr_positif(ft_printf("FT - Test  s: %.S  \n", wstr));
	// ft_putnbr_positif(printf("PF - Test  s: %.S  \n", wstr));
	// ft_putnbr_positif(ft_printf("FT - Test  s: %.0S  \n", wstr));
	// ft_putnbr_positif(printf("PF - Test  s: %.0S  \n", wstr));
	//
	//
	// ft_printf("FT - Test  s: %.8S  \n", wstr);
	// printf("PF - Test  s: %.8S  \n", wstr);
	// ft_printf("FT - Test  s: %10.8S  \n", wstr);
	// printf("PF - Test  s: %10.8S  \n", wstr);
	// ft_printf("FT - Test  s: %10.S  \n", wstr);
	// printf("PF - Test  s: %10.S  \n", wstr);
	// ft_printf("FT - Test  s: %10.0S  \n", wstr);
	// printf("PF - Test  s: %10.0S  \n", wstr);
	// ft_printf("FT - Test  s: *%-10S*  \n", wstr);
	// printf("PF - Test  s: *%-10S*  \n\n", wstr);
	//
	// ft_printf("FT - Test  s: *%-40S*  \n", wstr);
	// printf("PF - Test  s: *%-40S*  \n", wstr);
	// ft_printf("FT - Test  s: *%-40.8S*  \n", wstr);
	// printf("PF - Test  s: *%-40.8S*  \n", wstr);
	// ft_printf("FT - Test  s: *%-30S*  \n", wstr);
	// printf("PF - Test  s: *%-30S*  \n", wstr);
	// ft_printf("FT - Test  s: *%-35.10S*  \n", wstr);
	// printf("PF - Test  s: *%-35.10S*  \n", wstr);

	ft_printf("FT - Test  s: %s  \n", str);
	printf("PF - Test  s: %s  \n", str);
	ft_printf("FT - Test  c: %c  \n", 'a');
	printf("PF - Test  c: %c  \n", 'a');
	ft_printf("FT - Test  p: %p  \n", str);
	printf("PF - Test  p: %p  \n", str);

	ft_printf("FT - Test  i: %i  \n", 123456);
	printf("PF - Test  i: %i  \n", 123456);
	ft_printf("FT_printf :u: %u\n", u);
	printf("PF_printf :u: %u\n", u);
	ft_printf("FT_printf :o: %o - O:%O\n", o, O);
	printf("Prinft    :o: %o - O:%lo\n\n", o, O);
	ft_printf("FT_printf :x: %x - X:%X\n", x, X);
	printf("Prinft    :x: %x - X:%X\n\n", x, X);
	return (0);
}
