/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:55:59 by nerraou           #+#    #+#             */
/*   Updated: 2021/11/26 14:37:13 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef FD_MAX
#  define FD_MAX 10240
# endif

int		ft_indexof(const char *str, int c);

char	*join_and_free(char *str, char *buf);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*one_line_rest(char **rest, int index);
char	*read_line(int fd, char **rest);
char	*get_next_line(int fd);

void	str_del(char **str);

size_t	ft_strclen(const char *s, int param);

#endif
