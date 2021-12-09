/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:04:37 by vhaefeli          #+#    #+#             */
/*   Updated: 2021/12/09 11:51:52 by vhaefeli         ###   ########.fr       */
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
char	*ft_strjoini(char *p12, char *buf, int i);
void	ft_ini(char **buf, char **p2, int *i);
char	*ft_fill_line(char *buf, char *p1, char *p2, int i);
int		ft_searchendline(char *str);
char	*ft_strcut(char *str);
char	*ft_end_error(char **buf, char **p2);
void	ft_finish_line(char **p1, char **p2, int *i);
char	*get_next_line(int fd);

#endif
