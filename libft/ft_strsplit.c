/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:07:28 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/24 05:36:52 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*words_size;
char	**tab;
int		i;
int		j;

int		*ft_calculate_words(int *words, const char *str, char c)
{
	i = 0;
	j = 0;
	words_size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			*words += 1;
		i++;
	}
	*words += 1;
	words_size = (int*)malloc(sizeof(*words_size) * *words);
	i = 0;
	while (i < *words)
		words_size[i++] = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\t' && str[i] != '\n')
			words_size[j]++;
		else
			j++;
		i++;
	}
	return (words_size);
}

char	**ft_strsplit(const char *str, char c)
{
	int	words;

	if (*str == 0)
		return (0);
	words = 0;
	words_size = ft_calculate_words(&words, str, c);
	tab = (char**)malloc(sizeof(**tab) * (words + 1));
	i = 0;
	while (i < words)
	{
		j = 0;
		*(tab + i) = (char*)malloc(sizeof(*tab) * 255);
		while (*str != c && *str != '\t' && *str != '\n' && *str != '\0')
		{
			tab[i][j] = *str;
			j++;
			str++;
		}
		tab[i][j] = '\0';
		str++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
