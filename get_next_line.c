/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:33:01 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/01/12 15:18:59 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpytill(char *src, int c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(c + 1);
	while (i < c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcuttill(char *src, int c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(ft_strlen(src) - c + 1);
	while (src[c + i] != '\0')
	{
		dst[i] = src[c + i];
		i++;
	}
	dst[i] = '\0';
	free(src);
	return (dst);
}

char	*ft_end_error(char **p2)
{
	free(*p2);
	*p2 = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			nl;
	static char	*nextline;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			c_read;

	if (BUFFER_SIZE == 0 || fd == -1 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_ini(&nextline, 0);
	nl = ft_strfind(nextline, '\n');
	c_read = 1;
	while (nl == 0 && c_read > 0)
	{
		c_read = read(fd, buff, BUFFER_SIZE);
		buff[c_read] = '\0';
		if (c_read <= 0 && nextline[0] == 0)
			return (ft_end_error (&nextline));
		nl = ft_strfind(buff, '\n');
		nextline = ft_strjoinfree1(nextline, buff);
	}
	nl = ft_strfindend(nextline, '\n');
	line = ft_strcpytill(nextline, nl);
	nextline = ft_strcuttill(nextline, nl);
	return (line);
}
