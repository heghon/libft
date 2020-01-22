/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:53:25 by bmenant           #+#    #+#             */
/*   Updated: 2018/11/26 21:17:15 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	release_the_tab(char **tab, int k)
{
	while (k != 0)
	{
		free(tab[k]);
		k--;
	}
	free(tab[k]);
	free(tab);
}

static int	count_words(char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i++] != '\0')
			j = 1;
		if (j-- == 1)
			k++;
	}
	return (k);
}

static char	**make_tab(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (tab);
		j = 0;
		while (s[i] != c && s[i++] != '\0')
			j++;
		if (!(tab[k++] = (char *)malloc(sizeof(char) * (j + 1))))
		{
			release_the_tab(tab, k);
			return (NULL);
		}
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	if (!(tab = make_tab(s, c)))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		while (s[i] != c && s[i] != '\0')
			tab[k][j++] = s[i++];
		if (j > 0)
			tab[k++][j] = '\0';
	}
	tab[k] = NULL;
	return (tab);
}
