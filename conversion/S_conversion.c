
#include "../libftprintf.h"

int ft_count_bits(wchar_t *S, int size)
{
  int i;
  int wbit;

  i = 0;
  wbit = 0;
  while (i < size)
  {
    if (S[i] <= 127)
      wbit += 1;
    else if (S[i] <= 2047)
      wbit += 2;
    else if (S[i] <= 65535)
      wbit += 3;
    else if (S[i] <= 2097151)
      wbit += 4;
    i++;
  }
  return (wbit);
}

void ft_add_bits(wchar_t C, t_print *new)
{
  if (C <= 127)
      new->wbit += 1;
  else if (C <= 2047)
		new->wbit += 2;
	else if (C <= 65535)
		new->wbit += 3;
	else if (C <= 2097151)
		new->wbit += 4;
}

void ft_sub_bits(wchar_t C, t_print *new)
{
  if (C <= 127)
      new->wbit -= 1;
  else if (C <= 2047)
		new->wbit -= 2;
	else if (C <= 65535)
		new->wbit -= 3;
	else if (C <= 2097151)
		new->wbit -= 4;
}

void				S_conversion(t_print *new, va_list arg)
{
  wchar_t *string;
  wchar_t *argument;

  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  if (!ft_strcmp(new->flags, "h"))
      s_conversion(new, arg);
  else
  {
    argument = va_arg(arg, wchar_t*);
    // longueur
    new->wstring = ft_wstrdup(argument);
    //precision
    if (new->precision)
      string = ft_wstrdup(wkind_of_precision(new->wstring, new));
    else
      string = ft_wstrdup(new->wstring);
    free(new->wstring);
    new->wstring = ft_wstrdup(string);
    free(string);

    //taille
    if (new->size)
      string = ft_wstrdup(ft_modify_wwidth(new->wstring, new));
    else
      string = ft_wstrdup(new->wstring);
    free(new->wstring);
    new->wstring = ft_wstrdup(string);
    free(string);
  }
}
