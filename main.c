/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:27:35 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/09 13:17:41 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int i = 1;
	char	*str;

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	while (i < 7)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
		free(str);
	}
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}
