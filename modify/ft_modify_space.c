/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 19:26:21 by clegoube          #+#    #+#             */
/*   Updated: 2017/03/17 14:20:01 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char         *ft_modify_space(char *string, t_print *new)
{
	char *tmp;

	if (new->space)
	{
		tmp = ft_strjoin(" ", string);
		free(string);
		string =  ft_strdup(tmp);
		free(tmp);
	}
	// printf("string:%s", string);
	return (string);
}
