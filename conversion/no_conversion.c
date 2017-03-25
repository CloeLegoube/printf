
#include "../libftprintf.h"

void				no_conversion(t_print *new, va_list arg)
{
  char *string;


  //longueur
  if (new->space)
    new->space = 0;
	// printf("new->conversion: %d\n",new->conversion);
	// printf("new->string: *%s*\n",new->string);
// printf("string : *%s*\n", new->string);
	if (new->string == NULL)
		new->string = ft_strdup("");
	// string = ft_strsub(new->string, 0, 1);
	// free(new->string);
	// new->string = ft_strdup(string);
	// free(string);
	// ft_strcut_unicode(0, new->string, 1);
	arg = NULL;
// printf("string : *%s*\n", new->string);
// printf("new->conversion: %d\n",new->conversion);
// new->conversion = ft_indexchr("sSpdDioOuUxXcC", 'c');
modify_string(&string, new, (new->checkprecision && !new->htag), ft_modify_precision);
modify_string(&string, new, (new->size), ft_modify_width);
modify_string(&string, new, (new->space), ft_modify_space);
modify_string(&string, new, (new->plus), ft_modify_sign);
// new->index++;
}
