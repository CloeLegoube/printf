
#include "../libftprintf.h"

void				p_conversion(t_print *new, va_list arg)
{
  char *string;
  uintmax_t nb;

  if (new->plus)
    new->plus = 0;
  if (new->zero)
    new->zero = 0;
  if (new->space)
    new->space = 0;
  if (new->precision)
    new->precision = 0;
  //Adresse
  nb = va_arg(arg, uintmax_t);
  string = NULL;
  if (nb != 0)
    string = ft_strdup("0x");
  else
    string = ft_strdup("(nil)");
  new->string = ft_strjoin(string, ft_itobase(nb, "0123456789abcdef"));
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
