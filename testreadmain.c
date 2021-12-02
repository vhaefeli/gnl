/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:27:35 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/02 15:41:06 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 20

int	main(void)
{
	int	fd;
	int ret;
	int i = 0;
	char buf[BUF_SIZE + 1];

	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("open() failed\n",1);
		return (1);
	}
	write(1,"fd nb:", 6);
	ft_putnbr_fd(fd,1);
	ft_putstr_fd("\n",1);
	ret = read(fd, buf, BUF_SIZE);
	ft_putstr_fd(buf, 1);
	printf("\nA\n");

	while (i < 3)
	{
		printf("\nB\n");
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_putstr_fd(buf, 1);
		printf("\nret:%i - buf[ret-1]:%c\n", ret, buf[ret-1]);
		i++;
	}
	printf("\nC\n");

	ft_putnbr_fd(ret,1);
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() failed\n",1);
		return (1);
	}
	return (0);
}
