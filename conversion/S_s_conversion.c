
#include "../libftprintf.h"

void				s_conversion(t_print *new, va_list arg)
{
  char *string;
  char *argument;

  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
	// if (new->precision == 0 && !ft_strcmp(new->flags, "l"))
	//   new->precision = -1;
  if (!ft_strcmp(new->flags, "l"))
  {
      new->conversion= ft_indexchr("sSpdDioOuUxXcCb", 'S');
      S_conversion(new, arg);
      // new->index++;
  }
  else
  {
    // longueur

    argument  = va_arg(arg, char*);
    if (!argument)
      new->string = ft_strdup("(null)");
    else
      new->string = ft_strdup(argument);
    // new->string = ft_strdup(va_arg(arg, char*));

	modify_string(&string, new, (new->checkprecision), ft_modify_precision);
    modify_string(&string, new, (new->size), ft_modify_width);
  }
}
