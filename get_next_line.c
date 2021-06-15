/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:04:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/15 17:04:25 by sbeaujar         ###   ########.fr       */
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

char	*after_nl(char *line)
{
	int	i;
	char *temp;
	
	i = 0;
	if (!line)
		return (NULL);
	while (*line != '\n')
		line++;
	line++;
	while (line[i] != '\n' && line[i])
		i++;
/*	if (after_newline)
	{
		free(after_newline);
		after_newline = 0;
	}*/
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
	{
	//	free(after_newline);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = '\0';
	//free (after_newline);
	return (temp);
}

int get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char 	*after_newline;
	// char			*tmp;
	int				ret;
	
	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, "", 0) == - 1)
		return (-1);
	if (!after_newline)
		after_newline = ft_strdup("");
	// if (after_newline)
	// 	tmp = ft_strdup(after_newline);
	// else
	// 	tmp = ft_strdup("");
	while (!(ft_strchr(after_newline, '\n') && ret != 0))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
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
	*line = ft_strdup(after_newline);
	//after_newline + position +  du '\n' = ft_strdup
	//strndup after_newline, position
	free(after_newline);
	after_newline = after_nl(*line);
	no_backslash(*line);
	return (1);
}
