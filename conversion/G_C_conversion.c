
#include "../libftprintf.h"

void				C_length(t_print *new, va_list arg)
{
	wchar_t charac;

	charac = va_arg(arg, int);
	// printf("charac %d",charac );
	if (charac == 0)
	{
		new->value_zero = 1;
		charac = charac + 48;
	}
	if (charac <= 127)
		new->wbyte = 0;
	else if (charac <= 2047)
		new->wbyte = 1;
	else if (charac <= 65535)
		new->wbyte = 2;
	else if (charac <= 2097151)
		new->wbyte = 3;
		// printf("MB_CUR_MAX %d\n",MB_CUR_MAX );

	if (MB_CUR_MAX > 1 || charac <= 255)
	{

		new->wstring = (wchar_t *)malloc(2 * sizeof(*new->wstring));
		new->wstring[0] = charac;
		new->wstring[1] = '\0';
	}
	else
	{
		new->len = -1;
		return;
	}

}

void				C_conversion(t_print *new, va_list arg)
{
  wchar_t *string;
  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  if (new->precision)
    new->precision = 0;
  //longueur
  C_length(new, arg);
  // taille
  // printf("new->wstring1 : %S\n", new->wstring);
  if (new->size && new->wstring)
  {
	  modify_wstring(&string, new, (new->size), ft_modify_width);
	  new->string = ft_strdup((char *)new->wstring);
		new->wstring = NULL;
	  free(new->wstring);
  }

	if (new->wstring)
		new->len = ft_strcut_unicode(1, (char *)new->wstring, ft_wstrlen(new->wstring));

	// printf("new->wstring2 : %s\n", new->wstring);
	// printf("new->string : %s\n", new->string);

  // if (new->size)
  //   string = ft_wstrdup((wchar_t *)ft_modify_width((char *)new->wstring, new));
  // else
  //   string = ft_wstrdup(new->wstring);
  // free(new->wstring);
  // new->wstring = ft_wstrdup(string);
  // free(string);
	// new->string = (char *)(ft_strdup((char *)new->wstring));
	// printf("new->string : %s", new->string);
	// printf("new->wstring : %S", new->wstring);
}
