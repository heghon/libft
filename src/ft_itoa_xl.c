/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_xl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:12:20 by bmenant           #+#    #+#             */
/*   Updated: 2019/04/11 13:47:43 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_xl(unsigned long long int n)
{
	unsigned long long int	i;
	int						size;
	char					*s;

	size = 1;
	i = n;
	while (n /= 10)
		size++;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size] = '\0';
	s[--size] = (i % 10) + 48;
	while (i /= 10)
		s[--size] = (i % 10) + 48;
	return (s);
}
