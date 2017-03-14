
#include "../libftprintf.h"

void				d_conversion(t_print *new, va_list arg)
{
  char *string;


  //longueur
  new->string = ft_itoa(ft_modify_length_di(arg, new));
  if(new->string[0] == '-')
  {
    string = ft_strsub(new->string, 1, ft_strlen(new->string));
    free(new->string);
    new->string = ft_strdup(string);
    free(string);
    new->sign_less = 1;
    new->plus = 0;
  }
  if (new->zero && new->space && new->sign_less)
      new->space = 0;

  //precision
  if (new->precision && !new->htag)
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
  //flags => +
  if (new->plus)
    string = ft_strdup(add_sign(new->string, new));
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
  //flags => space
  if (new->space)
    string = ft_strdup(add_space(new->string, new));
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
  //signe -
  if (new->sign_less)
    string = ft_strjoin("-", new->string);
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
}
