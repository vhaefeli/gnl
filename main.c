/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:27:35 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/11/24 17:58:01 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int	fd;

	fd = open("42", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	printf("return %i \n\n\n",printf(" %c %c %c ", '0', 0, '1'));
//	printf("return %i \n\n\n",printf("%-14p\n", &str));
//	printf("return %i \n\n\n",printf("%-3.12s\n", "Papasalut"));
//	printf("return %i \n\n\n",printf("%020d\n", 18));
//	printf("return %i \n\n\n",printf("%-012s\n", "Papasalut"));


	return (0);
}
