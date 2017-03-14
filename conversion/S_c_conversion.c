

#include "../libftprintf.h"

void				c_length(t_print *new, va_list arg)
{
  char charac;

  if (ft_strcmp(new->flags,"no-flags"))
    charac = ft_modify_length_c(arg, new);
  else if (new->percentage)
    charac = '%';
  else
    charac = va_arg(arg, int);
  if (charac == 0)
  {
    new->value_zero = 1;
    charac = charac + 48;
  }
  new->string = (char *)malloc(2 * sizeof(*new->string));
  new->string[0] = charac;
  new->string[1] = '\0';
}

void				c_conversion(t_print *new, va_list arg)
{
  char *string;
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
  c_length(new, arg);
  // taille
  if (new->size)
    string = ft_strdup(ft_modify_width(new->string, new));
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
}
