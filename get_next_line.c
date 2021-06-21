/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:04:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/21 19:14:41 by dyoula           ###   ########.fr       */
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

char	*last(/*char **tmp,*/ char **after_newline, char **line)
{
	int	i;
	char	*tmp;

	i = 0;
	// *tmp = *after_newline;
	while (*after_newline && (*after_newline)[i] != '\n')
		i++;
	*line = ft_strndup(*after_newline, i);
	// *tmp = ft_strdup(*tmp);
	tmp = ft_strdup(*after_newline + i);
	free(*after_newline);
	return (tmp);
	// return (after_newline);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	// char			*tmp;
	static char		*after_newline = NULL;
	int				ret;

	ret = 1;
	if (safety(fd, &after_newline, line) == 0)
		return (-1);
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
	// tmp = NULL;
	after_newline = last(/*&tmp, */&after_newline, line);
	return (1);
}