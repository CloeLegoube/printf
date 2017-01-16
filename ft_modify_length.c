/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:48:12 by clegoube          #+#    #+#             */
/*   Updated: 2017/01/16 17:45:49 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

intmax_t	ft_modify_length_di(va_list arg, t_print *new)
{
	intmax_t nb;
	int 	argument;

	nb = 0;
	argument = va_arg(arg, int);
	if(new->flags != NULL)
	{
		if (ft_strcmp(new->flags,"l"))
			nb = (long)argument;
		else if (ft_strcmp(new->flags,"ll"))
			nb = (long long)argument;
		else if (ft_strcmp(new->flags,"h"))
			nb = (short)argument;
		else if (ft_strcmp(new->flags,"hh"))
			nb = (signed char)argument;
		else if (ft_strcmp(new->flags,"j"))
			nb = (intmax_t)argument;
		else if (ft_strcmp(new->flags,"z"))
			nb = (size_t)argument;
	}
	else
		nb = (intmax_t)argument;
	return (nb);
}

uintmax_t	ft_modify_length_uoxX(va_list arg, t_print *new)
{
	uintmax_t nb;
	int 	argument;

	nb = 0;
	argument = va_arg(arg,unsigned int);
	if(new->flags != NULL)
	{
		if (ft_strcmp(new->flags,"l"))
			nb = (unsigned long int)argument;
		else if (ft_strcmp(new->flags,"ll"))
			nb = (unsigned long long int)argument;
		else if (ft_strcmp(new->flags,"h"))
			nb = (unsigned short int)argument;
		else if (ft_strcmp(new->flags,"hh"))
			nb = (unsigned char)argument;
		else if (ft_strcmp(new->flags,"j"))
			nb = (uintmax_t)argument;
		else if (ft_strcmp(new->flags,"z"))
			nb = (size_t)argument;
	}
	else
		nb = (uintmax_t)argument;
	return (nb);
}
