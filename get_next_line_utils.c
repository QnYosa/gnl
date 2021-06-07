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

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
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
