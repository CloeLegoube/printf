
#include "../libftprintf.h"

void				C_length(t_print *new, va_list arg)
{
	wchar_t charac;

	charac = va_arg(arg, int);
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
	new->wstring = (wchar_t *)malloc(2 * sizeof(*new->wstring));
	new->wstring[0] = charac;
	new->wstring[1] = '\0';
}

void				C_conversion(t_print *new, va_list arg)
{
  wchar_t *string;
  //flags => +
  if (new->plus)
    new->plus = 0;
  if (new->space)
    new->space = 0;
  if (new->zero)
    new->zero = 0;
  if (new->precision)
    new->precision = 0;
  //longueur
  C_length(new, arg);
  // taille
	modify_wstring(&string, new, (new->size), ft_modify_width);
	if (new->wstring)
		new->len = ft_strcut_unicode(1, (char *)new->wstring, ft_wstrlen(new->wstring));
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
