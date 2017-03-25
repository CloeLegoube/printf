/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:48:42 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/14 20:17:18 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	modify_string(char **string, t_print *new, int yes, char *(*f)(char *, t_print *))
{
	if (yes)
		*string = ft_strdup(f(new->string, new));
	else
		*string = ft_strdup(new->string);
	free(new->string);
	new->string = ft_strdup(*string);

	free(*string);
}

void	modify_wstring(wchar_t **string, t_print *new, int yes, char *(*f)(char *, t_print *))
{
	if (yes)
		*string = ft_wstrdup((wchar_t *)(f((char *)new->wstring, new)));
	else
		*string = ft_wstrdup((wchar_t *)((char *)new->wstring));
	free(new->wstring);
	new->wstring = ft_wstrdup(*string);

	free(*string);
}
