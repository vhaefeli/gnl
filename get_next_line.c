/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:01:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/02 22:47:12 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] != '\0')
			len++;
	}
	return (len);
}

char	*ft_strjoini(const char *p23, const char *p1, size_t i)
{
	size_t	j;
	char	*dst;
	size_t	lone;
	size_t	ltwo;

	if (!p23 || !p1)
		return (NULL);
	lone = ft_strlen(p23);
	ltwo = i;
	j = 0;
	dst = malloc(lone + ltwo + 1);
	if (!dst)
		return (NULL);
	while (j < lone)
	{
		dst[j] = p23[j];
		j++;
	}
	while (j < (lone + ltwo))
	{
		dst[j] = p1[j - lone];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strcpyi(char *str, size_t i)
{
	char	*cpy;
	int		j;

	j = 0;
	cpy = malloc(ft_strlen(str) - i);
	i++;
	while (i < ft_strlen(str))
	{
		cpy[j++] = str[i++];
	}
	cpy[j] = '\0';
	return (cpy);
}

char *ft_strcpy(char *src)
{
	char	*dst;
	int i;

	i = 0;
	dst = malloc(ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char*	ft_char_ini(char *str)
{
	if (str == NULL)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	return (str);
}

char	*ft_fill_line(char *p1, char *p2, char *p3, size_t i)
{
	if (ft_strlen(p2) < ft_strlen(p3))
	{	
		p2 = ft_strjoini(p3, p1, i);
		free(p3);
		return (p2);
	}
	else
	{
		p3 = ft_strjoini(p2, p1, i);
		free(p2);
		return (p3);
	}
}

int	ft_searchendline(char *p1)
{
	int i;

	i = 0;
	while (p1[i] != '\n' && p1[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		p1[BUFFER_SIZE + 1];
	char		*p2;
	static char	*p3 = NULL;
	int		i;

	i = 0;
	p3 = ft_char_ini(p3);
	p2 = ft_char_ini(p3);
	read(fd, p1, BUFFER_SIZE);
	if (p1[1] == '\0')
		return (NULL);
	while (i >= 0)
	{
		i = ft_searchendline(p1);
		p2 = ft_fill_line(p1, p2, p3, i);
	 	if (i == BUFFER_SIZE)
			read(fd, p1, BUFFER_SIZE);
		else
		{
			p3 = ft_strcpyi(p1, i);
			i = -1;
		}
	}
	return (p2);
}
