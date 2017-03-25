

#include "../libftprintf.h"

void				d_conversion(t_print *new, va_list arg)
{
  char *string;


  //longueur
// printf("less:%d\n", new->sign_less);
	new->string = ft_itoa(ft_modify_length_di(arg, new));
	// printf("first[i]: %c\n", new->string[0] );
	// printf("new->string %s\n",new->string );
	// if (new->string[0] == '0')
	// 	new->value_zero = 1;
	if (new->checkprecision && new->precision == 0)
      new->precision = -1;
	if (new->string[0] == '-')
	{
		// printf("new->string %s\n",new->string );
		string = ft_strsub(new->string, 1, ft_strlen(new->string));
		free(new->string);
		new->string = ft_strdup(string);
		free(string);
		new->sign_less = 1;
		new->plus = 0;
		// printf("less:%d\n", new->sign_less);
	}
  if (new->zero && new->space && new->sign_less)
      new->space = 0;
  if (new->zero && new->checkprecision)
      new->zero = 0;
  if (new->plus || new->sign_less || (new->size && !new->zero))
	  new->space = 0;
  if (new->precision >= new->size)
	  new->size = 0;
  if (new->checkprecision && new->htag)
	 new->htag = 0;

modify_string(&string, new, (new->precision), ft_modify_precision);
modify_string(&string, new, (new->size), ft_modify_width);
modify_string(&string, new, (new->space), ft_modify_space);
modify_string(&string, new, (new->plus), ft_modify_sign);
//

  //signe -
  if (new->sign_less && !new->space)
    string = ft_strjoin("-", new->string);
  else
    string = ft_strdup(new->string);
  free(new->string);
  new->string = ft_strdup(string);
  free(string);
}
