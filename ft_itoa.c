/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:10:26 by bmenant           #+#    #+#             */
/*   Updated: 2018/11/21 20:34:43 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	i;
	int				neg;
	int				size;
	char			*s;

	neg = 0;
	size = 1;
	if (n < 0)
	{
		i = ((-1) * n);
		neg = 1;
	}
	else
		i = n;
	while (n /= 10)
		size++;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1 + neg))))
		return (NULL);
	s[size + neg] = '\0';
	s[--size + neg] = (i % 10) + 48;
	while (i /= 10)
		s[--size + neg] = (i % 10) + 48;
	if (neg == 1)
		s[0] = '-';
	return (s);
}
