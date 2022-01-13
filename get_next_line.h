/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:32:58 by vhaefeli          #+#    #+#             */
/*   Updated: 2022/01/12 15:22:58 by vhaefeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoinfree1(char *s1, char *s2);
void	ft_ini(char **buf, int strlenmin);
int		ft_strfind(const char *str, int c);
int		ft_strfindend(const char *str, int c);
char	*ft_end_error(char **p2);
char	*ft_strcpytill(char *src, int c);
char	*ft_strcuttill(char *str, int c);
char	*get_next_line(int fd);

#endif
