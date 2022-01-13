/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:33:25 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/01/12 15:22:54 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strfind(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_strfindend(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (ft_strlen(s));
}

void	ft_ini(char **str, int strlenmin)
{
	if (!(*str))
	{
		*str = malloc(strlenmin + 1);
		(*str)[strlenmin] = '\0';
	}
}

char	*ft_strjoinfree1(char *s1, char *s2)
{
	size_t	i;
	char	*dst;
	size_t	lone;
	size_t	ltwo;

	if (!s1 || !s2)
		return (NULL);
	lone = ft_strlen(s1);
	ltwo = ft_strlen(s2);
	i = 0;
	dst = malloc(lone + ltwo + 1);
	if (!dst)
		return (NULL);
	while (i < lone)
	{
		dst[i] = s1[i];
		i++;
	}
	while (i < (lone + ltwo + 1))
	{
		dst[i] = s2[i - lone];
		i++;
	}
	free (s1);
	return (dst);
}
