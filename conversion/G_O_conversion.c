
#include "../libftprintf.h"

void				O_conversion(t_print *new, va_list arg)
{
  new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'o');
  new->flags = "l";
  o_conversion(new, arg);
}
