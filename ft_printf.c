/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:39:12 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/30 13:21:53 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

va_list        *no_conversion(va_list arg, char conversion)
{
  va_arg(arg, void*);
  ft_putchar(conversion);
  return (0);
}

va_list         *kind_of_conversion(va_list arg, char conversion)
{
  if ((conversion == 'd') || (conversion == 'i'))
    ft_putnbr(va_arg(arg, int));
  else if (conversion == 's')
    ft_putstr(va_arg(arg, char*));
  // else if (conversion == 'S')
  //   ft_putwstr(va_arg(arg, char*));
	// else if (conversion == 'u')
	// 	my_put_unsigned_nbr(va_arg(arg, int));
  // else if (conversion == 'c')
  //   ft_putchar(va_arg(arg, int));
  // else if (conversion == 'o')
  //   ft_convert_base(va_arg(arg, int), "0123456789", "01234567");
  // else if (conversion == 'x')
  //   ft_convert_base(va_arg(arg, int), "0123456789", "0123456789abcdef");
  // else if (conversion == 'X')
  //   ft_convert_base(va_arg(arg, int), "0123456789", "0123456789ABCDEF");
  // else if (conversion == 'p')
  //   my_show_adress(va_arg(arg, int));
  // else
  //   no_conversion(arg, conversion);
  return (0);
}

va_list         *flags(va_list arg, char conversion)
{
  if (conversion == '-' && arg < 0)
    ft_putchar('-');
  else if (conversion == '+' && arg >= 0)
    ft_putchar('+');
  else if (conversion == '#')
  {
    conversion++;
    if (conversion == 'o')
      ft_putchar('0');
    if (conversion == 'x')
      ft_putstr("0x");
    if (conversion == 'X')
      ft_putstr("0X");
    conversion--;
  }
  else if (conversion == ' ' && arg >= 0)
    ft_putchar(' ');
  return (0);
}

int        ft_printf(char *conversion, ...)
{
  va_list  arg;

  va_start(arg, conversion);
  while (*conversion)
  {
    if (*conversion == '%')
      {
        conversion++;
        if (*conversion == '+' || *conversion == '-' || *conversion == ' ' || *conversion == '#')
          {
            flags(arg, *conversion);
            conversion++;
          }
        if (*conversion >= '0' && *conversion <= '9')
          conversion++;
        kind_of_conversion(arg, *conversion);
        conversion++;
        if (*conversion == '\0')
          return (0);
      }
    ft_putchar(*conversion);
    conversion++;
  }
  va_end(arg);
  return (0);
}
