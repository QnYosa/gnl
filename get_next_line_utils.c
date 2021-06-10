#include "get_next_line.h"

int		obtain_diviseur_de_nb(int nb, int i)
{
	while (nb / i > 9)
		i = i * 10;
	return (i);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	chiffre;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	chiffre = '0';
	i = 1;
	i = obtain_diviseur_de_nb(nb, i);
	while (i >= 1 && nb != -2147483648)
	{
		chiffre = nb / i + '0';
		write(1, &chiffre, 1);
		nb = nb % i;
		i = i / 10;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i] && fd >= 0)
		ft_putchar_fd(s[i], fd);
}


size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	while (str[i])
		i++;
	n_str = malloc(sizeof(char) * (i + 1));
	if (!n_str)
		return (NULL);
	i = -1;
	while (str[++i])
		n_str[i] = str[i];
	n_str[i] = 0;
	return (n_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	return (str);
}
