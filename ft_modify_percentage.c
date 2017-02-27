/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:15:05 by clegoube          #+#    #+#             */
/*   Updated: 2017/02/06 11:29:51 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_percentage(t_print *new)
{
	if (new->percentage && !(new->conversion))
	{
		if
	}



	int a;
	int b;
	int i;
	int j;
	char *result;
	result = NULL;

	a = ft_strlen(string);
	b = ft_atoi(new->size);
	if (b > a)
	{
		result = ft_strnew(b);
		i = 0;
		j = 0;
		while (i < a)
			result[i++] = string[j++];
		j = 0;
		while (i < b)
			result[i++] = ' ';
	}
	return (result);
}
