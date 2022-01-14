/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:56:50 by nerraou           #+#    #+#             */
/*   Updated: 2021/11/26 14:27:12 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*one_line_rest(char **rest, int index)
{
	char	*str;
	char	*to_free;

	str = ft_strjoin("", *rest);
	if (!str)
		return (NULL);
	to_free = *rest;
	*rest = ft_strdup(*rest + index + 1);
	free(to_free);
	if (!*rest)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*join_and_free(char *str, char *buf)
{
	char	*to_free;
	char	*new_str;

	to_free = str;
	new_str = ft_strjoin(str, buf);
	free(to_free);
	return (new_str);
}

void	str_del(char **str)
{
	free(*str);
	*str = NULL;
}

char	*read_line(int fd, char **rest)
{
	char	*buf;
	char	*str;
	ssize_t	reads;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	*buf = '\0';
	str = ft_strdup(*rest);
	free(*rest);
	*rest = NULL;
	while (str && ft_indexof(buf, '\n') == -1)
	{
		reads = read(fd, buf, BUFFER_SIZE);
		if (reads == 0 || reads == -1)
			break ;
		buf[reads] = '\0';
		str = join_and_free(str, buf);
	}
	if (reads != -1 && ft_indexof(buf, '\n') != -1)
		*rest = ft_strdup(buf + ft_indexof(buf, '\n') + 1);
	free(buf);
	if (reads == -1 || (str && reads == 0 && str[0] == '\0'))
		str_del(&str);
	return (str);
}

char	*get_next_line(int fd)
{
	int				index;
	static char		*rests[FD_MAX];

	if (fd <= -1 || BUFFER_SIZE < 1 || fd >= FD_MAX)
		return (NULL);
	if (!rests[fd])
	{
		rests[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!rests[fd])
			return (NULL);
		*rests[fd] = '\0';
	}
	if (!rests[fd])
		return (NULL);
	index = ft_indexof(rests[fd], '\n');
	if (index != -1)
		return (one_line_rest(&rests[fd], index));
	return (read_line(fd, &rests[fd]));
}
