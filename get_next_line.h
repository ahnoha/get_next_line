/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:51:07 by nerraou           #+#    #+#             */
/*   Updated: 2021/11/25 17:34:18 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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
