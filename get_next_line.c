/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:01:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/09 14:01:52 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoini(char *p12, char *buf, int i)
{
	int		j;
	char	*dst;
	int		lone;
	int		ltwo;

	lone = ft_strlen(p12);
	ltwo = i;
	j = 0;
	dst = malloc(lone + ltwo + 1);
	if (!dst)
		return (NULL);
	while (j < lone)
	{
		dst[j] = p12[j];
		j++;
	}
	while (j < (lone + ltwo))
	{
		dst[j] = buf[j - lone];
		j++;
	}
	free(p12);
	dst[j] = '\0';
	return (dst);
}

void	ft_ini(char **buf, char **p2, int *i)
{
	if (*p2 == NULL)
	{
		*p2 = malloc(1);
		(*p2)[0] = '\0';
	}
	*buf = malloc(BUFFER_SIZE + 1);
	(*buf)[BUFFER_SIZE] = '\0';
	*i = 0;
	return ;
}

char	*ft_fill_line(char *buf, char *p1, char *p2, int i)
{
	if (p2[0] == '\0')
	{
		p1 = ft_strjoini(p1, buf, i);
	}
	else
	{
		p1 = ft_strjoini(p2, buf, i);
		p2[0] = '\0';
	}
	return (p1);
}

int	ft_searchendline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*p1;
	static char	*p2 = NULL;
	int			i;
	int			c;

	ft_ini(&buf, &p2, &i);
	c = read(fd, buf, BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || fd < 0 || (c <= 0 && p2[0] == 0))
		return (ft_end_error(&buf, &p2));
	while (i >= 0)
	{
		p1 = ft_strjoini(p2, buf, c);
		i = ft_searchendline(p1);
		if (i == ft_strlen(p1) && i >= c && c != 0)
		{
			p2 = ft_strcpyi(p1, 0);
			c = read(fd, buf, BUFFER_SIZE);
		}
		else
			ft_finish_line(&p1, &p2, &i);
	}
	free(buf);
	return (p1);
}
