#include "printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int 	main (void)
{
	char c = 'r';
	char *str = "dede";
	int 	nbr = 4444444;
	setlocale(LC_ALL, "");
	wchar_t myChar1 = L'Ω';

	printf("/*******************************************************   TEST D d i   ***************************************************/\n");
	printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);
	ft_printf("|%012d| |%%| |%D| |% i| |%-05d| |%+4d| |%+9.6d| |%-09.0d| |%12d|\n", nbr, 5, -4, 8, 3, 32, 15, -21);

	printf("\n|%+3ld| |%-#3.6hd| |%0.0jd| |%+06.12hhd| |%-07lld| |%#-7.3zd|\n", 5, 676, 8, 123456789, -543, 9876);
	ft_printf("|%+3ld| |%-#3.6hd| |%0.0jd| |%+06.12hhd| |%-07lld| |%#-7.3zd|\n", 5, 676, 8, 123456789, -543, 9876);

	printf("\n |%+3lD| |%-#3.6hD| |%0.0jD| |%+06.12hhD| |%-07llD| |%#-7.3zD|\n", -435, -676, -47478, -123456789, -543, -9876);
	ft_printf("|%+3lD| |%-#3.6hD| |%0.0jD| |%+06.12hhD| |%-07llD| |%#-7.3zD|\n", -435, -676, -47478, -123456789, -543, -9876);


	printf("\n\n/****************************************************   TEST c   *******************************************************/\n");
	printf("%d\n", printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e'));
	ft_printf("%d\n", ft_printf("|%+05.12c| |%+ 4c| |%13c| |%-07c| |%012c| |%#1c|\n", c, 'a', 'b', 'c', 'd', 'e'));

	printf("|%+3c| |%-#3.6hc| |%0.0jc| |%+06.12hhc| |%-07llc| |%#-7.3zc|\n", 'a', 'b', 'c', 'd', 'e', 'f');
	ft_printf("|%+3c| |%-#3.6hc| |%0.0jc| |%+06.12hhc| |%-07llc| |%#-7.3zc|\n", 'a', 'b', 'c', 'd', 'e', 'f');

	printf("|%+3c| |%-#3.6c| |%0.0c| |%+06.12c| |%-07c| |%#-7.3c|\n", 'a', 'b', 'c', 'd', 'e', 'f');
	ft_printf("|%+3c| |%-#3.6c| |%0.0c| |%+06.12c| |%-07c| |%#-7.3c|\n", 'a', 'b', 'c', 'd', 'e', 'f');


	printf("\n\n/*******************************************************   TEST s   *****************************************************/\n");
	printf("%d\n", printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789"));
	ft_printf("%d\n", ft_printf("|%#0.23s| |%3s| |%04s| |%-04s| |%+011s| |%07.2s| |%-8.4s|\n", "salut", "42", "32", "wq", "43", "salut", "123456789"));

	printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");
	ft_printf("|%-#3.6hs| |%0.0js| |%+06.12hhs| |%-07lls| |%#-7.3zs|\n", "qwerty", "qwerty", "qwerty", "qwerty", "qwerty");


	printf("\n\n/******************************************************   TEST x X   ****************************************************/\n");
	printf("%d\n", printf("%x%x%x%x%x%x%x\n", 1, 4, 10, 100, 1000, 10000, 99999999));
	ft_printf("%d\n", ft_printf("%x%x%x%x%x%x%x\n", 1, 4, 10, 100, 1000, 10000, 99999999));
	printf("%d\n", printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.0X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23));
	ft_printf("%d\n", ft_printf("|%x| |%#08x| |%#-08x| |%#x| |%#08.0X| |%#-06x| |%++++++-0-++++06X| |%9.6x|\n", 4, 43, 23, 954, 971, 34, 31, 23));

	printf("%d\n", printf("|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));
	ft_printf("%d\n", ft_printf("|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));

	printf("%d\n", printf("|%+3lX| |%-#3.6hX| |%0.0jX| |%+06.12hhX| |%-07llX| |%#-7.3zX|\n", -435, -676, -47478, -123456789, -543, -9876));
	ft_printf("%d\n", ft_printf("|%+3lX| |%-#3.6hX| |%0.0jX| |%+06.12hhX| |%-07llX| |%#-7.3zX|\n", -435, -676, -47478, -123456789, -543, -9876));


	printf("%d\n", printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888));
	ft_printf("%d\n", ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888));


	printf("\n\n/******************************************************   TEST u U   ******************************************************/\n");
	printf("%d\n", printf("|%012u| |%09U| |%#-05u| |% .20u| |%-09.5u| |%+11u|\n", nbr, +21, 5, -4, 8, 3));
	ft_printf("%d\n", ft_printf("|%012u| |%09U| |%#-05u| |% .20u| |%-09.5u| |%+11u|\n", nbr, +21, 5, -4, 8, 3));

	printf("\n|%+3lu| |%-#3.6hu| |%0.0ju| |%+06.12hhu| |%-07llu| |%#-7.3zu|\n", 5, 63, 8, 123456789, 543, 9876);
	ft_printf("|%+3lu| |%-#3.6hu| |%0.0ju| |%+06.12hhu| |%-07llu| |%#-7.3zu|\n", 5, 63, 8, 123456789, 543, 9876);

	ft_printf("\n|%-#3.6hu|", 63);
	printf("\n|%-#3.6hu|\n", 63);

	ft_printf("\n|%-#3hu|", 63);
	printf("\n|%-#3hu|\n", 63);

	ft_printf("\n|%-#3.6ho|", 6764343);
	printf("\n|%-#3.6ho|\n", 6764343);

	ft_printf("\n|%-#10.6ho|", 6764343);
	ft_printf("\n|%#10.6ho|", 6764343);
	printf("\n|%-#10.6ho|\n", 6764343);

	ft_printf("\n|%#3.6ho|", 6764343);
	printf("\n|%#3.6ho|\n", 6764343);

	ft_printf("\n|%-3.6ho|", 6764343);
	printf("\n|%-3.6ho|\n", 6764343);

	ft_printf("\n|%3.6ho|", 6764343);
	printf("\n|%3.6ho|\n", 6764343);

	ft_printf("%-#6o\n", 2500);
	printf("%-#6o\n\n", 2500);

	printf("\n|%+3lU| |%-#3.6hU| |%0.0jU| |%+06.12hhU| |%-07llU| |%#-7.3zU|\n", -435, -676, -47478, -123456789, -543, -876);
	ft_printf("|%+3lU| |%-#3.6hU| |%0.0jU| |%+06.12hhU| |%-07llU| |%#-7.3zU|\n", -435, -676, -47478, -123456789, -543, -876);

	// printf("%d\n", printf("%hhu, %hhu\n", 0, UCHAR_MAX));
	// ft_printf("%d\n", ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX));


	printf("\n\n/*****************************************************   TEST o O   ******************************************************/\n");
	printf("|%#o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54);
	ft_printf("|%#o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54);

 	printf("%d\n", printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888));
 	ft_printf("%d\n", ft_printf("%o%o%o%o%o\n", 1, 100, 999, 42, 999988888));


	printf("%d\n", printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888));
	ft_printf("%d\n", ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888));


	printf("\n|%+3lo| |%-#3.6ho| |%0.0jo| |%+06.12hho| |%-07llo| |%#-7.3zo|\n", 5, 6764343, 8, 123456789, 543, 9876);
	ft_printf("|%+3lo| |%-#3.6ho| |%0.0jo| |%+06.12hho| |%-07llo| |%#-7.3zo|\n", 5, 6764343, 8, 123456789, 543, 9876);

	printf("\n|%+3lO| |%-#3.6hO| |%0.0jO| |%+06.12hhO| |%-07llO| |%#-7.3zO|\n", -435, -676, -47478, -123456789, -543, -9876);
	ft_printf("|%+3lO| |%-#3.6hO| |%0.0jO| |%+06.12hhO| |%-07llO| |%#-7.3zO|\n", -435, -676, -47478, -123456789, -543, -9876);

	// printf("%d\n", printf("%hho, %hho\n", 0, UCHAR_MAX));
	// ft_printf("%d\n", ft_printf("%hho, %hho\n", 0, UCHAR_MAX));


	printf("\n\n/******************************************************   TEST P   ******************************************************/\n");
	printf("|%p| |%016p| |%-16p| |%14.4p| |%p|\n", str, str, nbr, c);
	ft_printf("|%p| |%016p| |%-16p| |%14.4p| |%p|\n", str, str, nbr, c);

	printf("\n|%+3lp| |%-#3.6hp| |%0.0jp| |%+06.12hhp| |%-07llp| |%#-7.3zp|\n", str, nbr, c, c, nbr, str);
	ft_printf("|%+3lp| |%-#3.6hp| |%0.0jp| |%+06.12hhp| |%-07llp| |%#-7.3zp|\n", str, nbr, c, c, nbr, str);


	printf("\n\n/*****************************************************    TEST C S    *****************************************************/\n");
	ft_printf("%d\n", ft_printf("FT |%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));
	printf("%d\n", printf("PF |%-8C| |%#0 9lc| |%S|\n", myChar1, L'ℜ', L"ο Δικαιοπολις"));


	ft_printf("%d", ft_printf("\nFT |%#0 9lc|", L'ℜ'));
	printf("%d", printf("\nPF |%#0 9lc|", L'ℜ'));

	ft_printf("%d", ft_printf("\nFT |%9lc|", L'ℜ'));
	printf("%d", printf("\nPF |%9lc|", L'ℜ'));
	ft_printf("%d", ft_printf("\nFT |%#0 9S|\n", L"abℜba"));
	printf("%d", printf("\nPF |%#0 9S|\n", L"abℜba"));

	// int			ret[16];

/*	ret[0] = printf("{1 %%c : %c}\n", L'ℜ');
	ret[1] = printf("{2 %%C : %C}\n", L'ℜ');
	ret[2] = printf("{3 %%c : %c}\n", 254);
	ret[3] = printf("{4 %%C : %C}\n", 254);
	ret[4] = printf("{5 %%c : %c}\n", 0x4545);
	ret[5] = printf("{6 %%C : %C}\n", 0x4545);
	setlocale(LC_ALL, "");
	ret[6] = printf("{7 %%c : %c}\n", L'ℜ');
	ret[7] = printf("{8 %%C : %C}\n", L'ℜ');
	ret[8] = printf("{9 %%c : %c}\n", 254);
	ret[9] = printf("{10 %%C : %C}\n", 254);
	ret[10] = printf("{11 %%c : %c}\n", 0x4545);
	ret[11] = printf("{12 %%C : %C}\n", 0x4545);
	for (int i = 0; i < 12; ++i)
		printf("{%d}\n", ret[i]);*/
	//printf("%d", printf("\nPF |%#0 9S|\n", L"abℜba"));
	// ret[0] = printf("{1 %%s : %s}\n", "a");
	// ret[1] = printf("{2 %%S : %S}\n", L"ℜ");
	// ret[2] = printf("{3 %%s : %s}\n", "\xFE");
	// ret[3] = printf("{4 %%S : %S}\n", L"\xFE");
	// ret[4] = printf("{5 %%s : %s}\n", "\x45\x45");
	// ret[5] = printf("{6 %%S : %S}\n", "\x45\x45");
	// setlocale(LC_ALL, "");
	// ret[6] = printf("{7 %%s : %s}\n", L"ℜ");
	// ret[7] = printf("{8 %%S : %S}\n", L"ℜ");
	// ret[8] = printf("{9 %%s : %s}\n", "\xFE");
	// ret[9] = printf("{10 %%S : %S}\n", "\xFE");
	// ret[10] = printf("{11 %%s : %s}\n", "\x45\x45");
	// ret[11] = printf("{12 %%S : %S}\n", "\x45\x45");
	// for (int i = 0; i < 12; ++i)
	// 	printf("[%d]\n", ret[i]);
	printf("%d", printf("\nPF |%#0 9S|\n", L"abℜba"));
	ft_printf("%d", ft_printf("\nPF |%#0 9S|\n", L"abℜba"));


	printf("\n\n/******************************************************   TEST WTF   ******************************************************/\n");
	printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555);
	ft_printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555);

	// ft_printf("|%#-###-----#0++ #####9.8o|\n", 467349478438);
	// printf("|%#-###-----#0++ #####9.8o|\n\n", 467349478438);
	// ft_printf("|%#-0+9.8o|\n", 467349478438);
	// printf("|%#-0+9.8o|\n\n", 467349478438);
	// ft_printf("|%-0+9.8o|\n", 467349478438);
	// printf("|%-0+9.8o|\n\n", 467349478438);
	// ft_printf("|%#-0+9.12o|\n", 467349478438);
	// printf("|%#-0+9.12o|\n\n", 467349478438);

	printf("\n\n/******************************************************   TEST NULL   ******************************************************/\n");

	printf("%d\n", printf("|%-10d| |%c| |%s| |%u| |%C| |%p|\n", NULL, NULL, NULL, NULL, NULL, 0));
	ft_printf("%d\n", ft_printf("|%-10d| |%c| |%s| |%u| |%C| |%p|\n", NULL, NULL, NULL, NULL, NULL, 0));

	printf("\n\n/******************************************************   VALEUR RETOUR   ******************************************************/\n");


	printf("%d\n", printf("\n|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));
	// printf("\n|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876);
	ft_printf("%d\n", ft_printf("\n|%+3lx| |%8hhx| |%-#3.6hx| |%0.0jx| |%+06.12hhx| |%-07llx| |%#-7.3zx|\n", 5, 7843 ,43, 548, 123456789, 123, 9876));
	//
	// printf("%d\n", printf("|%p| |%016p| |%-16p|\n", str, str, nbr));
	// ft_printf("%d\n", ft_printf("|%p| |%016p| |%-16p|\n", str, str, nbr));
	//
	// printf("%d\n", printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555));
	// ft_printf("%d\n", ft_printf("|%xoxoxoxo| |%0000000000000x| |%-7llllllllllllx| |%#hhhhhhhhhhx| |%#----######-######08.0X| |%#-###-----#0++ #####9.8o| |%++++++-0-+++  +++----06X|\n", 43, -54, 95, 9, 532, 467349478438, -555));
	//
	// printf("%d\n", printf("|%#o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54));
	// ft_printf("%d\n", ft_printf("|%#o| |%#-.4o| |%012o| |%-#6o| |%+06.4o| |%-4o| |%#-5.11o|\n", 10, 12, 21, 11, 12, 5, 54));

	return (0);
}
