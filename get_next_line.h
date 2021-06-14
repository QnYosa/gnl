#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#define	BUFFER_SIZE 5

int get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);

#endif