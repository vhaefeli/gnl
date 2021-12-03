/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:04:37 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/03 14:49:38 by vhaefeli         ###   ########.fr       */
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

int		ft_strlen(const char *s);
char	*ft_strcpyi(char *str, int i);
char	*ft_strcpy(char *src);
char	*ft_strjoini(char *p23, char *p1, int i);
char	*ft_char_ini(char *str);
char	*ft_fill_line(char *p1, char *p2, char *p3, int i);
int		ft_searchendline(char *p1);
char	*get_next_line(int fd);

#endif
