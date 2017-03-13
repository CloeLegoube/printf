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

t_var *ft_inititalize_var(char *string, t_var *var, t_print *new)
{
	var = (t_var*)malloc(sizeof(t_var));
	var->a = ft_strlen(string);
	var->b = ft_atoi(new->size);
	var->i = 0;
	var->j = 0;
	return (var);
}

void	ft_iszero(char *result, t_var *var, t_print *new)
{
	if (new->zero)
	{
		if (new->plus)
		{
			result[var->i++] = '+';
			new->plus = 0;
		}
		if (new->sign_less)
		{
			result[var->i++] = '-';
			new->sign_less = 0;
		}
		result[var->i++] = '0';
	}
	else
			result[var->i++] = ' ';
}

void	ft_issign_noless(char *result, t_var *var, t_print *new)
{
	if (new->plus)
	{
		var->i--;
		result[var->i++] = '+';
		new->plus = 0;
	}
	if (new->sign_less)
	{
		var->i--;
		result[var->i++] = '-';
		new->sign_less = 0;
	}
}

void	ft_conditionless(char *string, char *result, t_var *var, t_print *new)
{
	if (new->less)
	{
		while (var->i < var->a)
		{
			if (new->plus || new->sign_less)
			{
					if (new->plus)
					{
						result[var->i++] = '+';
						new->plus = 0;
					}
					if (new->sign_less)
						result[var->i++] = '-';
				var->a++;
			}
			result[var->i++] = string[var->j++];
		}
		while (var->i < var->b)
				result[var->i++] = ' ';
	}
	else
	{
		while (var->i < var->b - var->a)
			ft_iszero(result, var, new);
		ft_issign_noless(result, var, new);
		while (var->i < var->b)
			result[var->i++] = string[var->j++];
	}
}

char	*ft_modify_width(char *string, t_print *new)
{
	t_var *var;
	char *result;

	var = NULL;
	var = ft_inititalize_var(string, var, new);
	if (new->sign_less)
		 var->b++;
	if (var->b <= var->a)
		return (string);
	if (new->sign_less)
		var->b--;
	result = ft_strnew(var->b);
	if (new->plus && new->space)
		new->space = 0;
	if (new->space)
	{
		result[var->i++] = ' ';
		new->space = 0;
	}
	ft_conditionless(string, result, var, new);
	return (result);
}
