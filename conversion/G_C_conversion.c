
#include "../libftprintf.h"

void ft_count_bit(wchar_t C, t_print *new)
{
  if (C <= 127)
    new->wbit = 0;
  else if (C <= 2047)
		new->wbit = 1;
	else if (C <= 65535)
		new->wbit = 2;
	else if (C <= 2097151)
		new->wbit = 3;
}

void				C_length(t_print *new, va_list arg)
{
  wchar_t charac;

  // if (ft_strcmp(new->flags,"no-flags"))
  //   charac = ft_modify_length_c(arg, new);
  // else
  charac = va_arg(arg, int);
  if (charac == 0)
  {
    new->value_zero = 1;
    charac = charac + 48;
  }
  ft_count_bit(charac, new);
  new->wstring = (wchar_t *)malloc(2 * sizeof(*new->wstring));
  new->wstring[0] = charac;
  new->wstring[1] = '\0';
}

void				C_conversion(t_print *new, va_list arg)
{
  // intmax_t nb;
  //
  // nb = 0;
  // if (ft_strcmp(new->flags,"l"))
  //     nb = va_arg(arg, long);
  //       nb++;
  wchar_t *string;
  // char charac;
  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  if (new->zero)
    new->zero = 0;
  if (new->precision)
    new->precision = 0;
  //longueur
  C_length(new, arg);
  // taille
  if (new->size)
    string = ft_wstrdup(ft_modify_wwidth(new->wstring, new));
  else
    string = ft_wstrdup(new->wstring);
  free(new->wstring);
  new->wstring = ft_wstrdup(string);
  free(string);

}
