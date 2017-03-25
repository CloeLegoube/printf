/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:23:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/25 19:51:05 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	// ft_printf("+- 5lperc %+- 5l%\n");
	// ft_printf("percperc %%\n");
	// ft_printf(" 0+5hs % 0+5hs\n");
	// ft_printf("-5.36hhS %-5.36hhS\n");
	// ft_printf("-.36jp %-.36jp\n");
	// ft_printf("0-+#zd %0-+#zd\n");
	// ft_printf("15.lD %15.lD\n");
	// ft_printf("#15.0lli %#15.0lli\n");
	// ft_printf("0#-5lo %0#-5lo\n");
	// ft_printf(".hhO %.hhO\n");
	// ft_printf("#.ju %#.ju\n");
	// ft_printf("0#23.5zU %0#23.5zU\n");
	// ft_printf("- .5x %- .5x\n");
	// ft_printf(".5X %.5X\n");
	// ft_printf("+.c %+.c\n");
	// ft_printf("0X %0X\n");


	// ft_printf("%5%\n");
	// printf("%5c\n", '%');
	// printf("\n");
	// ft_printf("%-5%\n");
	// printf("%-5c\n", '%');
	// printf("\n");
	// ft_printf("%x\n", -42);
	// printf("%x\n", -42);
	// printf("\n");
	// ft_printf("%X\n", -42);
	// printf("%X\n", -42);
	// printf("\n");
	// ft_printf("%x\n", 4294967296);
	// printf("%lx\n", 4294967296); // lx
	// printf("\n");
	// ft_printf("%X\n", 4294967296);
	// printf("%lX\n", 4294967296); // Lx
	// printf("\n");
	// ft_printf("%10x\n", 42);
	// printf("%10x\n", 42);
	// printf("\n");
	// ft_printf("%-10x\n", 42);
	// printf("%-10x\n", 42);
	// printf("\n");
	// ft_printf("%010x\n", 542);
	// printf("%010x\n", 542);
	// printf("\n");
	// ft_printf("%-15x\n", 542);
	// printf("%-15x\n", 542);
	// printf("\n");
	// ft_printf("%5.2x\n", 5427);
	// printf("%5.2x\n", 5427);
	// printf("\n");
	// ft_printf("%#8x\n", 42);
	// printf("%#8x\n", 42);
	// printf("\n");
	// ft_printf("%#08x\n", 42);
	// printf("%#08x\n", 42);
	// printf("\n");
	// ft_printf("%#-08x\n", 42);
	// printf("%#-8x\n", 42);  // 0 ignore
	// printf("\n");
	// ft_printf("@moulitest: *%#.x* *%#.0x*\n", 0, 0);
	// printf("@moulitest: *%#.x* *%#.0x*\n", 0, 0);
	// printf("\n");
	// ft_printf("@moulitest: *%.x* *%.0x*\n", 0, 0);
	// printf("@moulitest: *%.x* *%.0x*\n", 0, 0);
	// printf("\n");
	// ft_printf("@moulitest: *%5.x* *%5.0x*\n", 0, 0);
	// printf("@moulitest: *%5.x* *%5.0x*\n", 0, 0);
	// printf("\n");
	// ft_printf("%10s is a string\n", "this");
	// printf("%10s is a string\n", "this");
	// printf("\n");
	// ft_printf("%.2s is a string\n", "this");
	// printf("%.2s is a string\n", "this");
	// printf("\n");
	// ft_printf("%5.2s is a string\n", "this");
	// printf("%5.2s is a string\n", "this");
	// printf("\n");
	// ft_printf("%10s is a string\n", "");
	// printf("%10s is a string\n", "");
	// printf("\n");
	// ft_printf("%5.2s is a string\n", "");
	// printf("%5.2s is a string\n", "");
	// printf("\n");
	// ft_printf("%-10s is a string\n", "this");
	// printf("%-10s is a string\n", "this");
	// printf("\n");
	// ft_printf("%-.2s is a string\n", "this");
	// printf("%-.2s is a string\n", "this");
	// printf("\n");
	// ft_printf("%-5.2s is a string\n", "this");
	// printf("%-5.2s is a string\n", "this");
	// printf("\n");
	// ft_printf("%-10s is a string\n", "");
	// printf("%-10s is a string\n", "");
	// printf("\n");
	// ft_printf("%-5.2s is a string\n", "");
	// printf("%-5.2s is a string\n", "");
	// printf("\n");
	// ft_printf("%5c\n", 42);
	// printf("%5c\n", 42);
	// printf("\n");
	// ft_printf("%-5c\n", 42);
	// printf("%-5c\n", 42);
	// printf("\n");
	// ft_printf("%2c\n", 0);
	// printf("%2c\n", 0);
	// printf("\n");
	// ft_printf("%5o\n", 41);
	// printf("%5o\n", 41);
	// printf("\n");
	// ft_printf("%05o\n", 42);
	// printf("%05o\n", 42);
	// printf("\n");
	// ft_printf("%-5o\n", 2500);
	// printf("%-5o\n", 2500);
	// printf("\n");
	// ft_printf("%#6o\n", 2500);
	// printf("%#6o\n", 2500);
	// printf("\n");
	// ft_printf("%-#6o\n", 2500);
	// printf("%-#6o\n", 2500);
	// printf("\n");
	// ft_printf("%-05o\n", 2500);
	// printf("%-5o\n", 2500); // 0 ignore avec le -
	// printf("\n");
	// ft_printf("%-5.10o\n", 2500);
	// printf("%-5.10o\n", 2500);
	// printf("\n");
	// ft_printf("%-10.5o\n", 2500);
	// printf("%-10.5o\n", 2500);
	// printf("\n");
	// ft_printf("@moulitest: *%.o* *%.0o*\n", 0, 0);
	// printf("@moulitest: *%.o* *%.0o*\n", 0, 0);
	// printf("\n");
	// ft_printf("@moulitest: *%5.o* *%5.0o*\n", 0, 0);
	// printf("@moulitest: *%5.o* *%5.0o*\n", 0, 0);
	// printf("\n");
	// printf("*****************************************************\n");
	// printf("***************         Avec le HTAG      ***********\n");
	// printf("*****************************************************\n");
	// ft_printf("@moulitest--: *%#.o* *%#.0o*\n", 0, 0);
	// printf("@moulitest--: *%#.o* *%#.0o*\n", 0, 0);
	// printf("*****************************************************\n");
	// printf("***************         Sans le HTAG      ***********\n");
	// printf("*****************************************************\n");
	// ft_printf("@moulitest--: *%.o* *%.0o*\n", 0, 0);
	// printf("@moulitest--: *%.o* *%.0o*\n", 0, 0);
	// printf("\n");
	// ft_printf("@moulitest: %.10o\n", 42);
	// printf("@moulitest: %.10o\n", 42);
	// printf("\n");
	// ft_printf("% d\n", -42);
	// printf("% d\n", -42);
	// printf("\n");
	// ft_printf("% +d\n", 42);
	// printf("%+d\n", 42); // espace ignore avec le +
	// printf("\n");
	// ft_printf("% +d\n", -42);
	// printf("%+d\n", -42);
	// printf("\n");
	// ft_printf("%+ d\n", 42);
	// printf("%+d\n", 42);
	// printf("\n");
	// ft_printf("%+ d\n", -42);
	// printf("%+d\n", -42);
	// printf("\n");
	// ft_printf("%  +d\n", 42);
	// printf("%+d\n", 42);
	// printf("\n");
	// ft_printf("%  +d\n", -42);
	// printf("%+d\n", -42);
	// printf("\n");
	// ft_printf("%+  d\n", 42);
	// printf("%+d\n", 42);
	// printf("\n");
	// ft_printf("%+  d\n", -42);
	// printf("%+d\n", -42);
	// printf("\n");
	// ft_printf("% ++d\n", 42);
	// printf("%+d\n", 42);
	// printf("\n");
	// ft_printf("% ++d\n", -42);
	// printf("%+d\n", -42);
	// printf("\n");
	// ft_printf("%++ d\n", 42);
	// printf("%+d\n", 42);
	// printf("\n");
	// ft_printf("%++ d\n", -42);
	// printf("%+d\n", -42);
	// printf("\n");
	// ft_printf("%5d\n", 42);
	// printf("%5d\n", 42);
	// printf("\n");
	// ft_printf("%05d\n", 42);
	// printf("%05d\n", 42);
	// printf("\n");
	// ft_printf("%0+5d\n", 42);
	// printf("%0+5d\n", 42);
	// printf("\n");
	// ft_printf("%5d\n", -42);
	// printf("%5d\n", -42);
	// printf("\n");
	// ft_printf("%05d\n", -42);
	// printf("%05d\n", -42);
	// printf("\n");
	// ft_printf("%0+5d\n", -42);
	// printf("%0+5d\n", -42);
	// printf("\n");
	// ft_printf("%-5d\n", 42);
	// printf("%-5d\n", 42);
	// printf("\n");
	// ft_printf("%-05d\n", 42);
	// printf("%-5d\n", 42); // 0 ignore
	// printf("\n");
	// ft_printf("%-5d\n", -42);
	// printf("%-5d\n", -42);
	// printf("\n");
	// ft_printf("%-05d\n", -42);
	// printf("%-5d\n", -42); // 0 ignore
	// printf("\n");
	// ft_printf("%4.15d\n", 42);
	// printf("%4.15d\n", 42);
	// printf("\n");
	// ft_printf("%.10d\n", 4242);
	// printf("%.10d\n", 4242);
	// printf("\n");
	// ft_printf("%10.5d\n", 4242);
	// printf("%10.5d\n", 4242);
	// printf("\n");
	// ft_printf("%-10.5d\n", 4242);
	// printf("%-10.5d\n", 4242);
	// printf("\n");
	// ft_printf("% 10.5d\n", 4242);
	// printf("% 10.5d\n", 4242);
	// printf("\n");
	// ft_printf("%+10.5d\n", 4242);
	// printf("%+10.5d\n", 4242);
	// printf("\n");
	// ft_printf("%-+10.5d\n", 4242);
	// printf("%-+10.5d\n", 4242);
	// printf("\n");
	// ft_printf("%03.2d\n", 0);
	// printf("%3.2d\n", 0); // o et precision
	// printf("\n");
	// ft_printf("%03.2d\n", 1);
	// printf("%3.2d\n", 1);
	// printf("\n");
	// ft_printf("%03.2d\n", -1);
	// printf("%3.2d\n", -1);
	// printf("\n");
	// ft_printf("@moulitest: %.10d\n", -42);
	// printf("@moulitest: %.10d\n", -42);
	// printf("\n");
	// ft_printf("@moulitest: *%.d* *%.0d*\n", 0, 0);
	// printf("@moulitest: *%.d* *%.0d*\n", 0, 0);
	// printf("\n");
	// ft_printf("@moulitest: *%5.d* *%5.0d*\n", 0, 0);
	// printf("@moulitest: *%5.d* *%5.0d*\n", 0, 0);
	// printf("\n");
	// ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	// printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	// printf("\n");
	// ft_printf("string -1 = %u\n", -1);
	// printf("string -1 = %u\n",-1); // u => s
	// printf("\n");
	// ft_printf("FT -1 %u\n", -1);
	// printf("PF -1 %u\n", -1);
	// printf("\n");
	// ft_printf("4294967296 ==> %u\n", 4294967296);
	// printf("4294967296 ==> %ld\n", 4294967296); // u => s
	// printf("\n");
	// unsigned int uu1;
	// unsigned int uu2;
	// long uu3;
	// uu1 = 4294967295;
	// uu3 = 4294967295;
	// uu2 = (unsigned int)4294967296;
	// ft_printf("%u\n", uu2);
	// printf("%u\n", uu2); // u => s
	// printf("\n");
	// ft_printf("%15u\n", uu1);
	// printf("%15u\n", uu1); // u => s
	// printf("\n");
	// ft_printf("%-15u\n", uu1);
	// printf("%-15u\n", uu1); // u => s
	// printf("\n");
	// ft_printf("%015u\n", uu1);
	// printf("%015u\n", uu1); // u => s et 0 ignore
	// printf("\n");
	// ft_printf("%015u\n", uu2);
	// printf("%015u\n", uu2); // u => ld
	// printf("\n");
	// ft_printf("@moulitest: %.5u\n", 42);
	// printf("@moulitest: %.5u\n", 42); // u => s

	// # 0016 (int)
	//   ft_printf("%x", -42);
	//   1. (   16) -->ffffffffffffffd6<--
	//   2. (    8) -->ffffffd6<--
	//
	// # 0017 (int)
	//   ft_printf("%X", -42);
	//   1. (   16) -->FFFFFFFFFFFFFFD6<--
	//   2. (    8) -->FFFFFFD6<--
	//
	// # 0018 (int)
	//   ft_printf("%x", 4294967296);
	//   1. (    9) -->100000000<--
	//   2. (    1) -->0<--
	//
	// # 0019 (int)
	//   ft_printf("%X", 4294967296);
	//   1. (    9) -->100000000<--
	//   2. (    1) -->0<--
	//
	// # 0044 (int)
	//   ft_printf("%#08x", 42);
	//   1. (    8) -->00000x2a<--
	//   2. (    8) -->0x00002a<--
	//
	// # 0167 (int)
	//   ft_printf("% 10.5d", 4242);
	//   1. (   11) -->      04242<--
	//   2. (   10) -->     04242<--
	//
	// # 0179 (unsigned int)
	//   ft_printf("%u", "-1");
	//   1. (   20) -->18446744073709551615<--
	//   2. (   10) -->4294967295<--
	//
	// # 0181 (unsigned int)
	//   ft_printf("%u", "4294967296");
	//   1. (   10) -->4294967296<--
	//   2. (    1) -->0<--

	// printf("\n");
	// ft_printf("%x\n", -42);
	// printf("%x\n", -42);
	// printf("\n");
	// ft_printf("%X\n", -42);
    // printf("%X\n", -42);
	// printf("\n");


	//
	// ft_printf("%x\n", 4294967296);
    // printf("%x\n", (unsigned int)4294967296);
	// printf("\n");
	// ft_printf("%X\n", 4294967296);
	// printf("%X\n", (unsigned int)4294967296);
	// printf("\n");
