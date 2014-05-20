/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 21:46:37 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/28 21:46:39 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		check_sort(t_tab *tab)
{
	int		x;

	tab = tab->deb;
	x = tab->x;
	tab = tab->next;
	while (tab != tab->deb)
	{
		if (tab->x < x)
			return (0);
		x = tab->x;
		tab = tab->next;
	}
	return (1);
}

int		ft_max(t_tab *tab)
{
	int		max;

	tab = tab->deb;
	max = tab->x;
	tab = tab->next;
	while (tab != tab->deb)
	{
		if (tab->x > max)
			max = tab->x;
		tab = tab->next;
	}
	return (max);
}

int		ft_min(t_tab *tab)
{
	int		min;

	tab = tab->deb;
	min = tab->x;
	tab = tab->next;
	while (tab != tab->deb)
	{
		if (tab->x < min)
			min = tab->x;
		tab = tab->next;
	}
	return (min);
}

void	display_2(int flag, char *str)
{
	if (flag == 1 || !flag)
	{
		if (flag)
			str = ft_strcolor(str);
		ft_putendl(str);
	}
}
