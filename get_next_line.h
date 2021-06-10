#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define	BUFFER_SIZE 12

int get_next_line(int fd, char **line);
void	ft_putnbr(int nb);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(char *str);

#endif