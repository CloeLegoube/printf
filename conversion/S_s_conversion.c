
#include "../libftprintf.h"

void				s_conversion(t_print *new, va_list arg)
{
  char *string;
  char *argument;

  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  if (!ft_strcmp(new->flags, "l"))
      S_conversion(new, arg);
  else
  {
    // longueur
    argument  = va_arg(arg, char*);
    if (!argument)
      new->string = ft_strdup("(null)");
    else
      new->string = ft_strdup(argument);
    // new->string = ft_strdup(va_arg(arg, char*));
    //precision
    if (new->precision)
      string = ft_strdup(kind_of_precision(new->string, new));
    else
      string = ft_strdup(new->string);
    free(new->string);
    new->string = ft_strdup(string);
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
}
