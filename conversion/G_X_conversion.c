
#include "../libftprintf.h"

void				X_conversion(t_print *new, va_list arg)
{
  char *string;

  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
	if (new->zero && new->checkprecision && new->precision == 0)
	  new->zero = 0;
// if ((new->less && new->zero) || (new->zero && new->size && (-1 == new->precision || 0 == new->precision)))
//   new->zero = 0;
  if (new->less && new->zero)
    new->zero = 0;
  //longueur
  new->htag_prefixe = ft_strdup("0X");
  new->string  = ft_modify_htag(arg, new, "0123456789ABCDEF");
  if (new->value_zero && new->checkprecision && new->precision == 0)
	  new->precision = -1;
  modify_string(&string, new, (new->checkprecision && !new->htag), ft_modify_precision);
  modify_string(&string, new, (new->size), ft_modify_width);
}
