/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 21:49:06 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/28 21:49:07 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	**verif_flag(int *ac, char **av, int *flag)
{
	*flag = 0;
	if (av[1][0] == '-')
	{
		if (ft_isalpha(av[1][1]))
		{
			(*ac)--;
			av = flag_search(flag, av);
		}
		else if (!ft_isdigit(av[1][1]))
		{
			ft_putendl("\033[31mError");
			exit(1);
		}
	}
	else if (!ft_isdigit(av[1][0]))
	{
		ft_putendl("\033[31mError");
		exit(1);
	}
	return (av);
}

char	**flag_search(int *flag, char **av)
{
	if (ft_strcmp(av[1], "-c") == 0)
		*flag = 1;
	else if (ft_strcmp(av[1], "-v") == 0)
		*flag = 2;
	else if (ft_strcmp(av[1], "-cv") == 0 || ft_strcmp(av[1], "-vc") == 0)
		*flag = 3;
	else
	{
		ft_putendl("\033[31mError");
		exit(1);
	}
	av = decaler(av);
	return (av);
}
