/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/27 12:38:33 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"


static int		ft_wchar(wchar_t *dest, wchar_t C)
{
	int count;

	count = 0;
	*dest = 0;
	if (C <= 127 && (count = 1))
		*dest = C;
	else if (C <= 2047 && (count = 2))
	{
		*dest = (C >> 6) + 0xC0;
		*dest += ((C & 0x3F) + 0x80) << 8;
	}
	else if (C <= 65535 && (count = 3))
	{
		*dest = (C >> 12) + 0xE0;
		*dest += (((C >> 6) & 0x3F) + 0x80) << 8;
		*dest += ((C & 0x3F) + 0x80) << 16;
	}
	else if (C <= 2097151 && (count = 4))
	{
		*dest = (C >> 18)  + 0xF0;
		*dest += (((C >> 12) & 0x3F) + 0x80) << 8;
		*dest += (((C >> 6) & 0x3F) + 0x80) << 16;
		*dest += ((C & 0x3F) + 0x80) << 24;
	}
	return (count);
}

static char 	*ft_strcpy_unicode(int is_wstring, char *dest, const char *source)
{
	int		i;
	int		byte_count;

	i = 0;
	byte_count = 0;
	if (is_wstring)
	{
		while (((wchar_t *)source)[i])
		{
			byte_count += ft_wchar((wchar_t *)(dest + byte_count), ((wchar_t *)source)[i]);
			++i;
		}
		*((wchar_t *)dest + byte_count) = 0;
	}
	else
	{
		while (source[i])
		{
			dest[i] = source[i];
			++i;
		}
		*(dest + i) = 0;
	}
	return (dest);
}

static void		ft_conditionless(char *string, char *result,
	int len_string, t_print *new)
{
 	int		byte_len;
 	int		is_wstring;
	char 	*tmp;

	//  printf("wstring avant byte_len: *%s* \n", (char *)string);
	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S')) ||
				(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'C'));
	// if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p'))
	// 	byte_len = ft_strlen());
 // 	else

	byte_len = ft_strcut_unicode(is_wstring, (char *)string, len_string);
	if ((new->size - byte_len) < 0)
		byte_len = new->size;


	//
	// printf("\nwstring apres byte_len :");
	// write(1, string, ft_strlen(string));
	// printf("\n");
	// if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p'))
	// {
	// 	printf("string: %s \n\n", string);
	// 	// printf("result: %s \n\n", result);
	// 	// printf("new->htag_prefixe: %s \n\n", new->htag_prefixe);
	// 	tmp = ft_strjoin(new->htag_prefixe, string);
	// 	free(string);
	// 	string = ft_strdup(tmp);
	// 	free(tmp);
	// 	printf("string: %s \n\n", string);
	//
	// 	free(new->htag_prefixe);
	// 	new->htag_prefixe = ft_strdup("no");
	// 	// if (new->value_zero && new->zero)
	// 	// {
	// 	// 	free(string);
	// 	// 	string =ft_strdup("");
	// 	// }
	// }
	if (new->less)
	{
		ft_strcpy_unicode(is_wstring, result, string);
		ft_memset(result + byte_len, ' ', new->size - byte_len);
	}
	else
	{
		// printf("byte_len: %d \n", byte_len);
		// printf("new->size:%d\n", new->size);
		// printf("new->zero: %d \n", new->zero);
// printf("less:%d\n", new->sign_less);
		if (new->zero)
			ft_memset(result, '0', new->size - byte_len);
		else
		{
			ft_memset(result, ' ', new->size - byte_len);
		}

		if (new->sign_less && new->size != byte_len && new->sign_less--)
		{
			// printf("new->size - byte_len - 1:%d\n", new->size - byte_len - 1);

			result[new->size - byte_len - 1] = '-';
		}

		else if (new->plus && new->size != byte_len && new->plus--)
		{
			// printf("byte_len:%d\n", byte_len);
			// printf("new->size:%d\n", new->size);
			result[new->size - byte_len - 1] = '+';
		}

		if (ft_strcmp(new->htag_prefixe, "no") &&
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p') ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'o') && new->htag)))
		{
				// tmp = ft_strjoin(new->htag_prefixe, result);
				// free(result);
				// result = ft_strdup(tmp);
				// free(tmp);
			// 	printf("result:*%s*\n", result);
			// 	printf("new->size:*%d*\n", new->size);
			// printf("byte_len:*%d*\n", byte_len);
			if (new->size - byte_len <= ft_strlen(new->htag_prefixe))
			{
				ft_strcpy_unicode(is_wstring, result + new->size - byte_len, new->htag_prefixe);
				if (!new->value_zero)
					result = result + ft_strlen(new->htag_prefixe);
			}

			else
				ft_strcpy_unicode(is_wstring, result + new->size - byte_len - ft_strlen(new->htag_prefixe), new->htag_prefixe);

			// ft_strcpy_unicode(is_wstring, result + new->size - byte_len + ft_strlen(new->htag_prefixe), string);
			// printf("result:*%s*\n", result);
			// printf("new->htag_prefixe: %s \n", new->htag_prefixe);
		}
		// else
			ft_strcpy_unicode(is_wstring, result + new->size - byte_len, string);
			// // printf("new->htag: %d \n", new->htag);
			// tmp = ft_strjoin(new->htag_prefixe,result);
			// free(result);
			// result = ft_strdup(tmp);
			// printf("result:*%s*\n", result);

			// printf("result:*%s*\n", result);
			// ft_strcpy_unicode(is_wstring, result + new->size - byte_len , string);
			// printf("result:*%s*\n", result);
			// ft_strcpy_unicode(is_wstring, result + new->size - byte_len, new->htag_prefixe);
			// new->size -= ft_strlen(new->htag_prefixe);
			// i = ft_strlen(new->htag_prefixe);

		// 	printf("len_string: %d \n", len_string);
	    	// printf("new->size: %d \n", new->size);
			// printf("result:*%s*\n", result);



	}

	// printf("\nresultat apres ft_conditionless:");
	// write(1, result, new->size);
	// printf("\n");
}

