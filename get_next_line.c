/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:04:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/10 18:54:01 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*str;
	int			ret;
	
	if (fd < 0)
		return (-1);
	//printf("%s \n\nstop \n", *line);
	buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	ret = read (fd, buffer, BUFFER_SIZE);
	//printf("%s", buffer);
	str = ft_strdup("");
	str = buffer;
	printf ("%s", str);
	line = &str;
	return (1);
}

/*
buff = malloc(sizeof(char) * BUFFER_SIZE);
	read (fd, buff, BUFFER_SIZE);


	*/