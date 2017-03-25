
#include "../libftprintf.h"

void				S_conversion(t_print *new, va_list arg)
{
  wchar_t *string;
  wchar_t *argument;

  if (new->plus)
    new->plus = 0;
	// if (new->zero)
		// new->zero = 0;
	// if (new->precision == 0 && !ft_strcmp(new->flags, "l"))
	//   new->precision = -1;
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

	}
	else
		new->wstring = ft_wstrdup(L"(null)");
		//precision
		// printf("before:%S\n", new->wstring);
		modify_wstring(&string, new, (new->checkprecision), ft_modify_precision);
		// printf("after:%S\n", new->wstring);

		//taille
		// if (new->size)
		// {
		//   modify_wstring(&string, new, (new->size), ft_modify_width);
		//   new->string = ft_strdup((char *)new->wstring);
		//   free(new->wstring);
		// }
		// if (new->precision)
		//   string = ft_wstrdup((wchar_t *)ft_modify_precision((char *)new->wstring, new));
		// else
		//   string = ft_wstrdup(new->wstring);
		// free(new->wstring);
		// new->wstring = ft_wstrdup(string);
		// free(string);
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
// printf("after2:%S\n", new->wstring);
	if (new->wstring)
		new->len = ft_strcut_unicode(1, (char *)new->wstring, ft_wstrlen(new->wstring));
		// printf("after3:%S\n", new->wstring);
	// printf("bytes: %d\n", ft_strcut_unicode(1, (char *)new->wstring, ft_wstrlen(new->wstring)));
	// printf("ft_wstrlen: %zu", ft_wstrlen(new->wstring));

    // printf("(char *)new->wstring: *%s* \n", (char *)new->wstring);
    // printf("new->string : %s\n", new->string);
    // printf("new->wstring : %S\n", new->wstring);
    // write(1, new->wstring, new->size);

  }
}
