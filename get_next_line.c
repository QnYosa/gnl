/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:04:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/14 20:04:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void no_backslash(char *line)
{	
	while (*line)
	{
		if (*line == '\n')
		{
			*line = '\0';
			break ;
		}
		line++;
	}
}

char	*after_nl(char *line, char *after_newline)
{
	int	i;

	i = 0;
	if (!line)
		return (NULL);
	while (*line != '\n')
		line++;
	line++;
	while (line[i] != '\n' && line[i])
		i++;
	after_newline = malloc(sizeof(char) * (i + 1));
	if (!after_newline)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		after_newline[i] = line[i];
		i++;
	}
	return (after_newline);
}

int get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char 	*after_newline;
	char			*tmp;
	int				ret;
	
	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, "", 0) == - 1)
		return (-1);
	if (after_newline)
		tmp = ft_strdup(after_newline);
	else
		tmp = ft_strdup("");
	while (!(ft_strchr(tmp, '\n') && ret != 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret == 0)
		{
			*line = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
			free(after_newline);
			after_newline = NULL;
			return (0);
		}
		tmp = ft_strjoin(tmp, buffer);
	}
	*line = ft_strdup(tmp);
	after_newline = after_nl(*line, after_newline);
	no_backslash(*line);
	free(tmp);
	tmp = NULL;
	return (1);
}
