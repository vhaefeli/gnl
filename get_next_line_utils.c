/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:01:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/03 13:44:11 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] != '\0')
			len++;
	}
	return (len);
}

char	*ft_strcpyi(char *str, int i)
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
