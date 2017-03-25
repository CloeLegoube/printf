
#include "../libftprintf.h"

void				S_conversion(t_print *new, va_list arg)
{
  wchar_t *string;
  wchar_t *argument;

  if (new->plus)
    new->plus = 0;
	// if (new->zero)
	// 	new->zero = 0;
  if (new->space)
    new->space = 0;
  if (!ft_strcmp(new->flags, "h"))
  {
      new->conversion= ft_indexchr("sSpdDioOuUxXcC", 's');
      s_conversion(new, arg);
  }
  else
  {
    argument = va_arg(arg, wchar_t*);
	if (argument !=  NULL)
	{
		//longueur
			new->wstring = ft_wstrdup(argument);
		//precision
		modify_wstring(&string, new, (new->precision), ft_modify_precision);
		//taille
		// if (new->size)
		// {
		//   modify_wstring(&string, new, (new->size), ft_modify_width);
		//   new->string = ft_strdup((char *)new->wstring);
		//   free(new->wstring);
		// }
		if (new->precision)
		  string = ft_wstrdup((wchar_t *)ft_modify_precision((char *)new->wstring, new));
		else
		  string = ft_wstrdup(new->wstring);
		free(new->wstring);
		new->wstring = ft_wstrdup(string);
		free(string);
		//taille
		// if (new->size)
		//   string = ft_wstrdup((wchar_t *)ft_modify_width((char *)new->wstring, new));
		// else
		//   string = ft_wstrdup(new->wstring);
		// free(new->wstring);
		// new->wstring = ft_wstrdup(string);
		// free(string);
		if (new->size)
		{
		  modify_wstring(&string, new, (new->size), ft_modify_width);
		  new->string = ft_strdup((char *)new->wstring);
		  new->wstring = NULL;
		  free(new->wstring);
		}
	}
	else
		new->wstring = ft_wstrdup(L"(null)");
	if (new->wstring)
		new->len = ft_strcut_unicode(1, (char *)new->wstring, ft_wstrlen(new->wstring));
	// printf("bytes: %d\n", ft_strcut_unicode(1, (char *)new->wstring, ft_wstrlen(new->wstring)));
	// printf("ft_wstrlen: %zu", ft_wstrlen(new->wstring));

    // printf("(char *)new->wstring: *%s* \n", (char *)new->wstring);
    // printf("new->string : %s\n", new->string);
    // printf("new->wstring : %S\n", new->wstring);
    // write(1, new->wstring, new->size);

  }
}
