/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:01:08 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/09 13:33:29 by vhaefeli         ###   ########.fr       */
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
	cpy = malloc(ft_strlen(str) - i + 1);
	if (i == 0 && str[0] != '\n')
	{
		while (str[i] != '\0')
		{
			cpy[i] = str[i];
			i++;
		}
		cpy[i] = '\0';
		free(str);
	}
	else
	{
		i++;
		while (i < ft_strlen(str))
		{
			cpy[j++] = str[i++];
		}
		cpy[j] = '\0';
	}
	return (cpy);
}

char	*ft_strcut(char *str)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	dst = malloc(i + 1);
	while (j < i)
	{
		dst[j] = str[j];
		j++;
	}
	dst[j] = '\0';
	free(str);
	return (dst);
}

void	ft_finish_line(char **p1, char **p2, int *i)
{
	*p2 = ft_strcpyi(*p1, *i);
	*p1 = ft_strcut(*p1);
	*i = -1;
	return ;
}

char	*ft_end_error(char **buf, char **p2)
{
	free(*buf);
	*buf = NULL;
	free(*p2);
	*p2 = NULL;
	return (NULL);
}
