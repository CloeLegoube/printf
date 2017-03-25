
#include "../libftprintf.h"

void				U_conversion(t_print *new, va_list arg)
{
  new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'u');
  new->flags = "l";
  u_conversion(new, arg);
}
