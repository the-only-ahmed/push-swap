/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:05:09 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/27 16:50:42 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*delete_spaces(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

char	*fn_strchange(char *str, int i, int n)
{
	int		x;
	int		j;

	x = 0;
	while (x < n)
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			str[j] = str[j + 1];
			j++;
		}
		x++;
	}
	return (str);
}

char	**decaler(char **av)
{
	int		i;

	i = 1;
	while (av[i + 1])
	{
		av[i] = ft_strdup(av[i + 1]);
		i++;
	}
	av[i] = NULL;
	return (av);
}
