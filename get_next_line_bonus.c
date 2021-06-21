/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:08:26 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/21 17:57:36 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	safety(int fd, char **after_newline, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
		return (0);
	if (!after_newline[fd])
		after_newline[fd] = ft_strdup("");
	return (1);
}

char	**last(char *tmp, char **after_newline, int fd, char **line)
{
	int	i;

	i = 0;
	tmp = after_newline[fd];
	while (tmp && *tmp++ != '\n')
		i++;
	*line = ft_strndup(after_newline[fd], i);
	tmp = ft_strdup(tmp);
	free(after_newline[fd]);
	after_newline[fd] = tmp;
	return (&*after_newline);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	char			*tmp;
	static char		*after_newline[1024];
	int				ret;

	ret = 1;
	if (!safety(fd, after_newline, line))
		return (-1);
	while (!(ft_strchr(after_newline[fd], '\n') && ret != 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret == 0)
		{
			*line = ft_strdup(after_newline[fd]);
			free(after_newline[fd]);
			after_newline[fd] = NULL;
			return (0);
		}
		after_newline[fd] = ft_strjoin(after_newline[fd], buffer);
	}
	tmp = NULL;
	last(tmp, after_newline, fd, line);
	return (1);
}
