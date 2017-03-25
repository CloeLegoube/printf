
#include "../libftprintf.h"

void				D_conversion(t_print *new, va_list arg)
{
  new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'd');
  new->flags = "l";
  d_conversion(new, arg);
}
