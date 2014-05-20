/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 01:58:54 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/26 01:58:56 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*fn_tri(t_tab *l_a, int flag)
{
	t_tab	*l_b;
	int		a;
	int		i;
	char	*str;

	i = 0;
	l_b = NULL;
	str = ft_strnew(0);
	while (!check_sort(l_a) || l_b)
	{
		a = 0;
		l_a = fn_list_1(l_a, &a, &str);
		if (!a && !check_sort(l_a))
		{
			l_b = fn_send(&l_a, l_b);
			l_b = fn_list_2(l_b, &str, &i, &a);
		}
		if (!a && l_b)
			l_a = fn_back(l_a, &l_b, &str, &i);
		display(flag, l_a, l_b, str);
	}
	return (str);
}

t_tab	*fn_list_2(t_tab *l_b, char **str, int *i, int *a)
{
	*str = ft_strjoin(*str, "pb ");
	(*i)++;
	l_b = l_b->deb;
	*a = 1;
	if (l_b->next != NULL)
	{
		if (l_b->x < l_b->next->x)
		{
			*str = ft_strjoin(*str, "sb ");
			l_b = fn_swap(l_b);
		}
		else if (l_b->prev->x > l_b->x)
		{
			*str = ft_strjoin(*str, "rrb ");
			l_b = last_rot(l_b);
		}
		else if (l_b->x == ft_min(l_b))
		{
			*str = ft_strjoin(*str, "rb ");
			l_b = first_rot(l_b);
		}
	}
	return (l_b);
}

t_tab	*fn_list_1(t_tab *l_a, int *a, char **str)
{
	l_a = l_a->deb;

	if (l_a->x > l_a->next->x)
	{
		*str = ft_strjoin(*str, "sa ");
		fn_swap(l_a);
		*a = 1;
	}
	else if (l_a->prev->x < l_a->x)
	{
		*str = ft_strjoin(*str, "rra ");
		l_a = last_rot(l_a);
		*a = 1;
	}
	else if (l_a->x == ft_max(l_a))
	{
		*str = ft_strjoin(*str, "ra ");
		l_a = first_rot(l_a);
		*a = 1;
	}
	return (l_a);
}

t_tab	*fn_back(t_tab *l_a, t_tab **l_b, char **str, int *i)
{
	l_a = fn_send(l_b, l_a);
	*str = ft_strjoin(*str, "pa ");
	(*i)--;
	if (!(*i))
		*l_b = NULL;
	return (l_a);
}

void	display(int flag, t_tab *l_a, t_tab *l_b, char *str)
{
	if (flag == 2 || flag == 3)
	{
		affiche(l_a, l_b, str, flag);
		if (!check_sort(l_a) || l_b)
			ft_putchar('\n');
	}
}
