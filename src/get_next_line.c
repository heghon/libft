/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:43:22 by bmenant           #+#    #+#             */
/*   Updated: 2019/03/15 14:18:44 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reading(char **str, char *buff, int fd)
{
	int		ret;

	if (read(fd, buff, 0) < 0)
		return (NULL);
	ret = 1;
	while (ret && (!(ft_strchri(*str, '\n') != -1)))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret)
		{
			buff[ret] = '\0';
			if (!(*str))
				*str = ft_strsub(buff, 0, ret);
			else
				*str = ft_strjoinfree(*str, buff, 1);
			if (!(*str))
				return (NULL);
		}
	}
	free(buff);
	return (*str);
}

static char	*stocking(char **str)
{
	unsigned int	cut;
	size_t			len;
	char			*line;

	cut = ft_strchri(*str, '\n');
	len = ft_strlen(*str);
	if (ft_strchri(*str, '\n') != -1)
	{
		if (!(line = ft_strsub(*str, 0, cut)))
			return (NULL);
		if (!(*str = ft_strsubfree(*str, (cut + 1), (len - (cut + 1)))))
			return (NULL);
	}
	else
	{
		if (!(line = ft_strdup(*str)))
			return (NULL);
		ft_strdel(str);
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	char		*buff;
	static char	*str[7168];

	if (fd < 0 || fd > 7168 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (str[fd] == NULL)
	{
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	}
	if (!(reading(&str[fd], buff, fd)))
		return (-1);
	if (*str[fd])
	{
		if (!(*line = stocking(&str[fd])))
			return (-1);
		return (1);
	}
	return (0);
}
