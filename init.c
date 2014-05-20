/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:13:03 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/27 14:13:05 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_tab	*creation(t_tab *tab, int ac, char **av)
{
	t_tab	*tmp;
	t_tab	*tmp2;
	int		i;

	i = 0;
	while (i < ac)
	{
		tmp = init_tmp(tmp, av, i);
		if (!tab)
			tmp2 = tab = tmp;
		else
		{
			tmp2->next = tmp;
			tmp2->next->prev = tmp2;
			tmp2 = tmp2->next;
		}
		tmp->deb = tab;
		i++;
		if (i < ac)
			tmp = tmp->next;
	}
	tab->prev = tmp;
	tmp->next = tab;
	return (tab);
}

char	*raccourci(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 's' && str[i + 1] != 's' && str[i + 3] == 's' &&
			str[i + 4] != 's')
		{
			i++;
			str[i] = 's';
			str = fn_strchange(str, i, 3);
		}
		str = raccourci_b(str, &i);
		i++;
	}
	return (str);
}

t_tab	*init_tmp(t_tab *tmp, char **av, int i)
{
	tmp = (t_tab*)malloc(sizeof(t_tab));
	tmp->x = ft_atoi(av[i + 1]);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

char	*raccourci_b(char *str, int *i)
{
	if (str[*i] == 'r' && str[*i + 3] == 'r' && str[*i - 1] != 'r')
	{
		if ((str[*i + 1] == 'a' && str[*i + 4] == 'b') ||
			(str[*i + 1] == 'b' && str[*i + 4] == 'a'))
		{
			(*i)++;
			str[*i] = 'r';
			str = fn_strchange(str, *i, 3);
		}
	}
	if (str[*i] == 'r' && str[*i + 1] == 'r' && str[*i + 4] == 'r' &&
		str[*i + 5] == 'r')
	{
		if ((str[*i + 2] == 'a' && str[*i + 6] == 'b') ||
			(str[*i + 2] == 'b' && str[*i + 6] == 'a'))
		{
			*i += 2;
			str[*i] = 'r';
			str = fn_strchange(str, *i, 4);
		}
	}
	return (str);
}
