/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:25:22 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/23 14:17:26 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	safety(int fd, char **after_newline, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, "", 0) == -1)
		return (0);
	if (*after_newline == NULL)
		*after_newline = ft_strdup("");
	return (1);
}

char	*get_last(char *after_line, char **line)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (*after_line && after_line[i] != '\n')
		i++;
	if (after_line[i] != '\0')
	{
		*line = ft_strndup(after_line, i);
		tmp = ft_strdup(after_line + i + 1);
		free(after_line);
		return (tmp);
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*after_newline;
	int				ret;

	ret = 1;
	if (safety(fd, &after_newline, line) == 0)
		return (-1);
	while (!(ft_strchr(after_newline, '\n') && ret != 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		if (ret == 0)
		{
			*line = ft_strdup(after_newline);
			free(after_newline);
			after_newline = NULL;
			return (0);
		}
		after_newline = ft_strjoin(after_newline, buffer);
	}
	after_newline = get_last(after_newline, line);
	return (1);
}
