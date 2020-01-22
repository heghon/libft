/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:23:18 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/08 11:34:24 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrstr(const char *str, const char *str2)
{
	int	i;
	int	j;

	i = -1;
	while (str2[++i])
	{
		j = -1;
		while (str[++j])
			if (str[j] == str2[i])
				return ((int)str[j]);
	}
	return (0);
}
