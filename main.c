/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:27:35 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/02 19:50:06 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6
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
		ft_putstr_fd("open() failed\n",1);
		return (1);
	}
	write(1,"fd nb:", 6);
	ft_putnbr_fd(fd,1);
	ft_putstr_fd("\n",1);
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("ligne %i:\n%s\n", i++, str);
	}

	free(str);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n",1);
		return (1);
	}
	return (0);
}
