
#include "../libftprintf.h"

void				u_conversion(t_print *new, va_list arg)
{
  char *string;

  //flags => +
	if (new->plus)
		new->plus = 0;
	if (new->space)
		new->space = 0;
		// if (new->checkprecision && new->precision == 0)
	    //   new->precision = -1;
  //longueur
  new->string = ft_itoa_positif(ft_modify_length_uoxX(arg, new));
  if (new->string[0] == '0')
	  new->value_zero = 1;
	if (new->value_zero && new->checkprecision && new->precision == 0)
		new->precision = -1;
  modify_string(&string, new, (new->precision && !new->htag), ft_modify_precision);
  modify_string(&string, new, (new->size), ft_modify_width);
}
