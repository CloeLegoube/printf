
#include "../libftprintf.h"

void				U_conversion(t_print *new, va_list arg)
{
  new->conversion = 'u';
  new->flags = "l";
  u_conversion(new, arg);
}
