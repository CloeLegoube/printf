
#include "../libftprintf.h"

void				o_conversion(t_print *new, va_list arg)
{
  char *string;

  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  if (new->precision && new->zero)
    new->zero = 0;
	if (new->less && new->zero)
	  new->zero = 0;
if (new->checkprecision && new->precision == 0)
	new->precision = -1;
  //longueur
   new->htag_prefixe = ft_strdup("0");
  new->string  = ft_modify_htag(arg, new, "01234567");
  // printf("string: %s\n", new->string );
  if (new->string[0] == '0')
	  new->value_zero = 1;
	//   printf("new->value_zero: %d\n", new->value_zero);
	// printf("string1: %s\n", new->string );
  modify_string(&string, new, (new->precision), ft_modify_precision);
  // printf("string2: %s\n", new->string );
 //  	printf("string: %s\n", new->string );
  modify_string(&string, new, (new->size), ft_modify_width);
}
