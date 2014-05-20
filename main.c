/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 23:43:06 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/25 23:43:08 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		main(int ac, char **av)
{
	t_tab	*tab;
	char	*str;
	int		flag;

	if (ac == 1)
		return (1);
	ac--;
	tab = NULL;
	av = verif_flag(&ac, av, &flag);
	tab = creation(tab, ac, av);
	gest_error(tab);
	if (check_sort(tab))
	{
		ft_putendl("\033[32mListe déja trier !");
		return (1);
	}
	str = fn_tri(tab, flag);
	str = raccourci(str);
	str = delete_spaces(str);
	display_2(flag, str);
	free(str);
	return (0);
}
