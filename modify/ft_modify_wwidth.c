/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:34:43 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/30 17:47:32 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_var *ftw_inititalize_var(wchar_t *string, t_var *var, t_print *new)
{
	var = (t_var*)malloc(sizeof(t_var));
	var->b = ft_atoi(new->size);
	var->a = ft_wstrlen(string);
	var->i = 0;
	var->j = 0;
	return (var);
}

void	ftw_conditionless(wchar_t *string, wchar_t *result, t_var *var, t_print *new)
{
	if (new->less)
	{
		while (var->i < var->a)
			result[var->i++] = string[var->j++];
		while (var->i < var->b - new->wbit)
				result[var->i++] = ' ';
	}
	else
	{
		while (var->i < var->b - var->a - new->wbit)
			result[var->i++] = ' ';
		while (var->i < var->b)
			result[var->i++] = string[var->j++];
	}
}

void	ftw_Sconditionless(wchar_t *string, wchar_t *result, t_var *var, t_print *new)
{
	int count;

	count = 0;
	new->wbit = ft_count_bits(string, var->a);
	if (new->less)
	{
		while (var->i < var->a)
			result[var->i++] = string[var->j++];
		while (count < var->b - new->wbit)
		{
			result[var->i++] = L' ';
			count++;
		}
	}
	else
	{
		while (var->i < var->b - new->wbit)
			result[var->i++] = ' ';
		while (count < var->a)
		{
			result[var->i++] = string[var->j++];
			count++;
		}
	}
}


wchar_t	*ft_modify_wwidth(wchar_t *string, t_print *new)
{
	t_var *var;
	wchar_t *result;

	var = NULL;
	var = ftw_inititalize_var(string, var, new);
	if (var->b <= var->a)
		return (string);
	result = ft_wstrnew(var->b);
	// if (new->plus && new->space)
	// 	new->space = 0;
	if (new->space)
	{
		result[var->i++] = ' ';
		new->space = 0;
	}
	if (new->conversion == ft_indexchr("sSpdDioOuUxXcC", 'S'))
		ftw_Sconditionless(string, result, var, new);
	else
		ftw_conditionless(string, result, var, new);
	return (result);
}
