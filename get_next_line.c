/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:04:28 by dyoula            #+#    #+#             */
/*   Updated: 2021/06/07 20:04:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char *yo;
	char *str;
	static int i;
	int ret;
	
	if (!fd)
		return (-1);
	yo = malloc(sizeof(char) * BUFFER_SIZE);
	read (fd, yo, BUFFER_SIZE);
	i = 0;
	while (yo[i] != '\n' && yo[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	ft_strlcpy(str, yo, i + 1);
	*line = str;
	free(str);
	return (ret);
}