// 	ft_printf("*%#08x*\n", 42);
//     printf("*%#08x*\n", 42);
// 	ft_printf("*%#-08x*\n", 42);
// 	printf("*%#-8x*\n", 42);
//
// ft_printf("*%-10x*\n", 42);
//   printf("*%-10x*\n", 42);
//   ft_printf("*%010x*\n", 542);
//   printf("*%010x*\n", 542);
//   ft_printf("*%-15x*\n", 542);
//   printf("*%-15x*\n", 542);
//   ft_printf("*%-5o*\n", 2500);
//   printf("*%-5o*\n", 2500);
//   ft_printf("*%-05o*\n", 2500);
//   printf("*%-5o*\n", 2500);
//   ft_printf("*%-5.10o*\n", 2500);
//   printf("*%-5.10o*\n", 2500);
//   ft_printf("*%-10.5o*\n", 2500);
//   printf("*%-10.5o*\n", 2500);

	// printf("\n");
	// ft_printf("% 10.5d\n", 4242);
	// printf("% 10.5d\n", 4242);
	// printf("%10d\n", 4242);
 // 	printf("% 10d\n", 4242);
	// printf("\n");
	// ft_printf("%u\n", -1);
	// printf("4294967295\n");
	// ft_printf("%u\n", 4294967296);
	// printf("%u\n", 4294967296);
	// printf("0\n");
	// ft_printf("%d%d%d%d%d",1, -2, 3, -4, 5);
	// ft_printf("*% Zoooo*");
	// printf("% Zoooo");
	// ft_putchar('\n');
	// ft_printf("*{%}*");
	// printf("{%}");
	// ft_putchar('\n');
	// ft_printf("%p", 0);
	// ft_putchar('\n');
	// printf("%p", (void *)0);

	// printf("ret :%d", ft_printf("111*%s*\n", "222"));
	// printf("\n");
	// printf("ret :%d", printf("111*%s*\n", "222"));

	// ft_printf("%S", L"米");
	// ft_putchar('\n');
	// printf("%S", L"米");
	// ft_putchar('\n');
	// ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// // printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// // L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	// ft_putchar('\n');
	// ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
	// ft_putchar('\n');
	// // printf("a%Sb%sc%S", L"我", "42", L"猫");
	// ft_putchar('\n');
	// ft_printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠');
	// ft_putchar('\n');
	// printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠');
	// ft_printf("{%S}", NULL);
	//
	// printf("{%S}", (wchar_t *)NULL);
	// ft_printf("{%10R}");
	// ft_putchar('\n');
	// // printf("{%10R}");
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_printf("{%30S}", L"我是一只猫。");
	// ft_putchar('\n');
	// printf("{%30S}", L"我是一只猫。");
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_printf("{%-30S}", L"我是一只猫。");
	// ft_putchar('\n');
	// printf("{%-30S}", L"我是一只猫。");


	// ft_printf("%hu, %hu", 0, USHRT_MAX);
	// ft_putchar('\n');
	// printf("%hu, %hu", (unsigned short)0, (unsigned short)USHRT_MAX);
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_printf("%ho, %ho", 0, USHRT_MAX);
	// ft_putchar('\n');
	// printf("%ho, %ho", (unsigned short)0, (unsigned short)USHRT_MAX);
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_printf("%hx, %hx", 0, USHRT_MAX);
	// ft_putchar('\n');
	// printf("%hx, %hx", (unsigned short)0, (unsigned short)USHRT_MAX);
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_printf("%hX, %hX", 0, USHRT_MAX);
	// ft_putchar('\n');
	// printf("%hX, %hX", (unsigned short)0, (unsigned short)USHRT_MAX);

	//
	// ft_putchar('\n');
	// ft_printf("{%03c}", 0);
	//
	// printf("{%3c}", 0);
	// ft_putchar('\n');
	// ft_printf("{%030S}", L"我是一只猫。");
	// ft_putchar('\n');
	// printf("{%030S}", L"我是一只猫。");
	// ft_putchar('\n');
	// ft_printf("{%05p}", 0);
	// ft_putchar('\n');
	// printf("{%5p}", (void *)0);
	// ft_putchar('\n');
	// ft_printf("111%s", "222");
	// ft_putchar('\n');
	// printf("111%s", "222");
	// ft_printf("{%-15Z}", 123);
	// ft_putchar('\n');
	// printf("{%-15c}", 'Z');
	// // ft_putchar('\n');
	// // ft_printf("%#o", 0);
	// // ft_putchar('\n');
	// // printf("%#o", 0);
	// ft_printf("{%10R}");
	// ft_putchar('\n');
	// printf("{%10c}", 'R');
	// ft_putchar('\n');
	// ft_printf("{%-15p}", 0);
	// ft_putchar('\n');
	// ft_printf("{%05p}", 0);
	// ft_putchar('\n');
	// printf("{%5p}", (void *)0);
	// ft_putchar('\n');
	// ft_printf("{%03c}", 0);
	// printf("{%3c}", 0);
	// ft_putchar('\n');
	// printf("{%3c}", 0);
	// printf("{%10s}", "R");
	// ft_putchar('\n');
	// ft_printf("{%03c}", 0);
	// ft_putchar('\n');
	// printf("{%3c}", 0);
	// ft_printf("%#o\n", 0);
	// printf("%#o\n\n", 0);
	// ft_printf("{% 03d}\n", 0);
	// printf("{% 03d}\n\n", 0);
	// ft_printf("%#.O\n", 0);
	// printf("%#.O\n\n", 0);
	// ft_printf("%#.lo\n", 0);
	// printf("%#.lo\n\n", (unsigned long)0);
	// ft_printf("%.X, %.0X\n", 0, 0);
	// printf("%.X, %.0X\n\n", 0, 0);
	// ft_printf("%.u, %.0u\n", 0, 0);
	// printf("%.u, %.0u\n\n", 0, 0);
	// ft_printf("%jhd\n", 9223372036854775807);
	// ft_printf("%jd\n", 9223372036854775807);
	// printf("%jd\n", 9223372036854775807);
	// ft_printf("%jd\n", "9223372036854775807");
	// ft_printf("%zhd\n", 4294967296);
	// ft_printf("%zd\n", "4294967296");
	// ft_printf("%ll#x\n", 9223372036854775807);
	// ft_printf("%#llx\n", 9223372036854775807);
	// printf("%ll#x\n", 9223372036854775807);
	// ft_printf("%#llx\n", 9223372036854775807);
	// printf("%#llx\n", 9223372036854775807);
	// ft_printf("%hhld\n", 128);
	// printf("%hhld\n", 128);
	// ft_printf("%ld\n", 128);
	// printf("%ld\n", 128);
	// ft_printf("%.4S\n", L"我是一只猫。");
	// printf("%.4S\n\n", L"我是一只猫。");
	// ft_printf("%15.4S\n", L"我是一只猫。");
	// printf("%15.4S\n\n", L"我是一只猫。");
	// ft_printf("%4.15S\n", L"我是一只猫。");
	// printf("%4.15S\n\n", L"我是一只猫。");
	// ft_printf("\n%-#3.6hd|%+06.12hhd|\n", 676, 123456789);
	// printf("\n%-#3.6hd|%+06.12hhd|\n", 676, 123456789);
	// ft_printf("\n-#3.6hd*%-#3.6hd*\n", 676);
	// ft_printf("\n-#.6hd*%-#.6hd*\n", 676);
	// printf("\n-#3.6hd*%-#3.6hd*\n", 676);
	// ft_printf("|%+3D|\n", -435);
	// printf("|%+3lD|\n", -435);
	// ft_printf("|%+06.12hhD|\n", -123456789);
	// printf("|%+06.12hhD|\n", -123456789);
	// ft_printf("|%.0s|\n", "qwerty");
	// printf("|%.0s|\n", "qwerty");
	// ft_printf("%#.o\n", 42);
	// printf("%#.o\n\n", 42);

	// ft_printf("FT - %.0ls\n", L"fasg");
	// printf("PF - %.0ls\n\n", L"fasg");
	// ft_printf("FT - %.ls\n", L"fasg");
	// printf("PF - %.ls\n\n", L"fasg");
	// ft_printf("%.3S\n", NULL);
	// printf("%.3S\n\n", NULL);
	// ft_printf("%.5S\n", L"†œø˙Unicode string");
	// printf("%.5S\n\n", L"†œø˙Unicode string");
	// ft_printf("%c  %C  %5C %5c %5lc\n", 0, 0, 0x20ac, 'x', L'L');
	// printf("%c  %C  %5C %5c %5lc\n\n", 0, 0, 0x20ac, 'x', L'L');
	// ft_printf("*%5C*\n", L'®');
	// printf("*%5C*\n\n", L'®');
	// ft_printf("%--5C\n", L'a');
	// printf("%--5C\n\n", L'a');
	// ft_printf("%p %5p %.2p %.15p %.15p\n", 5, 4896548, 15694, 0, -1);
	// printf("%p %5p %.2p %.15p %.15p\n\n", 5, 4896548, 15694, 0, -1);
	// ft_printf("%48p\n", 587);
	// printf("%48p\n\n", 587);
	// ft_printf("%--.5p\n", 42);
	// printf("%--.5p\n\n", 42);
	// ft_printf("%.5p\n", 42);
	// printf("%.5p\n\n", 42);
	// ft_printf("%9.0p\n", 482);
	// printf("%9.0p\n\n", 482);
	// ft_printf("%.5p\n", 32);
	// printf("%.5p\n\n", 32);
	// ft_printf("%.5p\n", 0);
	// printf("%.5p\n\n", 0);
	ft_printf("%09.0U\n", 482);
	ft_printf("%9.0U\n", 482);
	printf("%09.0U\n\n", 482);
	ft_printf("%#09.0X\n", 482);
	// ft_printf("%#9.0X\n", 482);
	printf("%#09.0X\n\n", 482);
	// printf("%#09.X\n\n", 482);
	// printf("%#09.2X\n\n", 482);
	// printf("%#09.5X\n\n", 482);
	// printf("%#09X\n\n", 482);
	// printf("%09.0X\n\n", 482);
	// printf("%0.0X\n\n", 482);
	ft_printf("%#09.0o\n", 482);
	ft_printf("%#9.0o\n", 482);
	printf("%#09.0o\n\n", 482);


	return (0);
}
