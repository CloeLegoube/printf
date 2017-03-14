
#include "../libftprintf.h"

void				x_conversion(t_print *new, va_list arg)
{
  char *string;

  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  //longueur
  new->string  = htag_get_string(arg, new, "0123456789abcdef", "0x");
  // printf("string: %s", new->string );
  //precision
  if (new->precision && !new->htag)
    string = ft_strdup(kind_of_precision(new->string, new));
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
  //taille
  if (new->size)
    string = ft_strdup(ft_modify_width(new->string, new));
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
}
