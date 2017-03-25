/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_sign_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:26:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/23 16:35:38 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char         *ft_modify_sign(char *string, t_print *new)
{
	char *tmp;

	// if (new->plus && ft_atoi(string) >= 0)
	if (new->plus)
	{
		tmp = ft_strjoin("+", string);
		free(string);
		string =  ft_strdup(tmp);
		free(tmp);
	}
	// printf("string:%s", string);
	return (string);
}
