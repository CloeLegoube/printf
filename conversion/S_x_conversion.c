
#include "../libftprintf.h"

void				x_conversion(t_print *new, va_list arg)
{
  char *string;

  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
	if (new->less && new->zero)
	  new->zero = 0;
	if (new->checkprecision && new->precision == 0)
      new->precision = -1;
  //longueur
  new->htag_prefixe = ft_strdup("0x");
  new->string  = ft_modify_htag(arg, new, "0123456789abcdef");
  // printf("string: %s", new->string );
  // printf("(new->precision && !new->htag): %d", (new->precision && !new->htag) );
  modify_string(&string, new, (new->precision && !new->htag), ft_modify_precision);
  modify_string(&string, new, (new->size), ft_modify_width);

}