char			*ft_modify_width(char *string, t_print *new)
{
	int			len_string;
	char		*result;
	// char		*tmp;
	int			i;
	int			is_wstring;

	i = 0;
	// printf("new->htag_prefixe: *%s* \n", new->htag_prefixe);
	is_wstring = (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S')) ||
		(new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'C'));
	if (ft_strcmp(new->htag_prefixe, "no") && new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p') && new->value_zero)
		 string = ft_strdup(new->htag_prefixe);
	len_string = is_wstring ? ft_wstrlen((wchar_t *)string) : ft_strlen(string);
	// if (new->size + new->sign_less <= ft_strcut_unicode(1, (char *)string, len_string))
	// 	return (string);
	result = is_wstring ? (char *)ft_wstrnew(new->size) : ft_strnew(new->size);
	if (new->less || new->zero)
	{
		if (new->sign_less && new->sign_less-- && new->size--)
			result[i++] = '-';
		else if (new->plus && new->plus-- && new->size--)
			result[i++] = '+';
		else if (new->space && new->space-- && new->size--)
			result[i++] = ' ';
		if (ft_strcmp(new->htag_prefixe, "no") && new->htag)
		{
			ft_strcpy_unicode(is_wstring, result + i, new->htag_prefixe);
			new->size -= ft_strlen(new->htag_prefixe);
			i = ft_strlen(new->htag_prefixe);
		}
		if (ft_strcmp(new->htag_prefixe, "no") &&
			new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'p') &&
			(!new->value_zero || (new->value_zero && new->zero)))
		{
			ft_strcpy_unicode(is_wstring, result + i, new->htag_prefixe);
			new->size -= ft_strlen(new->htag_prefixe);
			i = ft_strlen(new->htag_prefixe);
			free(new->htag_prefixe);
			new->htag_prefixe = ft_strdup("no");
			if (new->value_zero && new->zero)
			{
				free(string);
				string =ft_strdup("");
			}

		}
		// printf("result: *%s* \n", result);
		// printf("string: *%s* \n", string);

	}
	// if (ft_strcmp(new->htag_prefixe, "no"))
	// {
	// 	tmp = ft_strjoin(new->htag_prefixe, result);
	// 	free(result);
	// 	result = ft_strdup(tmp);
	// 	free(tmp);
	// 	i += ft_strlen(new->htag_prefixe);
	// 	new->size -= ft_strlen(new->htag_prefixe);
	// }
	ft_conditionless((char *)string, result + i, len_string, new);
	// printf("result:*%s*\n", result);

	return (result);
}


// char			*ft_modify_width(char *string, t_print *new)
// {
// 	int		len_string;
// 	char	*result;
// 	int		i;

// 	i = 0;
// 	len_string = ft_strlen(string);
// 	if (new->size + new->sign_less <= len_string)
// 		return (string);
// 	result = ft_strnew(new->size);
// 	if (new->less || new->zero)
// 	{
// 		if (new->sign_less && new->sign_less--)
// 			result[i++] = '-';
// 		else if (new->plus && new->plus--)
// 			result[i++] = '+';
// 		else if (new->space && new->space--)
// 			result[i++] = ' ';
// 	}
// 	ft_conditionless(string, result + i, len_string, new);
// 	return (result);
// }
