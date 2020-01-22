/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:24:56 by bmenant           #+#    #+#             */
/*   Updated: 2018/11/26 20:14:07 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!(s == NULL || f == NULL))
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(i, (char)(s[i]));
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
